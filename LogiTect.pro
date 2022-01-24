QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    logicalelement.cpp \
    main.cpp \
    mainwindow.cpp \
    methods.cpp \
    net.cpp \
    truthtable.cpp

HEADERS += \
    classes.h \
    logictypes.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

#TRANSLATIONS += \
 #   LogiTect_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

#win32:RC_FILE = rcfile.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
