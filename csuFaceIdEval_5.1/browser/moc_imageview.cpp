/****************************************************************************
** ImageView meta object code from reading C++ file 'imageview.h'
**
** Created: Wed Jun 25 17:39:25 2003
**      by: The Qt MOC ($Id: moc_imageview.cpp 208 2003-06-27 22:28:53Z charu $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "imageview.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *ImageView::className() const
{
    return "ImageView";
}

QMetaObject *ImageView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_ImageView( "ImageView", &ImageView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString ImageView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ImageView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString ImageView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "ImageView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* ImageView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"ImageView", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_ImageView.setMetaObject( metaObj );
    return metaObj;
}

void* ImageView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "ImageView" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool ImageView::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool ImageView::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool ImageView::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool ImageView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
