/****************************************************************************
** FileListView meta object code from reading C++ file 'filelistview.h'
**
** Created: Wed Jun 25 17:39:14 2003
**      by: The Qt MOC ($Id: moc_filelistview.cpp 208 2003-06-27 22:28:53Z charu $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "filelistview.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *FileListView::className() const
{
    return "FileListView";
}

QMetaObject *FileListView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_FileListView( "FileListView", &FileListView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString FileListView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FileListView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString FileListView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FileListView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* FileListView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QListView::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_0 = {"switchImages", 1, param_slot_0 };
    static const QUMethod slot_1 = {"saveForm", 0, 0 };
    static const QUMethod slot_2 = {"loadForm", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "field", &static_QUType_QString, 0, QUParameter::In },
	{ "value", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"changeData", 2, param_slot_3 };
    static const QUMethod slot_4 = {"nextItem", 0, 0 };
    static const QUMethod slot_5 = {"prevItem", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "switchImages(QListViewItem*)", &slot_0, QMetaData::Public },
	{ "saveForm()", &slot_1, QMetaData::Public },
	{ "loadForm()", &slot_2, QMetaData::Public },
	{ "changeData(QString,QString)", &slot_3, QMetaData::Public },
	{ "nextItem()", &slot_4, QMetaData::Public },
	{ "prevItem()", &slot_5, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"FileListView", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_FileListView.setMetaObject( metaObj );
    return metaObj;
}

void* FileListView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "FileListView" ) )
	return this;
    return QListView::qt_cast( clname );
}

bool FileListView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: switchImages((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 1: saveForm(); break;
    case 2: loadForm(); break;
    case 3: changeData((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2)); break;
    case 4: nextItem(); break;
    case 5: prevItem(); break;
    default:
	return QListView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool FileListView::qt_emit( int _id, QUObject* _o )
{
    return QListView::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool FileListView::qt_property( int id, int f, QVariant* v)
{
    return QListView::qt_property( id, f, v);
}

bool FileListView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
