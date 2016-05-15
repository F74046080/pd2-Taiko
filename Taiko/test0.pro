#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T17:18:12
#
#-------------------------------------------------

QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test0
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myrect.cpp \
    enemy.cpp \
    score.cpp \
    game.cpp \
    enemy2.cpp \
    time.cpp \
    end.cpp

HEADERS  += mainwindow.h \
    enemy.h \
    score.h \
    game.h \
    enemy2.h \
    time.h \
    end.h \
    myrect.h

FORMS    += mainwindow.ui \
    end.ui

RESOURCES += \
    res.qrc

DISTFILES +=
