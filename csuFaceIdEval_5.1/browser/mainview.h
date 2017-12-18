#ifndef IMAGEPAIN_INCLUDED
#define IMAGEPAIN_INCLUDED
 
#include <qwidget.h>
#include <qpushbutton.h>

class FileListView;
class ImageView;
class FormView;
class QButton;


class MainView: public QWidget{
Q_OBJECT

public:
MainView(QWidget* parent, const char* name);
QPushButton* keyboardbutton;

public slots:
	
  void freeForSave();
  void freeForLoad();
  void keyboardAccess(bool onoff);
signals:
 void nextFace();
  void prevFace();
  void loadData();
  void saveData();
  void changeData(QString, QString);
  
protected:
  void resizeEvent(QResizeEvent*);
  virtual void keyPressEvent ( QKeyEvent * );
 

 private:

  FileListView* filelistview;
  ImageView* sourceview;
  ImageView* normview;
  FormView* formview;
  QButton* loadbutton;
  QButton* savebutton;
  QButton* clearbutton;
  QButton* exitbutton; 
  
  };


#endif
