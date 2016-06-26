#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QRect>
#include <QDesktopWidget>
#include <QThread>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QMimeData>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // splashScreen is used to skip taskbar
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint
                   | Qt::WindowStaysOnTopHint | Qt::SplashScreen );
    this->setAttribute(Qt::WA_Hover);
    // transpernecy
    this->setWindowOpacity( 0.97 );

    // calculate X and Y position
    QRect rec = QApplication::desktop()->screenGeometry();
    int window_width = rec.width();
    int window_height = rec.height();
    int X = - (window_width / 2);
    int Y = (window_height / 2) - this->height() / 2;

    this->setGeometry( X, Y, w_width_close, w_height );
    this->setFixedWidth( w_width_close );

    repository = QDir::homePath();

    add_and_commit = false;

    // get the only object from Scripts class
    scripts = Scripts::get_Scribts_obj();

    // EVENTS
    connect( ui->add_repo_btn, SIGNAL(clicked(bool)), this, SLOT(add_repo_event()) );
    connect( ui->frame, SIGNAL(attempt_to_drop()), this, SLOT(drop_event()) );
    connect( ui->commit_btn, SIGNAL(clicked(bool)), this, SLOT(commit_event()) );
    connect( ui->terminal_btn, SIGNAL(clicked(bool)), this, SLOT(open_terminal_event()) );
    connect( ui->status_btn, SIGNAL(clicked(bool)), this, SLOT(repo_status_event()) );
    connect( ui->quit_btn, SIGNAL(clicked(bool)), this, SLOT(quit_event()) );
}

void MainWindow::add_repo_event()
{
    repository = QFileDialog::getExistingDirectory(this,
        tr("Choose a GIT repository folder"),
        repository,
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    // if this is a git repository
    if( scripts->git_is_repo( repository ) )
    {
        ui->add_files_btn->setEnabled(true);
        ui->commit_btn->setEnabled(true);
        ui->commit_btn->setEnabled(true);
        ui->terminal_btn->setEnabled(true);
        ui->status_btn->setEnabled(true);
        ui->branch_btn->setEnabled(true);

        ui->add_repo_btn->setIcon( QIcon::fromTheme( "dialog-ok" ) );

        // enable droping
        ui->frame->setAcceptDrops(true);

        // TODO: need a better implementation
        ui->add_files_btn->repository = repository;
        ui->frame->repository = repository;
    }

    // if not
    else
    {
        // directory looks like an openable repository
        QMessageBox::warning( this, "error!", "This path doesn't have a GIT repo" );
        repository = QDir::homePath();
    }
}

void MainWindow::drop_event()
{
    this->setFixedWidth(w_width_open);
}

void MainWindow::commit_event()
{
    QString msg =  QInputDialog::getMultiLineText( this, "Commit message", "message:");

    if(add_and_commit == true)
    {
        scripts->git_add(repository, "all");
        scripts->git_commit(repository, msg);
    }

    else
        scripts->git_commit(repository, msg);
}

void MainWindow::open_terminal_event()
{
    scripts->git_open_terminal_here(repository);
}

void MainWindow::repo_status_event()
{
    QString status = scripts->git_status( repository );

    QMessageBox::information( this, "Git status", status, QMessageBox::Ok );
}


void MainWindow::on_branch_btn_clicked(bool checked)
{
    if(checked == 0)
    {
        QStringList items = scripts->git_branches(repository, QString("get_branches")).split('\n', QString::SkipEmptyParts);
        QString selected = QInputDialog::getItem( this, "Choose a branch", "branch:", items );

        // set selected branch as default
        qDebug() << scripts->git_branches( repository, QString("set_current_branch"),
                                  QString(selected) );
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
        qApp->quit();

    if(event->key() == Qt::Key_Control)
        add_and_commit = true;
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Control)
        add_and_commit = false;
}

void MainWindow::enterEvent(QEvent *event)
{
    if(event->MouseMove)
    {
        QThread::msleep(100);
        this->setFixedWidth( w_width_open );
    }
}

void MainWindow::leaveEvent(QEvent *event)
{
    if(event->MouseMove)
    {
        QThread::msleep(500);
        this->setFixedWidth( w_width_close );
    }
}

void MainWindow::quit_event()
{
    qApp->quit();
}

MainWindow::~MainWindow()
{
    delete ui;
}
