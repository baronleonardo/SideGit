#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QRect>
#include <QDesktopWidget>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_Hover);

    QRect rec = QApplication::desktop()->screenGeometry();
    int width = rec.width();
    int height = rec.height();

    int X = - (width / 2);
    int Y =  (height / 2) - 150;

    this->setGeometry( X, Y, 55, 300 );

    this->resize( 2, 300 );
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
        qApp->quit();
}

void MainWindow::enterEvent(QEvent *event)
{
    if(event->MouseMove)
    {
        QThread::msleep(100);
        this->resize( 55, 300 );
    }
}

void MainWindow::leaveEvent(QEvent *event)
{
    if(event->MouseMove)
    {
        QThread::msleep(500);
        this->resize( 2, 300 );
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
