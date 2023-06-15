#ifndef SETTING_CONTAINERS_H
#define SETTING_CONTAINERS_H

#include <QMap>

#include "InternalClass/net_setting.h"
#include "InternalClass/placement_setting.h"
#include "InternalClass/sensor_setting.h"
#include "InternalClass/signal_setting.h"
#include "InternalClass/actuator_setting.h"

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
    void parsing_xml_net(QDomElement child);
    void parsing_xml_place(QDomElement child);
    void parsing_xml_signal(QDomElement child);
    void parsing_xml_actuator(QDomElement child);
    void parsing_xml_sensor(QDomElement child);

    void create_xml_nets(QDomDocument document_xml, QDomElement);
    void create_xml_places(QDomDocument document_xml, QDomElement);
    void create_xml_signals(QDomDocument document_xml, QDomElement);
    void create_xml_actuators(QDomDocument document_xml, QDomElement);
    void create_xml_sensors(QDomDocument document_xml, QDomElement);

public:
    QMap<int, Net_Setting> networks_map;
    QMap<int, Placement_Setting> placements_map;
    QMap<int, Signal_Setting> signals_map;
    QMap<int, Actuator_Setting> actuators_map;
    QMap<int, Sensor_Setting> sensors_map;

private:
    QString xml_filename;
};

#endif // SETTING_CONTAINERS_H
