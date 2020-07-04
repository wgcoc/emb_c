QT += core
QT -= gui

TARGET = emb_c
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Business.cpp \
    queue.c \
    cachedQueue.c \
    TMDQueue.c \
    TimeMarkedData.c \
    ECG_Module.c \
    HistogramDisplay.c

HEADERS += \
    Business.hpp \
    queue.h \
    cachedQueue.h \
    ECGPkg.h \
    TimeMarkedData.h \
    TMDQueue.h \
    includes.h \
    ECG_Module.h \
    HistogramDisplay.h

