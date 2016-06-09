#include "qframe_edit.h"
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDebug>
#include "git_functions.h"

QFrame_edit::QFrame_edit(QWidget* parnet) : QFrame(parnet)
{

}

void QFrame_edit::dragEnterEvent(QDragEnterEvent *event)
{
    if( event->mimeData()->hasUrls() )
    {
        event->acceptProposedAction();
        emit attempt_to_drop();
    }
}

void QFrame_edit::dropEvent(QDropEvent * event)
{
    // we use for loop as if the user drag more than one file
    foreach( const QUrl &url, event->mimeData()->urls() )
    {
        git_add( url.toLocalFile() );
    }
}
