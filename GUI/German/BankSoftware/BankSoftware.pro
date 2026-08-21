QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    widget.cpp \
    konto.cpp \
    girokonto.cpp \
    sparkonto.cpp \
    data.cpp \
    controller.cpp

HEADERS += \
    widget.h \
    konto.h \
    girokonto.h \
    sparkonto.h \
    data.h \
    controller.h

# Es wird keine widget.ui verwendet: die Oberfläche (View) wird bewusst im
# Code aufgebaut (siehe widget.cpp), um sie unabhängig vom Qt Designer
# nachvollziehbar und versionierbar zu halten.

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
