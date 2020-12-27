QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    graphics.cpp \
    ground.cpp \
    kong.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    npc.cpp \
    sprite.cpp \
    toshizo.cpp \
    wall.cpp \
    wraith.cpp

HEADERS += \
    collision.h \
    graphics.h \
    ground.h \
    kong.h \
    mainwindow.h \
    map.h \
    npc.h \
    sprite.h \
    toshizo.h \
    wall.h \
    wraith.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
