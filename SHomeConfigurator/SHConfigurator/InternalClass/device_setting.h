#ifndef DEVICE_SETTING_H
#define DEVICE_SETTING_H

#include <QString>
#include <QMap>


class Device_Setting
{
public:
    Device_Setting();
    Device_Setting(QString Name, int ID, QString description);


    QString get_name();
    int     get_id();
    QString get_description();


    void set_name(QString new_name);    
    void set_id(int new_id);    
    void set_description(QString new_description);


public:
    QMap<int,QString> dev_actuator_map;
    QMap<int,QString> dev_sensor_map;

private:
    QString name;
    int id;
    QString description;
};

#endif // DEVICE_SETTING_H
