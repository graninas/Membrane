QT += core
QT += widgets

QT -= gui

CONFIG += c++1z

TARGET = Membrane
# CONFIG += console
# CONFIG -= app_bundle

TEMPLATE = app

SOURCES = \
    glwidget.cpp \
    main.cpp \
    window.cpp \
    membrane/membrane.cpp \
    world.cpp \
    membrane/patterns.cpp \
    membrane/pattern.cpp \
    membrane/schememanager.cpp \
    membrane/logic.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS = \
    glwidget.h \
    window.h \
    membrane/membrane.h \
    membrane/world.h \
    membrane/pattern.h \
    membrane/patterns.h \
    membrane/schememanager.h \
    membrane/logic.h

    

# install
# target.path = $$[QT_INSTALL_EXAMPLES]/opengl/2dpainting
# INSTALLS += target
