#include "device_setting.h"

Device_Setting::Device_Setting():
    name(),
    id()
{}

Device_Setting::Device_Setting(QString Name, int ID, QString _description):
    name(Name),
    id(ID),
    description(_description)
{}

QString Device_Setting::get_name()
{
    return name;
}

void Device_Setting::set_name(QString new_name)
{
    name = new_name;
}

int Device_Setting::get_id()
{
    return id;
}

void Device_Setting::set_id(int new_id)
{
    id = new_id;
}

QString Device_Setting::get_description()
{
    return description;
}

void Device_Setting::set_description(QString new_description)
{
    description = new_description;
}




