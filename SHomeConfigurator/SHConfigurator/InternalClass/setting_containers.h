#ifndef SETTING_CONTAINERS_H
#define SETTING_CONTAINERS_H

#include <QMap>

#include "InternalClass/net_setting.h"
#include "InternalClass/placement_setting.h"
#include "InternalClass/sensor_setting.h"
#include "InternalClass/signal_setting.h"
#include "InternalClass/actuator_setting.h"

class Setting_Containers
{
public:
    Setting_Containers();

    void read_all_networks_from_file(QString filename);
    void read_all_placements_from_file(QString filename);
    void read_all_signals_from_file(QString filename);
    void read_all_actuators_from_file(QString filename);
    void read_all_sensors_from_file(QString filename);

    void save_all_networks_to_file();
    void save_all_placements_to_file();
    void save_all_sensors_to_file();
    void save_all_actuators_to_file();
    void save_all_signals_to_file();

    int get_networkID_by_name(QString name, bool *ok);
    int get_placementID_by_name(QString name, bool *ok);
    int get_signalID_by_name(QString name, bool *ok);

    QStringList get_net_names_list();
    QStringList get_placement_names_list();
    QStringList get_signalValues_names_list();

public:
    QMap<int, Net_Setting> networks_map;
    QMap<int, Placement_Setting> placements_map;
    QMap<int, Signal_Setting> signals_map;
    QMap<int, Actuator_Setting> actuators_map;
    QMap<int, Sensor_Setting> sensors_map;

private:
    //QString pathToini = "C:\\smart_home_setting\\";
    //QString pathToini = "/home/andrii/Arozin/SHome2/smart_home_setting/";
    QString pathToini;
    QString pathToIni_net;
    QString pathToIni_place;
    QString pathToIni_signal;
    QString pathToIni_sensor;
    QString pathToIni_actuator;
};

#endif // SETTING_CONTAINERS_H
