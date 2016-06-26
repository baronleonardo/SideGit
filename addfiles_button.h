#ifndef ADDFILES_BUTTON_H
#define ADDFILES_BUTTON_H

#include <QPushButton>
#include <QDropEvent>
#include <QString>
#include <QList>
#include "git_functions.h"

class AddFiles_button : public QPushButton
{
    Q_OBJECT

public:
    QString repository;

private:
    Scripts *scripts;

public:
    AddFiles_button(QWidget* parent = NULL);

private slots:
    void add_files_event();
//    void dragEnterEvent(QDragEnterEvent *event);
//    void dropEvent(QDropEvent* event);
//    QList<QString> get_draged_files();
};

#endif // ADDFILES_BUTTON_H
