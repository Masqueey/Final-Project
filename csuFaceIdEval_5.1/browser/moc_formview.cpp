/****************************************************************************
** FormView meta object code from reading C++ file 'formview.h'
**
** Created: Wed Jun 25 17:39:20 2003
**      by: The Qt MOC ($Id: moc_formview.cpp 208 2003-06-27 22:28:53Z charu $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "formview.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *FormView::className() const
{
    return "FormView";
}

QMetaObject *FormView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_FormView( "FormView", &FormView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString FormView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString FormView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "FormView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* FormView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"FormView", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_FormView.setMetaObject( metaObj );
    return metaObj;
}

void* FormView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "FormView" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool FormView::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool FormView::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool FormView::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool FormView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
