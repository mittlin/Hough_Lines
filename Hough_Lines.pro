#-------------------------------------------------
#
# Project created by QtCreator 2015-09-22T09:35:41
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Hough_Lines
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

CV_LIB = /usr/local/lib
LIBS += -L$${CV_LIB} -lopencv_ml -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_video -lopencv_legacy

SOURCES += main.cpp
