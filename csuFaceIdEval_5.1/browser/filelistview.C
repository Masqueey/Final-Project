#include "filelistview.h"

#include "imageview.h"


#include "qfiledialog.h"

#include "formview.h"

#include "facedata.h"

#include <qdir.h>

#include <iostream.h>

#define IMAGE_COL 0
#define PERSON_COL 1
#define SOURCE_COL 2
#define NORM_COL 3
#define DATA_COL 8


int min(int x, int y){ if(x < y) return x; else return y; }

QString getBaseName(QString filename){
  QString basename(filename);
  //cout<<"basename ="<<basename<<"\n";
  for(int i = 0; i < basename.length(); i++){
    if(basename[i] == '.'){
     
      basename.truncate(i);
      //      cout << basename << endl;
      return basename;
    }
  }
  return basename;
}

extern QDir sourceDir;
extern QDir normDir;


/*creates the list header that is displayed below the image*/

FileListView::FileListView(QWidget* parent,ImageView* sview,ImageView* nview):
  QListView(parent,"Files"),
  sourceview(sview),
  normview(nview),
  currentimage(0)
{  
  addColumn("Base Name");
  addColumn("Person");
  addColumn("Source");
  addColumn("Norm");
  addColumn("#");
  addColumn("Type");
  addColumn("Camera");
  addColumn("Date");
  addColumn("Data");
  

  //QDir sourceDir(QFileDialog::getExistingDirectory());
  sourcepath = sourceDir.path();
  cout<<"source= "<<sourceDir.path();
  //QDir normDir(QFileDialog::getExistingDirectory());
  normpath = normDir.path();
  int count = min(sourceDir.count(),normDir.count());/* count gives the total nos of dirs and files present in the directory*/
  for(int i = 0; i < sourceDir.count(); i++){
   // cout<<"i ="<<i<<" sourceDir ="<<sourceDir[i]<<"\n";	  
    if(sourceDir[i].length() && sourceDir[i][0] != '.'){ 
      QString base = getBaseName(sourceDir[i]);
      
      files[base].sourceName = sourceDir[i];
      files[base].person = base;
      files[base].person.truncate(5);
      files[base].basename = base;
      files[base].type = base;
      files[base].type.remove(0,5).remove(2,100);
      files[base].type = base;
      files[base].type.remove(0,5).remove(2,100);
      files[base].camera = base;
      files[base].camera.remove(0,7).remove(3,100);
      int datestart = 10;
      for(; datestart < base.length(); datestart++){
	if(base[datestart] == '_') break;
      }
      datestart++;
      files[base].date = base;
      files[base].date.remove(0,datestart).remove(6,100);
    }
  }

  for(int i = 0; i < normDir.count(); i++){
    if(normDir[i].length() && normDir[i][0] != '.'){
      QString base(getBaseName(normDir[i]));
      files[base].normName = normDir[i];
      files[base].person = base;
      files[base].person.truncate(5);
      files[base].basename = base;
      files[base].type = base;
      files[base].type.remove(0,5).remove(2,100);
      files[base].type = base;
      files[base].type.remove(0,5).remove(2,100);
      files[base].camera = base;
      files[base].camera.remove(0,7).remove(3,100);
      int datestart = 10;
      for(; datestart < base.length(); datestart++){
	if(base[datestart] == '_') break;
      }
      datestart++;
      files[base].date = base;
      files[base].date.remove(0,datestart).remove(6,100);
    }
  }
  /**********************************************************
   * code form here till end of function is used to display *
   * the values in the columns below the images             *
   **********************************************************/ 
  int personinstance = 0;
  QString lastperson = "";
  std::map<QString,FileInfo>::iterator each = files.begin();
  for( ; each != files.end() ; each++){
    QString name = getBaseName(each->second.sourceName);
    //cout<<"name ="<<name<<"\n";
    if(name == "-"){
      name = getBaseName(each->second.normName);
    }
    QString person = name;
    person.truncate(5);
    //cout<<"person = "<<person<<"\n";
    if(person == lastperson) personinstance++;//cout<<"person increased";}
    else personinstance = 0;
    lastperson = person;
    QListViewItem* tempitem = new QListViewItem(
		      this,
		      each->second.basename,
		      each->second.person,
		      each->second.sourceName,
		      each->second.normName,
		      QString(personinstance < 10 ? "0" : "") + QString().setNum(personinstance),
		      each->second.type,
		      each->second.camera,
		      each->second.date);
    tempitem->setText(8,"NO");
  }

  QObject::connect(this,SIGNAL(selectionChanged ( QListViewItem * )),this,SLOT(switchImages( QListViewItem *)));

}
/*****************************************************************************
 * when the next image is selected before it is loaded the previous image's  *
 * details are recorded. Recording is done in two different ways -- Subject  *
 * Specific and Image Specific. for this purpose methods form the formview.C * 
 * file are called. After this is done the new image is loaded.              *
 *****************************************************************************/  
void FileListView::switchImages( QListViewItem* selection){
  //cout<<"currentimage ="<<currentimage<<"\n";	
  //cout<<"selection = "<<selection<<"\n";
  if(currentimage){
   // cout<<"value1 = "<<&facedata.persondata[currentimage->text(PERSON_COL)]<<"value2 = "<<&facedata.imagedata[currentimage->text(IMAGE_COL)]<<"\n";	  
    form->storedata(&facedata.persondata[currentimage->text(PERSON_COL)],&facedata.imagedata[currentimage->text(IMAGE_COL)]);
//cout<<"means = "<<facedata.imagedata[currentimage->text(IMAGE_COL)].person <<"\n";

    facedata.imagedata[currentimage->text(IMAGE_COL)].person = currentimage->text(PERSON_COL); // save the person field
       //cout<<"means1 = "<<currentimage->text(PERSON_COL)<<"\n";  

    
    currentimage->setText(DATA_COL,"YES");
  }
  currentimage = selection;
//cout<<"count ="<<facedata.persondata.count(currentimage->text(PERSON_COL))<<"\n";
  form->loaddata(
  
		 facedata.persondata.count(currentimage->text(PERSON_COL)) ? &facedata.persondata[currentimage->text(PERSON_COL)] : NULL ,
		 facedata.imagedata.count( currentimage->text(IMAGE_COL)) ? &facedata.imagedata[currentimage->text(IMAGE_COL)]  : NULL );


  QString sourcefile = sourcepath + "/" + selection->text(SOURCE_COL);
  //cout<<"sourcefile ="<<sourcefile<<"\n";
  if(selection->text(SOURCE_COL) != "-")
    sourceview->LoadImage(sourcefile);
  else
    sourceview->clearImage();
  QString normfile = normpath + "/" + selection->text(NORM_COL);
  if(selection->text(NORM_COL) != "-")
    normview->LoadFR(normfile,130,150);
  else
    normview->clearImage();

}
void FileListView::saveForm(){

  if(currentimage){
    form->storedata(&facedata.persondata[currentimage->text(PERSON_COL)],&facedata.	imagedata[currentimage->text(IMAGE_COL)]);
    facedata.imagedata[currentimage->text(IMAGE_COL)].person = currentimage->text(PERSON_COL);
           // save the person field
  }

}

void FileListView::loadForm(){
   
    //cout<<"in loadForm present in filelistview\n";	
    QListViewItem* temp = firstChild();
    int i = 0;
    while(temp){
        i++;
        if( facedata.imagedata.count( temp->text(IMAGE_COL)) ){
	    //cout<<"temp->text(IMAGE_COL) ="<<temp->text(IMAGE_COL)<<"\n"; 	
            temp->setText(DATA_COL,"YES");
        } else {
            temp->setText(DATA_COL,"NO");
        }
            
        temp = temp->nextSibling();	
    }
    cout << "Updated " << i << endl;

  if(currentimage){
  form->loaddata(
		 facedata.persondata.count(currentimage->text(NORM_COL)) ? &facedata.persondata[currentimage->text(NORM_COL)] : NULL ,
		 facedata.imagedata.count( currentimage->text(SOURCE_COL)) ? &facedata.imagedata[currentimage->text(SOURCE_COL)]  : NULL );
  }
	
  cout<<"end";
  
}

void FileListView::changeData(QString field, QString value){
  saveForm();
  if(currentimage){
    if(field == "GENDER" || field == "RACE" || field == "AGE" || field == "SKIN" ){
      facedata.persondata[currentimage->text(PERSON_COL)].covariates[field] = value;
    } else {
      facedata.imagedata[currentimage->text(IMAGE_COL)].covariates[field] = value;
    }
   
    form->loaddata(
		   facedata.persondata.count(currentimage->text(PERSON_COL)) ? &facedata.persondata[currentimage->text(PERSON_COL)] : NULL ,
		   facedata.imagedata.count( currentimage->text(IMAGE_COL)) ? &facedata.imagedata[currentimage->text(IMAGE_COL)]  : NULL );
  }
}

void FileListView::nextItem(){
  setCurrentItem(currentItem()->itemBelow());
}

void FileListView::prevItem(){
  setCurrentItem(currentItem()->itemAbove());

}
