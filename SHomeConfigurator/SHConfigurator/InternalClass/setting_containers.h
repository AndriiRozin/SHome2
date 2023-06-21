#ifndef SETTING_CONTAINERS_H
#define SETTING_CONTAINERS_H

#include <QMap>

#include "InternalClass/net_setting.h"
#include "InternalClass/placement_setting.h"
#include "InternalClass/sensor_setting.h"
#include "InternalClass/signal_setting.h"
#include "InternalClass/actuator_setting.h"
#include "InternalClass/device_setting.h"

#include <QtXml>
#include <QTextStream>

class Setting_Containers
{
public:
    Setting_Containers();

    void write_to_xml();
    void read_from_xml();

    int get_networkID_by_name(QString name, bool *ok);
    int get_placementID_by_name(QString name, bool *ok);
    int get_signalID_by_name(QString name, bool *ok);

    QStringList get_net_names_list();
    QStringList get_placement_names_list();
    QStringList get_signalValues_names_list();

private:
    QString read_xml_filename();
    void parsing_xml(QDomDocument document_xml);
    void parsing_xml_net(QDomElement elem);
    void parsing_xml_place(QDomElement elem);
    void parsing_xml_signal(QDomElement elem);
    void parsing_xml_actuator(QDomElement child);
    void parsing_xml_sensor(QDomElement elem);
    void parsing_xml_device(QDomElement elem);
    void parsing_xml_device_sensors(QDomElement, Device_Setting*);
    void parsing_xml_device_actuators(QDomElement, Device_Setting*);

    void create_xml_nets(QDomElement);
    void create_xml_places(QDomElement);
    void create_xml_signals(QDomElement);
    void create_xml_actuators(QDomElement);
    void create_xml_sensors(QDomElement);
    void create_xml_devices(QDomElement);
    void create_xml_device_sensors(QDomElement);
    void create_xml_device_actuators(QDomElement);

public:
    QMap<int, Net_Setting> networks_map;
    QMap<int, Placement_Setting> placements_map;
    QMap<int, Signal_Setting> signals_map;
    QMap<int, Actuator_Setting> actuators_map;
    QMap<int, Sensor_Setting> sensors_map;
    QMap<int, Device_Setting> devices_map;

private:
    QString xml_filename;
    QDomDocument document_xml;
};

#endif // SETTING_CONTAINERS_H
