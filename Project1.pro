TEMPLATE = app
TARGET = Project1

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4) :  QT += widgets

SOURCES += \
    custombutton.cpp \
    mainWindow.cpp \
    prog.cpp

HEADERS += \
    custombutton.h \
    mainWindow.h
