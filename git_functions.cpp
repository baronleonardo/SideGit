#include "git_functions.h"
#include <QProcess>
//#include <git2.h>
#include <QDebug>
#include <QTextCodec>

#define QByteArray_TO_QString(bArr) QTextCodec::codecForName("UTF-8")->toUnicode( bArr );

bool git_is_repo( QString path )
{
    /*// GIT
    git_libgit2_init();

    git_repository *repo = NULL;
    int error = git_repository_open(&repo, repository.toStdString().c_str());

    // Pass NULL for the output parameter to check for but not open the repo
    if (error < 0)
    {
        // directory looks like an openable repository
        QMessageBox::warning( this, "error!", "This path doesn't have a GIT repo" );
    }*/

    QProcess process;
    process.start( "./git_check_repo.sh", QStringList() << path );
//    process.setProcessChannelMode(QProcess::ForwardedChannels);

    while(process.waitForFinished());

    int status = process.exitCode();

    if( status != 0 )
        return false;

    return true;
}

void git_add( QString file_name )
{
    QProcess process;
    process.start( "./git_add.sh", QStringList() << file_name );
//    process.setProcessChannelMode(QProcess::ForwardedChannels);

    while(process.waitForFinished());

    qDebug() << process.readAllStandardOutput();
    qDebug() << process.readAllStandardError();
}

void git_commit(QString path, QString msg)
{
    QProcess process;
    process.start( "./git_commit.sh", QStringList() << path << msg );
//    process.setProcessChannelMode(QProcess::ForwardedChannels);

    while(process.waitForFinished());

    qDebug() << process.readAllStandardOutput();
}

void git_open_terminal_here(QString path)
{
    QProcess process;
    process.start( "./open_terminal_here.sh", QStringList() << path );

    while(process.waitForFinished());
}

QString git_status(QString path)
{
    QProcess process;
    process.start( "./git_status.sh", QStringList() << path );
//    process.setProcessChannelMode(QProcess::ForwardedChannels);

    while(process.waitForFinished());

    return QByteArray_TO_QString( process.readAllStandardOutput() );
}

QString git_branches(QString path, QString func_name, QString parameters)
{
    QProcess process;
    process.start( "./git_branches.sh", QStringList() << func_name << path << parameters );
//    process.setProcessChannelMode(QProcess::ForwardedChannels);

    while(process.waitForFinished());

    return QByteArray_TO_QString( process.readAllStandardOutput() );
}
