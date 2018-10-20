#-------------------------------------------------
#
# Project created by QtCreator 2016-11-01T21:04:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dronecontrol
TEMPLATE = app

INCLUDEPATH +=  /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui  -lopencv_imgproc


SOURCES += main.cpp\
        mainwindow.cpp \
    rosthread.cpp

HEADERS  += mainwindow.h \
    rosthread.h

FORMS    += mainwindow.ui

RESOURCES +=
