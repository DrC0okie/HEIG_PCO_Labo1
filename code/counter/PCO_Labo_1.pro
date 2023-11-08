#-------------------------------------------------
#
# Project created by QtCreator 2015-02-12T16:05:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


TARGET = PCO_Labo_1
TEMPLATE = app

LIBS += -lpcosynchro

SOURCES += main.cpp\
        dialog.cpp \
    mythread.cpp \
    naivespinlock.cpp \
    spinlock.cpp \
    ticketLock.cpp \
    yieldlock.cpp

HEADERS  += dialog.h \
    mythread.h \
    naivespinlock.h \
    spinlock.h \
    ticketLock.h \
    yieldlock.h

FORMS    += dialog.ui
