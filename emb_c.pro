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
    HistogramDisplay.c \
    TestBuilder.c \
    NotificationHandle.c \
    TMDQueue_OBS.c \
    HistogramDisplay_OBS.c \
    observer/Observer.c \
    observer/Subject.c \
    observer/main_test.c

HEADERS += \
    Business.hpp \
    queue.h \
    cachedQueue.h \
    ECGPkg.h \
    TimeMarkedData.h \
    TMDQueue.h \
    includes.h \
    ECG_Module.h \
    HistogramDisplay.h \
    TestBuilder.h \
    NotificationHandle.h \
    TMDQueue_OBS.h \
    HistogramDisplay_OBS.h \
    observer/List.h \
    observer/Observer.h \
    observer/Subject.h

