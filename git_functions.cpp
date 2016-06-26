#include "git_functions.h"
#include <QProcess>
//#include <git2.h>
#include <QDebug>
#include <QTextCodec>

#define QByteArray_TO_QString(bArr) QTextCodec::codecForName("UTF-8")->toUnicode( bArr );

#define CMD "/bin/bash"

QStringList build_args( QString script_path )
{
    QFile file(script_path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            exit(-1);

    return QStringList() << "-c" << file.readAll() << "bash";
}

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
    process.start( CMD, QStringList() << build_args(":/scripts/git_check_repo.sh") << path );
//    process.setProcessChannelMode(QProcess::ForwardedChannels);

    while(process.waitForFinished());

    int status = process.exitCode();

    if( status != 0 )
        return false;

    return true;
}

void git_add( QString path, QString file_name )
{
    QProcess process;
    process.start( CMD, QStringList() << build_args(":/scripts/git_add.sh") << path << file_name );
//    process.setProcessChannelMode(QProcess::ForwardedChannels);

    while(process.waitForFinished());

    qDebug() << process.readAllStandardOutput();
    qDebug() << process.readAllStandardError();
}

void git_commit(QString path, QString msg)
{
    QProcess process;
    process.start( CMD, QStringList() << build_args(":/scripts/git_commit.sh") << path << msg);
//    process.setProcessChannelMode(QProcess::ForwardedChannels);

    while(process.waitForFinished());

    qDebug() << process.readAllStandardOutput();
}

void git_open_terminal_here(QString path)
{
    QProcess process;
    process.start( CMD, QStringList() << build_args(":/scripts/open_terminal_here.sh") << path );

    while(process.waitForFinished());

    qDebug() << process.readAllStandardOutput();
    qDebug() << process.readAllStandardError();
}

QString git_status(QString path)
{
    QProcess process;
    process.start( CMD, QStringList() << build_args(":/scripts/git_status.sh") << path );
//    process.setProcessChannelMode(QProcess::ForwardedChannels);

    while(process.waitForFinished());

    return QByteArray_TO_QString( process.readAllStandardOutput() );
}

QString git_branches(QString path, QString func_name, QString parameters)
{
    QProcess process;
    process.start( CMD, QStringList() << build_args(":/scripts/git_branches.sh") << func_name << path << parameters );
//    process.setProcessChannelMode(QProcess::ForwardedChannels);

    while(process.waitForFinished());

    return QByteArray_TO_QString( process.readAllStandardOutput() );
}
