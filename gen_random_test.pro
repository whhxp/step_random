QT += core
QT -= gui

CONFIG += c++11

TARGET = gen_random_test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    #step_random.cpp

HEADERS += \
    step_random.h
