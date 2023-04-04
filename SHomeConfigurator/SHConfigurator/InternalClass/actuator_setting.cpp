#include "actuator_setting.h"

Actuator_Setting::Actuator_Setting():
    name(),
    sensorID(),
    description(),
    network(),
    placement2(),
    placement1(),
    placement0(),
    signalValue()
{}

Actuator_Setting::Actuator_Setting(QString Name, int SensorID):
    name(Name),
    sensorID(SensorID)
{}


Actuator_Setting::Actuator_Setting(QString Name, int SensorID,
                               Placement_Setting Placement2,
                               Placement_Setting Placement1,
                               Placement_Setting Placement0,
                               QString Description ):
    name(Name),
    sensorID(SensorID),
    description(Description),
    network(),
    placement2(Placement2),
    placement1(Placement1),
    placement0(Placement0),

    signalValue()
{}

void Actuator_Setting::set_name(QString value)
{
    name = value;
}
QString Actuator_Setting::get_name(){
    return name;
}

void Actuator_Setting::set_id(int value)
{
    sensorID = value;
}
int Actuator_Setting::get_id()
{
    return sensorID;
}

void Actuator_Setting::set_plasement2(Placement_Setting value)
{
    placement2 = value;
}

Placement_Setting Actuator_Setting::get_placement2()
{
    return  placement2;
}

void Actuator_Setting::set_plasement1(Placement_Setting value)
{
    placement1 = value;
}

Placement_Setting Actuator_Setting::get_placement1()
{
    return  placement1;
}

void Actuator_Setting::set_plasement0(Placement_Setting value)
{
    placement0 = value;
}

Placement_Setting Actuator_Setting::get_placement0()
{
    return  placement0;
}

void Actuator_Setting::set_description(QString value)
{
    description = value;
}

QString Actuator_Setting::get_description()
{
    return description;
}

void Actuator_Setting::set_network(Net_Setting net)
{
    network = net;
}
Net_Setting Actuator_Setting::get_network()
{
    return network;
}

void Actuator_Setting::set_signal(Signal_Setting value)
{
    signalValue = value;
}

Signal_Setting Actuator_Setting::get_signal()
{
    return signalValue;
}
