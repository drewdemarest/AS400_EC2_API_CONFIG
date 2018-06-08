#-------------------------------------------------
#
# Project created by QtCreator 2018-06-07T11:11:58
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AS400_EC2_API_CONFIG
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    inputwidgets/as400inputwidget.cpp \
    inputwidgets/importscheduleinputwidget.cpp \
    inputwidgets/queryinputwidgets/invoicequeryinputwidget.cpp \
    inputwidgets/queryinputwidgets/customerchainqueryinputwidget.cpp \
    inputwidgets/mysqlinputwidget.cpp \
    json_settings/jsonsettings.cpp

HEADERS += \
        mainwindow.h \
    inputwidgets/as400inputwidget.h \
    inputwidgets/importscheduleinputwidget.h \
    inputwidgets/queryinputwidgets/invoicequeryinputwidget.h \
    inputwidgets/queryinputwidgets/customerchainqueryinputwidget.h \
    inputwidgets/mysqlinputwidget.h \
    json_settings/jsonsettings.h

FORMS += \
        mainwindow.ui \
    inputwidgets/as400inputwidget.ui \
    inputwidgets/importscheduleinputwidget.ui \
    inputwidgets/queryinputwidgets/invoicequeryinputwidget.ui \
    inputwidgets/queryinputwidgets/customerchainqueryinputwidget.ui \
    inputwidgets/mysqlinputwidget.ui
