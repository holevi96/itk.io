QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
INCLUDEPATH += ../shared/shared
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../shared/shared/serializehelper.cpp \
    ../shared/shared/serializable.cpp \
    ../shared/shared/boringplayerinfo.cpp \
    ../shared/shared/design.cpp \
    ../shared/shared/serverinfo.cpp \
    ../shared/shared/playerinfo.cpp \
    ../shared/shared/advancedplayerinfo.cpp \
    ../shared/shared/completeplayerinfo.cpp \
    ../shared/shared/minimalplayerinfo.cpp \
    ../shared/shared/ownplayerinfo.cpp \
    ../shared/shared/firstplayerinfo.cpp \
    ../shared/shared/c.cpp \
    client.cpp \
    connectingToServerScreen.cpp \
    inGameMenu.cpp \
    loginSreen.cpp \
    main.cpp \
    mainwindow.cpp \
    IngameView.cpp

HEADERS += \
    ../shared/shared/serializehelper.h \
    ../shared/shared/serializable.h \
    ../shared/shared/design.h \
    ../shared/shared/boringplayerinfo.h \
    ../shared/shared/serverinfo.h \
    ../shared/shared/playerinfo.h \
    ../shared/shared/advancedplayerinfo.h \
    ../shared/shared/completeplayerinfo.h \
    ../shared/shared/minimalplayerinfo.h \
    ../shared/shared/ownplayerinfo.h \
    ../shared/shared/firstplayerinfo.h \
    ../shared/shared/c.h \
    client.h \
    connectingToServerScreen.h \
    inGameMenu.h \
    loginSreen.h \
    mainwindow.h \
    IngameView.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
