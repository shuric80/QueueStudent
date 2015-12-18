#-------------------------------------------------
#
# Project created by QtCreator 2015-12-17T20:56:38
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = studentsprofile
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    clientprofile.cpp \
    guiauthenticated.cpp \
    topclass.cpp

HEADERS  += widget.h \
    clientprofile.h \
    guiauthenticated.h \
    topclass.h

FORMS    += widget.ui \
    guiauthenticated.ui
