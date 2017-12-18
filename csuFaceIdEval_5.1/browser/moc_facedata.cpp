/****************************************************************************
** FaceData meta object code from reading C++ file 'facedata.h'
**
** Created: Wed Jun 25 17:39:09 2003
**      by: The Qt MOC ($Id: moc_facedata.cpp 208 2003-06-27 22:28:53Z charu $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "facedata.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *FaceData::className() const
{
    return "FaceData";
}

QMetaObject *FaceData::metaObj = 0;
static QMetaObjectCleanUp cleanUp_FaceData( "FaceData", &FaceData::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString FaceData::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FaceData", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString FaceData::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FaceData", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* FaceData::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"LoadData", 0, 0 };
    static const QUMethod slot_1 = {"SaveData", 0, 0 };
    static const QUMethod slot_2 = {"ClearData", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "LoadData()", &slot_0, QMetaData::Public },
	{ "SaveData()", &slot_1, QMetaData::Public },
	{ "ClearData()", &slot_2, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"saveForm", 0, 0 };
    static const QUMethod signal_1 = {"loadForm", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "saveForm()", &signal_0, QMetaData::Public },
	{ "loadForm()", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"FaceData", parentObject,
	slot_tbl, 3,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_FaceData.setMetaObject( metaObj );
    return metaObj;
}

void* FaceData::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "FaceData" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL saveForm
void FaceData::saveForm()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL loadForm
void FaceData::loadForm()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool FaceData::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: LoadData(); break;
    case 1: SaveData(); break;
    case 2: ClearData(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool FaceData::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: saveForm(); break;
    case 1: loadForm(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool FaceData::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool FaceData::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
