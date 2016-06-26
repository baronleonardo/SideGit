#ifndef QFRAME_EDIT_H
#define QFRAME_EDIT_H

#include <QObject>
#include <QFrame>
#include <QString>
#include "git_functions.h"

class QFrame_edit : public QFrame
{
    Q_OBJECT
public:
    QFrame_edit(QWidget* parnet = NULL);

public:
    QString repository;

private:
    Scripts *scripts;

public slots:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent* event);

signals:
    void attempt_to_drop();
};

#endif // QFRAME_EDIT_H
