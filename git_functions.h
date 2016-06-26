#ifndef GIT_FUNCTIONS_H
#define GIT_FUNCTIONS_H

#include <QString>
#include <QStringList>

class Scripts
{
private:
    Scripts();

private:
    static Scripts *scripts;
    QStringList cmd_args_git_check_repo;
    QStringList cmd_args_git_add;
    QStringList cmd_args_git_commit;
    QStringList cmd_args_git_open_termainl;
    QStringList cmd_args_git_status;
    QStringList cmd_args_git_branches;

public:
    static Scripts* get_Scribts_obj();

private:
    QStringList build_args( QString script_path );

public:
    bool git_is_repo( QString path );
    void git_add( QString path, QString file_name );
    void git_commit( QString path, QString msg );
    void git_open_terminal_here(QString path);
    QString git_status(QString path);
    QString git_branches(QString path, QString func_name, QString parameters = "");
};

#endif // GIT_FUNCTIONS_H
