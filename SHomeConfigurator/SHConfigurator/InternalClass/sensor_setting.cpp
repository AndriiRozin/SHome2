#include "sensor_setting.h"

Sensor_Setting::Sensor_Setting():
    name(),
    sensorID(),
    description(),
    network(),
    placement2(),
    placement1(),
    placement0(),
    signalValue()
{}

Sensor_Setting::Sensor_Setting(QString Name, int SensorID):
    name(Name),
    sensorID(SensorID)
{}

Sensor_Setting::Sensor_Setting(QString Name, int SensorID,
                               Placement_Setting Placement2,
                               Placement_Setting Placement1,
                               Placement_Setting Placement0,
                               QString Description):
    name(Name),
    sensorID(SensorID),
    description(Description),
    network(),
    placement2(Placement2),
    placement1(Placement1),
    placement0(Placement0),

    signalValue()
{}

void Sensor_Setting::set_name(QString value)
{
    name = value;
}
QString Sensor_Setting::get_name(){
    return name;
}

void Sensor_Setting::set_id(int value)
{
    sensorID = value;
}
int Sensor_Setting::get_id()
{
    return sensorID;
}

void Sensor_Setting::set_plasement2(Placement_Setting value)
{
    placement2 = value;
}

Placement_Setting Sensor_Setting::get_placement2()
{
    return  placement2;
}

void Sensor_Setting::set_plasement1(Placement_Setting value)
{
    placement1 = value;
}

Placement_Setting Sensor_Setting::get_placement1()
{
    return  placement1;
}

void Sensor_Setting::set_plasement0(Placement_Setting value)
{
    placement0 = value;
}

Placement_Setting Sensor_Setting::get_placement0()
{
    return  placement0;
}

void Sensor_Setting::set_description(QString value)
{
    description = value;
}

QString Sensor_Setting::get_description()
{
    return description;
}

void Sensor_Setting::set_network(Net_Setting net)
{
    network = net;
}
Net_Setting Sensor_Setting::get_network()
{
    return network;
}

void Sensor_Setting::set_signal(Signal_Setting value)
{
    signalValue = value;
}

Signal_Setting Sensor_Setting::get_signal()
{
    return signalValue;
}
