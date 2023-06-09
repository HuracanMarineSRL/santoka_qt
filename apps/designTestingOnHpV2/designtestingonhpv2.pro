#-------------------------------------------------
#
# Project created by QtCreator 2023-01-26T02:33:25
#
#-------------------------------------------------
CONFIG += c++17
QT       += core gui xml designer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = designtestonhpv2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += SANTOKA
DEFINES += DESKTOP
#DEFINES += MACOS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    batteryfullwidget.cpp \
   pages/faultdialog.cpp \
    displayer/battery_filter.cpp \
    dataproducer.cpp \
    main.cpp \
    mainwindow.cpp \
    widgets/battery.cpp \
    widgets/batterydesign.cpp \
    displayer/generalinfo_filter.cpp \
    displayer/motor_filter.cpp \
    displayer/thermicmotor_filter.cpp \
    displayer/command_filter.cpp \
    displayer/vahicle_filter.cpp \
    displayer/filter.cpp \
    boatinfowindow.cpp \
    widgets/batterywidget.cpp

HEADERS += \
    batteryfullwidget.h \
    displayer/battery_filter.h \
    pages/faultdialog.h \
    dataproducer.h \
    mainwindow.h \
    widgets/battery.h \
      widgets/batterydesign.h \
    displayer/generalinfo_filter.h \
    displayer/motor_filter.h \
    displayer/thermicmotor_filter.h \
    displayer/command_filter.h \
    displayer/vahicle_filter.h \
    displayer/filter.h \
    boatinfowindow.h \
    widgets/batterywidget.h

FORMS += \
    batteryfullwidget.ui \
        mainwindow.ui \
        faultdialog.ui \
    batterydisign.ui \
    boatinfowindow.ui \
    widgets/battery.ui \
    widgets/batterywidget.ui

CONFIG += monility
MOBILITY += systeminfo

RESOURCES += \
    resources.qrc
