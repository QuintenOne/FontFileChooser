QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled23
TEMPLATE = app

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    filelist.cpp \
    fontlabel.cpp

HEADERS += \
        mainwindow.h \
    filelist.h \
    fontlabel.h

FORMS += \
        mainwindow.ui \
    filelist.ui \
    fontlabel.ui
