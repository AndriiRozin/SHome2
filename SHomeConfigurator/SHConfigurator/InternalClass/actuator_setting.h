#ifndef ACTUATOR_SETTING_H
#define ACTUATOR_SETTING_H

#include <QString>

#include "InternalClass/net_setting.h"
#include "InternalClass/placement_setting.h"
#include "InternalClass/signal_setting.h"

class Actuator_Setting
{
public:
    Actuator_Setting();
    Actuator_Setting(QString Name, int SensorID);
    Actuator_Setting(QString Name, int SensorID,
                     Placement_Setting Placement2, // вместоPlacement0-2 передать вектор плайсментов
                     Placement_Setting Placement1,
                     Placement_Setting Placement0,
                     QString Description);

    void set_name(QString);
    QString get_name();

    void set_id(int);
    int get_id();

    void set_plasement2(Placement_Setting);
    Placement_Setting get_placement2();

    void set_plasement1(Placement_Setting);
    Placement_Setting get_placement1();

    void set_plasement0(Placement_Setting);
    Placement_Setting get_placement0();

    void set_description(QString);
    QString get_description();

    void set_network(Net_Setting);
    Net_Setting get_network();

    void set_signal(Signal_Setting);
    Signal_Setting get_signal();

private:
    QString name;
    int sensorID;
    QString description;

    Net_Setting network;

    Placement_Setting placement2;
    Placement_Setting placement1;
    Placement_Setting placement0;

    Signal_Setting signalValue;
};

#endif // ACTUATOR_SETTING_H
