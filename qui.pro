#-------------------------------------------------
#
# Project created by QtCreator 2017-02-19T12:55:42
#
#-------------------------------------------------

QT       += core gui network
QT       += charts
QT       += serialport
QT       += network
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET          = qui
TEMPLATE        = app
MOC_DIR         = temp/moc
RCC_DIR         = temp/rcc
UI_DIR          = temp/ui
OBJECTS_DIR     = temp/obj
DESTDIR         = $$PWD/bin
win32:RC_FILE   = other/main.rc
PRECOMPILED_HEADER  = head.h

INCLUDEPATH     += $$PWD
INCLUDEPATH     += $$PWD/form
INCLUDEPATH     += $$PWD/demo
CONFIG          += qt warn_off
DEFINES         += demo1

SOURCES += main.cpp\    
    form/quiwidget.cpp \
    form/highlighter.cpp \
    form/panelwidget.cpp \
    form/frmdevice.cpp \
    demo/sliderbar.cpp \
    demo/navlistview.cpp \
    demo/uidemo3.cpp \
    dialog.cpp \
    demo/appinit.cpp \
    duankou.cpp \
    shujuku.cpp \
    help.cpp \
    setting.cpp

HEADERS  += head.h\
    form/quiwidget.h \
    form/highlighter.h \
    form/panelwidget.h \
    form/frmdevice.h \
    demo/appinit.h \
    demo/sliderbar.h \
    demo/navlistview.h \
    demo/uidemo3.h \
    dialog.h \
    duankou.h \
    shujuku.h \
    help.h \
    setting.h

FORMS    += \
    form/quicreator.ui \
    form/frmdevice.ui \
    dialog.ui \
    duankou.ui \
    shujuku.ui \
    help.ui \
    setting.ui \
    demo/uidemo333.ui \
    demo/uidemo3.ui

RESOURCES += \
    other/qss.qrc \
    other/main.qrc \
    demo/demo.qrc \
    other/qss/qss.qrc
