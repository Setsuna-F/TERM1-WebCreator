#-------------------------------------------------
#
# Project created by QtCreator 2016-02-21T16:20:16
#
#-------------------------------------------------

#QT       += core gui
QT += widgets

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestDragAndDrop
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    rectangleitem.cpp \
    pagewidget.cpp \
    feuillewidget.cpp

HEADERS  += mainwindow.h \
    rectangleitem.h \
    pagewidget.h \
    feuillewidget.h

FORMS    += mainwindow.ui


# install
#target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/dragdroprobot
#INSTALLS += target
