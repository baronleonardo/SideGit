#-------------------------------------------------
#
# Project created by QtCreator 2016-06-07T16:13:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SideGit
TEMPLATE = app

#LIBS += -lgit2

SOURCES += main.cpp\
        mainwindow.cpp \
    addfiles_button.cpp \
    git_functions.cpp \
    qframe_edit.cpp

HEADERS  += mainwindow.h \
    addfiles_button.h \
    git_functions.h \
    qframe_edit.h

FORMS    += mainwindow.ui

DISTFILES += \
    git_add.sh \
    git_check_repo.sh \
    git_commit.sh \
    open_terminal_here.sh \
    git_status.sh
