QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    el_to_save_form.cpp \
    graphicsscene.cpp \
    input_output.cpp \
    input_output_properties.cpp \
    logical_element_properties.cpp \
    logicalelement.cpp \
    main.cpp \
    mainwindow.cpp \
    methods.cpp \
    net.cpp \
    net_properties.cpp \
    set_logic_level.cpp \
    truthtable.cpp

HEADERS += \
    el_to_save_form.h \
    graphicsscene.h \
    input_output.h \
    input_output_properties.h \
    logical_element_properties.h \
    logicalelement.h \
    logictypes.h \
    mainwindow.h \
    methods.h \
    net.h \
    net_properties.h \
    set_logic_level.h \
    temp.h

FORMS += \
    el_to_save_form.ui \
    input_output_properties.ui \
    logical_element_properties.ui \
    mainwindow.ui \
    net_properties.ui \
    set_logic_level.ui

TRANSLATIONS += \
    LogiTect_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

win32:RC_FILE = rcfile.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    LogiTect_ru_RU.ts

RESOURCES += \
    resources.qrc
