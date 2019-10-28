TEMPLATE = app
CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG -= qt
QT       += core network

SOURCES += \
        globalconstants.cpp \
        main.cpp \
        serverinfo.cpp

HEADERS += \
    globalconstants.h \
    serverinfo.h
