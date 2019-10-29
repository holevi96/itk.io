TEMPLATE = app
CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG -= qt
QT       += core network

SOURCES += \
        globalconstants.cpp \
        main.cpp \
        serializable.cpp \
        serverinfo.cpp

HEADERS += \
    globalconstants.h \
    serializable.h \
    serverinfo.h
