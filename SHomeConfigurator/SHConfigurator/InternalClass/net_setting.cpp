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

int Net_Setting::get_id()
{
    return id;
}

QString Net_Setting::get_description()
{
    return description;
}
