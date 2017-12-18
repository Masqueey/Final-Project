#include "mainview.h"
#include <qapplication.h>
#include "filelistview.h"
#include "imageview.h"
#include "formview.h"
#include <qpushbutton.h>
#include <qbutton.h>
#include "facedata.h"

#include <iostream.h>


inline int max(int x, int y){ return x > y ? x : y;} 
extern int loadfile;
MainView::MainView(QWidget* parent, const char* name)
  :QWidget(parent, name){
  sourceview = new ImageView(this,"Source Image");
  //sourceview->LoadImage("00749fa010_941201.pgm");
  normview = new ImageView(this,"Nomalized Image");
  //normview->LoadFR("00749fa010_941201.nrm",130,150);
  filelistview = new FileListView(this,sourceview,normview);
  formview = new FormView(this);
  filelistview->form = formview;

  loadbutton = new QPushButton("Load Data",this);
    //  QObject::connect(loadbutton,SIGNAL(clicked(void)), &facedata, SLOT(LoadData(void)));
  QObject::connect(loadbutton,SIGNAL(clicked(void)), this, SLOT(freeForLoad(void)));
  QObject::connect(this,SIGNAL(loadData(void)), &facedata, SLOT(LoadData(void)));
  QObject::connect(&facedata,SIGNAL(loadForm(void)), filelistview, SLOT(loadForm(void)));
  savebutton = new QPushButton("Save Data",this);
    QObject::connect(savebutton,SIGNAL(clicked(void)), this, SLOT(freeForSave(void)));
  QObject::connect(this,SIGNAL(saveData(void)), &facedata, SLOT(SaveData(void)));
  QObject::connect(&facedata,SIGNAL(saveForm(void)), filelistview, SLOT(saveForm(void)));
  clearbutton = new QPushButton("Clear Data", this);
  
  QObject::connect(clearbutton,SIGNAL(clicked(void)), &facedata, SLOT(ClearData(void)));

  QObject::connect(this,SIGNAL(changeData(QString, QString)), filelistview, SLOT(changeData(QString, QString)));
  QObject::connect(this,SIGNAL(nextFace()), filelistview, SLOT(nextItem()));
  QObject::connect(this,SIGNAL(prevFace()), filelistview, SLOT(prevItem()));

  keyboardbutton = new QPushButton("KeyBoard Grab", this);
    
  keyboardbutton->setToggleButton(TRUE);
  keyboardbutton->setOn(TRUE);
  //QObject::connect(keyboardbutton,SIGNAL(clicked()),this, SLOT(keyboardAccess()));
  QObject::connect(keyboardbutton,SIGNAL(toggled(bool)),this, SLOT(keyboardAccess(bool)));
  if(keyboardbutton->isToggleButton())
   cout<<"toggle\n";
  else 
   cout<<"not toggle\n";
    
  exitbutton = new QPushButton("Quit",this); 
  QObject::connect(exitbutton, SIGNAL(clicked(void)),qApp,SLOT(quit(void))) ;           

  //grabKeyboard();
  resize(width(),height());
  
  if(loadfile==1)
  emit loadData();

}



void MainView::keyboardAccess(bool onoff)
{
	cout<<"in key grab";
	if(!onoff)
	grabKeyboard();
	else
	releaseKeyboard();
		
	
}
void MainView::resizeEvent(QResizeEvent*){
    /*  This bit of code causes a lot of problems now that qt
    *   has switched to multithreading. This function seems to
    *   called before all of the children have been created.
    *   Often this results in a segmentation fault core dump.
    *
    *   I believe this problem is caused by the file list view
    *   because it needs to get a directory when it is created.
    *   the new qt does not handle this well.  Probably because
    *   the multithreading allows the program to get out of sync.
    */
    if(this && sourceview && normview && filelistview && formview){
        sourceview->move(0,0);
        normview->move(sourceview->width(),0);
        filelistview->move(0,sourceview->height());
        filelistview->resize(sourceview->width() + normview->width(),height()-sourceview->height());
        formview->move(sourceview->width()+normview->width(),0);
        formview->resize(width()-(sourceview->width()+normview->width()),height() - 30);
        loadbutton->move(sourceview->width()+normview->width(),height()-30);
        loadbutton->resize((width() - (sourceview->width()+normview->width()))/5,30);
        savebutton->move(loadbutton->width()+sourceview->width()+normview->width(),height()-30);
        savebutton->resize((width() - (sourceview->width()+normview->width()))/5,30);
        clearbutton->move(2*loadbutton->width()+sourceview->width()+normview->width(),height()-30);
        clearbutton->resize((width() - (sourceview->width()+normview->width()))/5,30);
	keyboardbutton->move(3*loadbutton->width()+sourceview->width()+normview->width(),height()-30);
        keyboardbutton->resize((width() - (sourceview->width()+normview->width()))/5,30);
	exitbutton->move(4*loadbutton->width()+sourceview->width()+normview->width(),height()-30);
        exitbutton->resize((width() - (sourceview->width()+normview->width()))/5,30);

    }
}
  
void MainView::keyPressEvent ( QKeyEvent * event){
  //  cout << event->key() << endl;
  int k = event->key();
  cout << "key: " << k << endl;
  switch(k){
  case 4117:	/* down arrow key */
  case 4100:    /* Enter key   */
    emit nextFace();
    break;
  case 4115: 	/* up arrow key */
  case 4099:	/* backspace  */
    emit prevFace();
    break;

  case 49: 
    //    cout << "Q" << endl;
    emit changeData("GENDER","MALE");
    break;
  case 50: 
    emit changeData("GENDER","FEMALE");
    break;
  case 81: 
    emit changeData("RACE","WHITE");
    break;
  case 87: 
    emit changeData("RACE","BLACK");
    break;
  case 69: 
    emit changeData("RACE","ASIAN");
    break;
  case 82: 
    emit changeData("RACE","OTHER");
    break;
  case 65: 
    emit changeData("AGE","TEEN");
    break;
  case 83: 
    emit changeData("AGE","20");
    break;
  case 68: 
    emit changeData("AGE","30");
    break;
  case 70: 
    emit changeData("AGE","40");
    break;
  case 71: 
    emit changeData("AGE","50");
    break;
  case 72: 
    emit changeData("AGE","60+");
    break;
  case 90: 
    emit changeData("SKIN","CLEAR");
    break;
  case 88: 
    emit changeData("SKIN","FRECKELED");
    break;
  case 67: 
    emit changeData("SKIN","WRINKLED");
    break;
  case 86: 
    emit changeData("SKIN","BOTH");
    break;
  case 66: 
    emit changeData("SKIN","OTHER");
    break;
  case 54: 
    emit changeData("GLASSES","YES");
    break;
  case 55: 
    emit changeData("GLASSES","NO");
    break;
  case 56: 
    emit changeData("FACIAL_HAIR","YES");
    break;
  case 57: 
    emit changeData("FACIAL_HAIR","NO");
    break;
  case 85: 
    emit changeData("EXPRESSION","NEUTRAL");
    break;
  case 73: 
    emit changeData("EXPRESSION","OTHER");
    break;
  case 75: 
    emit changeData("MOUTH","CLOSED");
    break;
  case 76: 
    emit changeData("MOUTH","OPEN");
    break;
  case 59: 
    emit changeData("MOUTH","TEETH");
    break;
  case 39: 
    emit changeData("MOUTH","OTHER");
    break;
  case 44: 
    emit changeData("EYES","CLOSED");
    break;
  case 46: 
    emit changeData("EYES","OPEN");
    break;
  case 47: 
    emit changeData("EYES","OTHER");
    break;
  case 79: 
    emit changeData("BANGS","YES");
    break;
  case 80: 
    emit changeData("BANGS","NO");
    break;
  case 48: 
    emit changeData("MAKEUP","YES");
    break;
  case 45: 
    emit changeData("MAKEUP","NO");
    break;
  };
}

void MainView::freeForSave(){
  
  emit saveData();
  grabKeyboard();
  releaseKeyboard();

}

void MainView::freeForLoad(){
   emit loadData();
   grabKeyboard();
   releaseKeyboard();

}
