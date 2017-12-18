/****************************************************************************
** RadioWidget meta object code from reading C++ file 'radiowidget.h'
**
** Created: Wed Jun 25 17:39:36 2003
**      by: The Qt MOC ($Id: moc_radiowidget.cpp 208 2003-06-27 22:28:53Z charu $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "radiowidget.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *RadioWidget::className() const
{
    return "RadioWidget";
}

QMetaObject *RadioWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_RadioWidget( "RadioWidget", &RadioWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString RadioWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "RadioWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString RadioWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "RadioWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* RadioWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QButtonGroup::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"RadioWidget", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_RadioWidget.setMetaObject( metaObj );
    return metaObj;
}

void* RadioWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "RadioWidget" ) )
	return this;
    return QButtonGroup::qt_cast( clname );
}

bool RadioWidget::qt_invoke( int _id, QUObject* _o )
{
    return QButtonGroup::qt_invoke(_id,_o);
}

bool RadioWidget::qt_emit( int _id, QUObject* _o )
{
    return QButtonGroup::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool RadioWidget::qt_property( int id, int f, QVariant* v)
{
    return QButtonGroup::qt_property( id, f, v);
}

bool RadioWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
