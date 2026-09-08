QT += widgets

CONFIG += console c++11
CONFIG -= app_bundle
TEMPLATE = app
TARGET = login-dialog-smoke

INCLUDEPATH += ..

SOURCES += \
    smoke_test.cpp \
    ../logindialog.cpp \
    ../mainwindow.cpp

HEADERS += \
    ../logindialog.h \
    ../mainwindow.h

FORMS += \
    ../logindialog.ui \
    ../mainwindow.ui

RESOURCES += ../rc.qrc
