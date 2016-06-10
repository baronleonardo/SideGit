#include "qframe_edit.h"
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDebug>
#include "git_functions.h"
#include "cassert"

QFrame_edit::QFrame_edit(QWidget* parnet) : QFrame(parnet)
{
    repository = "";
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
    assert( repository != "" );

    // we use for loop as if the user drag more than one file
    foreach( const QUrl &url, event->mimeData()->urls() )
    {
        git_add( repository, url.toLocalFile() );
    }
}
