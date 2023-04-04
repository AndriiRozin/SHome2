#include "setting_containers.h"

#include <QSettings>
#include <QDebug>


Setting_Containers::Setting_Containers()
{
    read_all_networks_from_file();
    read_all_placements_from_file();
    read_all_signals_from_file();
    read_all_actuators_from_file();
    read_all_sensors_from_file();
}

void Setting_Containers::read_all_networks_from_file()
{
    QSettings  settings("C:\\smart_home_setting\\Net.ini", QSettings::IniFormat);
    QStringList nets_lst = settings.childGroups();

    foreach(QString net, nets_lst){
        // read data for current placement
        int net_number = net.remove("Net_").toInt();

        settings.beginGroup("Net_" + QString::number(net_number));

        Net_Setting new_net(settings.value("Name").toString(),
                            settings.value("Id").toInt(),
                            settings.value("Description").toString());

        //placement_map.insert(placement_id, elem);
        networks_map.insert(settings.value("Id").toInt(), new_net);

        settings.endGroup();
    }
    qDebug() << "networks_map" <<networks_map.size();
}

void Setting_Containers::read_all_placements_from_file()
{
    QSettings  settings("C:\\smart_home_setting\\Placement.ini", QSettings::IniFormat);
    QStringList placement_lst = settings.childGroups();

    foreach(QString placement, placement_lst){
        // read data for current placement
        int placement_number = placement.remove("Placement_").toInt();

        settings.beginGroup("Placement_" + QString::number(placement_number));

        Placement_Setting new_placement(settings.value("Name").toString(),
                                        settings.value("Id").toInt(),
                                        settings.value("Description").toString());

        //placement_map.insert(placement_id, elem);
        placements_map.insert(settings.value("Id").toInt(), new_placement);

        settings.endGroup();
    }
    qDebug() << "placements_map" << placements_map.size();
}

void Setting_Containers::read_all_signals_from_file()
{
    QSettings  settings("C:\\smart_home_setting\\signals.ini", QSettings::IniFormat);
    QStringList signal_lst = settings.childGroups();

    Signal_Setting new_signal;

    // read values from file and put them to container
    foreach(QString signal, signal_lst) {

        settings.beginGroup(signal);
        new_signal.set_name(settings.value("Name").toString());
        new_signal.set_id(settings.value("Id").toInt());
        new_signal.set_description(settings.value("Description").toString());
        new_signal.set_offset(settings.value("Offset").toDouble());
        new_signal.set_scale(settings.value("Scale").toDouble());
        new_signal.set_initSourceValue(settings.value("InitSourceValue").toInt());
        new_signal.set_errSourceValue(settings.value("Err_sourceValue").toInt());
        new_signal.set_maxValue(settings.value("MaxValue").toDouble());
        new_signal.set_minValue(settings.value("MinValue").toDouble());
        new_signal.set_signalStatus(enum_signal_status::INIT);
        settings.endGroup();

        signals_map.insert(new_signal.get_id(), new_signal);
    }
    qDebug() << "signals_map" << signals_map.size();
}

void Setting_Containers::read_all_actuators_from_file()
{
    QSettings  settings("C:\\smart_home_setting\\actuator.ini", QSettings::IniFormat);
    QStringList actuators_lst = settings.childGroups();

    // create AbstractSensor for each
    foreach(QString actuator, actuators_lst){
        // read data for current sensor
        int actuator_number = actuator.remove("Actuator_").toInt();

        settings.beginGroup("Actuator_" + QString::number(actuator_number));

        Actuator_Setting  new_actuator;
        new_actuator.set_name(settings.value("Name").toString());
        new_actuator.set_id(settings.value("Id").toInt());
        new_actuator.set_description(settings.value("Description").toString());

        int pl2_id = settings.value("Plasement2").toInt();
        new_actuator.set_plasement2(placements_map[pl2_id]);

        int pl1_id = settings.value("Plasement1").toInt();
        new_actuator.set_plasement1(placements_map[pl1_id]);

        int pl0_id = settings.value("Plasement0").toInt();
        new_actuator.set_plasement0(placements_map[pl0_id]);

        int net_id = settings.value("Network").toInt();
        new_actuator.set_network(networks_map[net_id]);

        int sig_id = settings.value("Signal").toInt();
        new_actuator.set_signal(signals_map[sig_id]);

        //placement_map.insert(placement_id, elem);
        actuators_map.insert(settings.value("Id").toInt(), new_actuator);

        settings.endGroup();
    }
    qDebug() << "actuators_map" << actuators_map.size();
}

void Setting_Containers::read_all_sensors_from_file()
{
    QSettings  settings("C:\\smart_home_setting\\sensor.ini", QSettings::IniFormat);
    QStringList sensors_lst = settings.childGroups();

    // create AbstractSensor for each sensor
    foreach(QString sensor, sensors_lst){
        // read data for current sensor
        int sensor_number = sensor.remove("Sensor_").toInt();

        settings.beginGroup("Sensor_" + QString::number(sensor_number));

        Sensor_Setting new_sensor;
        new_sensor.set_name(settings.value("Name").toString());
        new_sensor.set_id(settings.value("Id").toInt());
        new_sensor.set_description(settings.value("Description").toString());

        int net_id = settings.value("Network").toInt();
        Net_Setting net = networks_map[net_id];
        new_sensor.set_network(net);

        int pl2_id = settings.value("Plasement2").toInt();
        Placement_Setting plasement2 = placements_map[pl2_id];
        new_sensor.set_plasement2(plasement2);

        int pl1_id = settings.value("Plasement1").toInt();
        Placement_Setting plasement1 = placements_map[pl1_id];
        new_sensor.set_plasement1(plasement1);

        int pl0_id = settings.value("Plasement0").toInt();
        Placement_Setting plasement0 = placements_map[pl0_id];
        new_sensor.set_plasement0(plasement0);

        int sig_id = settings.value("Signal").toInt();
        Signal_Setting signal = signals_map[sig_id];
        new_sensor.set_signal(signal);

        //placement_map.insert(placement_id, elem);
        sensors_map.insert(settings.value("Id").toInt(), new_sensor);

        settings.endGroup();
    }
    qDebug() << "sensors_map" << sensors_map.size();
}
