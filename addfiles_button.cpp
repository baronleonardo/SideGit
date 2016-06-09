#include "addfiles_button.h"
#include <QDebug>
#include <QMimeData>
#include <QFileDialog>
#include "git_functions.h"
#include <cassert>

AddFiles_button::AddFiles_button(QWidget* parent) : QPushButton(parent)
{
    connect( this, SIGNAL(clicked(bool)), this, SLOT(add_files_event()) );
    repository = "";
}

//void AddFiles_button::dragEnterEvent(QDragEnterEvent *event)
//{
//    if( event->mimeData()->hasUrls() )
//        event->acceptProposedAction();
//}

//void AddFiles_button::dropEvent(QDropEvent * event)
//{

//    // we use for loop as if the user drag more than one file
//    foreach( const QUrl &url, event->mimeData()->urls() )
//    {
//        git_add( url.toLocalFile() );
//    }
//}

void AddFiles_button::add_files_event()
{
    assert( repository != "" );

    QStringList list = QFileDialog::getOpenFileNames(this,
        tr("Choose file(s) to be added to the current repo"),
        repository, "*");

    foreach (QString file_name, list)
    {
        git_add( file_name );
    }
}
