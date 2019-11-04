TEMPLATE = app
CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG -= qt
QT       += core network

SOURCES += \
        advancedplayerinfo.cpp \
        boringplayerinfo.cpp \
        completeplayerinfo.cpp \
        design.cpp \
        firstplayerinfo.cpp \
        globalconstants.cpp \
        main.cpp \
        minimalplayerinfo.cpp \
        ownplayerinfo.cpp \
        playerinfo.cpp \
        serializable.cpp \
        serverinfo.cpp

HEADERS += \
    advancedplayerinfo.h \
    boringplayerinfo.h \
    completeplayerinfo.h \
    design.h \
    firstplayerinfo.h \
    globalconstants.h \
    minimalplayerinfo.h \
    ownplayerinfo.h \
    playerinfo.h \
    serializable.h \
    serverinfo.h
