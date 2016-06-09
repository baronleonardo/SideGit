#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    QString repository;
    const uint w_width_close = 2;
    const uint w_width_open = 46;
    const uint w_height = 300;

protected:
    void keyPressEvent(QKeyEvent *);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

public slots:
    void add_repo_event();
    void commit_event();
    void drop_event();
    void repo_status_event();
    void open_terminal_event();
    void quit_event();
};

#endif // MAINWINDOW_H
