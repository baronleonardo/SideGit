#ifndef GIT_FUNCTIONS_H
#define GIT_FUNCTIONS_H

#include <QString>

bool git_is_repo( QString path );
void git_add( QString file_name );
void git_commit( QString path, QString msg );
void git_open_terminal_here(QString path);
QString git_status(QString path);
QString git_branches(QString path, QString func_name, QString parameters = "");

#endif // GIT_FUNCTIONS_H
