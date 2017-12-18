/****************************************************************************
** MainView meta object code from reading C++ file 'mainview.h'
**
** Created: Wed Jun 25 17:39:30 2003
**      by: The Qt MOC ($Id: moc_mainview.cpp 208 2003-06-27 22:28:53Z charu $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "mainview.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *MainView::className() const
{
    return "MainView";
}

QMetaObject *MainView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MainView( "MainView", &MainView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString MainView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MainView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MainView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MainView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MainView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"freeForSave", 0, 0 };
    static const QUMethod slot_1 = {"freeForLoad", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "onoff", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"keyboardAccess", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "freeForSave()", &slot_0, QMetaData::Public },
	{ "freeForLoad()", &slot_1, QMetaData::Public },
	{ "keyboardAccess(bool)", &slot_2, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"nextFace", 0, 0 };
    static const QUMethod signal_1 = {"prevFace", 0, 0 };
    static const QUMethod signal_2 = {"loadData", 0, 0 };
    static const QUMethod signal_3 = {"saveData", 0, 0 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"changeData", 2, param_signal_4 };
    static const QMetaData signal_tbl[] = {
	{ "nextFace()", &signal_0, QMetaData::Public },
	{ "prevFace()", &signal_1, QMetaData::Public },
	{ "loadData()", &signal_2, QMetaData::Public },
	{ "saveData()", &signal_3, QMetaData::Public },
	{ "changeData(QString,QString)", &signal_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"MainView", parentObject,
	slot_tbl, 3,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MainView.setMetaObject( metaObj );
    return metaObj;
}

void* MainView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MainView" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL nextFace
void MainView::nextFace()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL prevFace
void MainView::prevFace()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL loadData
void MainView::loadData()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL saveData
void MainView::saveData()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL changeData
void MainView::changeData( QString t0, QString t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
}

bool MainView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: freeForSave(); break;
    case 1: freeForLoad(); break;
    case 2: keyboardAccess((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool MainView::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: nextFace(); break;
    case 1: prevFace(); break;
    case 2: loadData(); break;
    case 3: saveData(); break;
    case 4: changeData((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool MainView::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool MainView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
