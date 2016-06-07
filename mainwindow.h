#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

protected:
    void keyPressEvent(QKeyEvent *);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
};

#endif // MAINWINDOW_H
