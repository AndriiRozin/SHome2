#include "net_setting.h"

Net_Setting::Net_Setting():
    name(),
    id()
{}

Net_Setting::Net_Setting(QString Name, int ID, QString _description):
    name(Name),
    id(ID),
    description(_description)
{}

QString Net_Setting::get_name()
{
    return name;
}

void Net_Setting::set_name(QString new_name)
{
    name = new_name;
}

int Net_Setting::get_id()
{
    return id;
}

void Net_Setting::set_id(int new_id)
{
    id = new_id;
}

QString Net_Setting::get_description()
{
    return description;
}

void Net_Setting::set_description(QString new_description)
{
    description = new_description;
}
