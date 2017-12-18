/*===========================================================================
  Short demonstration program to show how to begin structuring the first
  programming lab assignment for CS410, Spring 2001.   

 Last update,  January 30, 2001   Ross Beveridge
 ===========================================================================*/

/* ------------------------ INCLUDE FILES --------------------------------- */

#include "mainview.h"
#include <qapplication.h>
#include <iostream.h>
#include <fstream.h>
#include <qdir.h>
#include <qfiledialog.h>
/* ---------------------------- MAIN -------------------------------------- */

// DSB
/* This file is created to as a quick way to store eyecoordinates for the
*  image files */
ofstream eyecoords("EyeCoords.txt");

/* These two variables are used to store directory names.
 * They use to be only temporary variables in the constructure
 * of the file list view. When qt switched to multithreading
 * This caused sycronization problems that lead to a
 * secmentation fault.  As a result these two directories
 * are determined before the application is run (app.exec()) and
 * their values are passed through the use of global variables.
 */
QDir sourceDir;
QDir normDir;
QDir loadDir;
int loadfile = 0;


int main( int argc, char **argv )
{
  // Create the application and the interface object. The interface
  // object handles all of the work and is a subclass of QWidget. 
  QApplication app(argc, argv);

  sourceDir.setPath(argv[1]);/*QFileDialog::getExistingDirectory()*/
  normDir.setPath(argv[2]);/*QFileDialog::getExistingDirectory();*/
  loadDir.setPath(argv[3]);

    QString covariatefile = argv[3];
  if(!covariatefile.isNull())
  loadfile=1;
  else loadfile=0;
  

  
  //QMainWindow* mainwin = new QMainWindow(0,"Face Browser");
  MainView* mainview= new MainView(0,"FaceBrowser");
  
  //mainwin->setCentralWidget(mainwindow);
  app.setMainWidget( mainview );
  mainview->resize(1000,700);
  mainview->show();

  return app.exec();
}





























































