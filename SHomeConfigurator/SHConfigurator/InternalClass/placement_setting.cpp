#include "placement_setting.h"

Placement_Setting::Placement_Setting():
    name(),
    id()
{}


Placement_Setting::Placement_Setting(QString Name, int ID, QString Description):
    name(Name),
    id(ID),
    description(Description)
{}

QString Placement_Setting::get_name()
{
    return name;
}

int Placement_Setting::get_id()
{
    return id;
}

QString Placement_Setting::get_description()
{
    return description;
}



void Placement_Setting::set_name(const QString value)
{
    name = value;
}


void Placement_Setting::set_id(const int value)
{
    id = value;
}

void Placement_Setting::set_description(const QString value)
{
    description = value;
}
