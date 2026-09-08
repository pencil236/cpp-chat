QT += widgets

CONFIG += c++11
TEMPLATE = app
TARGET = llfcchat

RC_ICONS = icon.ico
DESTDIR = ./bin

SOURCES += \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    logindialog.h \
    mainwindow.h

FORMS += \
    logindialog.ui \
    mainwindow.ui

RESOURCES += rc.qrc
