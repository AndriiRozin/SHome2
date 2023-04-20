QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    InternalClass/actuator_setting.cpp \
    InternalClass/net_setting.cpp \
    InternalClass/placement_setting.cpp \
    InternalClass/sensor_setting.cpp \
    InternalClass/setting_containers.cpp \
    InternalClass/signal_setting.cpp \
    Settings/dialog_actuator_edit.cpp \
    Settings/dialog_actuator_setting.cpp \
    Settings/dialog_cannodeedit.cpp \
    Settings/dialog_net_edit.cpp \
    Settings/dialog_net_setting.cpp \
    Settings/dialog_placement_edit.cpp \
    Settings/dialog_placement_setting.cpp \
    Settings/dialog_sasetting.cpp \
    Settings/dialog_sensor_edit.cpp \
    Settings/dialog_sensor_setting.cpp \
    Settings/dialog_setup.cpp \
    Settings/dialog_signal_edit.cpp \
    Settings/dialog_signal_setting.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    InternalClass/actuator_setting.h \
    InternalClass/net_setting.h \
    InternalClass/placement_setting.h \
    InternalClass/sensor_setting.h \
    InternalClass/setting_containers.h \
    InternalClass/signal_setting.h \
    Settings/dialog_actuator_edit.h \
    Settings/dialog_actuator_setting.h \
    Settings/dialog_cannodeedit.h \
    Settings/dialog_net_edit.h \
    Settings/dialog_net_setting.h \
    Settings/dialog_placement_edit.h \
    Settings/dialog_placement_setting.h \
    Settings/dialog_sasetting.h \
    Settings/dialog_sensor_edit.h \
    Settings/dialog_sensor_setting.h \
    Settings/dialog_setup.h \
    Settings/dialog_signal_edit.h \    
    Settings/dialog_signal_setting.h \
    mainwindow.h

FORMS += \
    Settings/dialog_actuator_edit.ui \
    Settings/dialog_actuator_setting.ui \
    Settings/dialog_cannodeedit.ui \
    Settings/dialog_net_edit.ui \
    Settings/dialog_net_setting.ui \
    Settings/dialog_placement_edit.ui \
    Settings/dialog_placement_setting.ui \
    Settings/dialog_sasetting.ui \
    Settings/dialog_sensor_edit.ui \
    Settings/dialog_sensor_setting.ui \
    Settings/dialog_setup.ui \    
    Settings/dialog_signal_edit.ui \
    Settings/dialog_signal_setting.ui \
    mainwindow.ui

TRANSLATIONS += \
    SHConfigurator_uk_UA.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
