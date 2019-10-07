QT       += core gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    main.cpp \
    mainwindow.cpp \
    mybutton.cpp \
    server/core/acceleration.cpp \
    server/core/gamecore.cpp \
    server/core/globalconstants.cpp \
    server/core/map.cpp \
    server/core/ship.cpp \
    server/gui/servergui.cpp \
    server/sn/servernetcommunication.cpp

HEADERS += \
    mainwindow.h \
    mybutton.h \
    server/core/acceleration.h \
    server/core/gamecore.h \
    server/core/globalconstants.h \
    server/core/map.h \
    server/core/ship.h \
    server/gui/servergui.h \
    server/sn/servernetcommunication.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    README.md \
    Screenshot.png \
    TODO
