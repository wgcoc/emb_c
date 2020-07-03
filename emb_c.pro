QT += core
QT -= gui

TARGET = emb_c
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Business.cpp \
    queue.c

HEADERS += \
    Business.hpp \
    queue.h

