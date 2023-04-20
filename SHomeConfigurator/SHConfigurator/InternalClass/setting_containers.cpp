#include "setting_containers.h"

#include <QSettings>
#include <QDebug>
#include <QMap>


Setting_Containers::Setting_Containers():
    networks_map(),
    placements_map(),
    signals_map(),
    actuators_map(),
    sensors_map(),
    pathToini(),
    pathToIni_net(),
    pathToIni_place(),
    pathToIni_signal(),
    pathToIni_sensor(),
    pathToIni_actuator()

{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    pathToini = settings.value("Folder").toString();
    pathToIni_net = settings.value("Net").toString();
    pathToIni_place = settings.value("Place").toString();
    pathToIni_signal = settings.value("Signal").toString();
    pathToIni_sensor = settings.value("Sensor").toString();
    pathToIni_actuator = settings.value("Actuator").toString();
    settings.endGroup();

    read_all_networks_from_file(pathToIni_net);
    read_all_placements_from_file(pathToIni_place);
    read_all_signals_from_file(pathToIni_signal);
    read_all_actuators_from_file(pathToIni_actuator);
    read_all_sensors_from_file(pathToIni_sensor);
}

void Setting_Containers::read_all_networks_from_file(QString filename)
{
    QSettings  settings(filename, QSettings::IniFormat);
    QStringList nets_lst = settings.childGroups();

    foreach(QString net, nets_lst){
        // read data for current placement
        int net_number = net.remove("Net_").toInt();

        settings.beginGroup("Net_" + QString::number(net_number));

        Net_Setting new_net(settings.value("Name").toString(),
                            settings.value("Id").toInt(),
                            settings.value("Description").toString());

        networks_map.insert(settings.value("Id").toInt(), new_net);
        settings.endGroup();
    }
}

void Setting_Containers::read_all_placements_from_file(QString filename)
{
    QSettings  settings(filename, QSettings::IniFormat);
    QStringList placement_lst = settings.childGroups();

    foreach(QString placement, placement_lst){
        // read data for current placement
        int placement_number = placement.remove("Placement_").toInt();

        settings.beginGroup("Placement_" + QString::number(placement_number));

        Placement_Setting new_placement(settings.value("Name").toString(),
                                        settings.value("Id").toInt(),
                                        settings.value("Description").toString());

        placements_map.insert(settings.value("Id").toInt(), new_placement);
        settings.endGroup();
    }
}

void Setting_Containers::read_all_signals_from_file(QString filename)
{
    QSettings  settings(filename, QSettings::IniFormat);
    QStringList signal_lst = settings.childGroups();

    Signal_Setting new_signal;

    // read values from file and put them to container
    foreach(QString signal, signal_lst) {

        settings.beginGroup(signal);
        new_signal.set_name(settings.value("Name").toString());
        new_signal.set_id(settings.value("Id").toInt());
        new_signal.set_description(settings.value("Description").toString());
        new_signal.set_offset(settings.value("Offset").toDouble());
        new_signal.set_factor(settings.value("Scale").toDouble());
        new_signal.set_initRawValue(settings.value("InitSourceValue").toInt());
        new_signal.set_errRawValue(settings.value("Err_sourceValue").toInt());
        new_signal.set_maxValue(settings.value("MaxValue").toDouble());
        new_signal.set_minValue(settings.value("MinValue").toDouble());
        new_signal.set_signalStatus(enum_signal_status::INIT);
        settings.endGroup();

        signals_map.insert(new_signal.get_id(), new_signal);
    }
}

void Setting_Containers::read_all_actuators_from_file(QString filename)
{
    QSettings  settings(filename, QSettings::IniFormat);
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

        actuators_map.insert(settings.value("Id").toInt(), new_actuator);
        settings.endGroup();
    }
}

void Setting_Containers::read_all_sensors_from_file(QString filename)
{
    QSettings  settings(filename, QSettings::IniFormat);
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

        sensors_map.insert(settings.value("Id").toInt(), new_sensor);
        settings.endGroup();
    }   
}

void Setting_Containers::save_all_networks_to_file()
{
    QSettings  settings(pathToIni_net, QSettings::IniFormat);

    settings.clear();

    QList<int> keys = networks_map.keys();
    foreach(int key, keys)
    {
        Net_Setting myNet = networks_map[key];
        settings.beginGroup("Net_" + QString::number(myNet.get_id()));

        settings.setValue("Name", myNet.get_name());
        settings.setValue("Id", myNet.get_id());
        settings.setValue("Description" , myNet.get_description());

        settings.endGroup();
    }
}

void Setting_Containers::save_all_placements_to_file()
{
    QSettings  settings(pathToIni_place, QSettings::IniFormat);
    settings.clear();

    // create Placement for each Placements
    QList<int> keys = placements_map.keys();
    foreach(int key, keys)
    {
        Placement_Setting myPlacement = placements_map[key];

        settings.beginGroup("Placement_" + QString::number(myPlacement.get_id()));
        settings.setValue("Name", myPlacement.get_name());
        settings.setValue("Id", myPlacement.get_id());
        settings.setValue("Description",myPlacement.get_description());

        settings.endGroup();
    }
}

void Setting_Containers::save_all_sensors_to_file()
{
    QSettings  settings(pathToIni_sensor, QSettings::IniFormat);
    settings.clear();

    // create AbstractSensor for each sensor
    QList<int> keys = sensors_map.keys();
    foreach(int key, keys)
    {
        Sensor_Setting mySensor = sensors_map[key];

        settings.beginGroup("Sensor_" + QString::number(mySensor.get_id()));
        settings.setValue("Name", mySensor.get_name());
        settings.setValue("Id", mySensor.get_id());
        settings.setValue("Description",mySensor.get_description());
        settings.setValue("Plasement2",mySensor.get_placement2().get_id());
        settings.setValue("Plasement1",mySensor.get_placement1().get_id());
        settings.setValue("Plasement0",mySensor.get_placement0().get_id());
        settings.setValue("Signal", mySensor.get_signal().get_id());

        settings.endGroup();
    }
}

void Setting_Containers::save_all_actuators_to_file()
{
    QSettings  settings(pathToIni_actuator, QSettings::IniFormat);
    settings.clear();

    // create AbstractSensor for each sensor
    QList<int> keys = actuators_map.keys();
    foreach(int key, keys)
    {
        Actuator_Setting myActuator = actuators_map[key];

        settings.beginGroup("Actuator_" + QString::number(myActuator.get_id()));
        settings.setValue("Name", myActuator.get_name());
        settings.setValue("Id", myActuator.get_id());
        settings.setValue("Description",myActuator.get_description());
        settings.setValue("Plasement2",myActuator.get_placement2().get_id());
        settings.setValue("Plasement1",myActuator.get_placement1().get_id());
        settings.setValue("Plasement0",myActuator.get_placement0().get_id());
        settings.setValue("Signal", myActuator.get_signal().get_id());

        settings.endGroup();
    }
}

void Setting_Containers::save_all_signals_to_file()
{
    QSettings  settings(pathToIni_signal, QSettings::IniFormat);
    settings.clear();

    // create AbstractSensor for each sensor
    QList<int> keys = signals_map.keys();
    foreach(int key, keys)
    {
        Signal_Setting mySignal = signals_map[key];

        settings.beginGroup("Signal_" + QString::number(mySignal.get_id()));
        settings.setValue("Name", mySignal.get_name());
        settings.setValue("Id", mySignal.get_id());
        settings.setValue("Description",mySignal.get_description());
        settings.setValue("Offset",mySignal.get_offset());
        settings.setValue("Scale",mySignal.get_factor());
        settings.setValue("InitSourceValue",mySignal.get_initRawValue());
        settings.setValue("Err_sourceValue",mySignal.get_errRawValue());
        settings.setValue("MaxValue",mySignal.get_maxValue());
        settings.setValue("MinValue",mySignal.get_minValue());

        settings.endGroup();
    }
}

QStringList Setting_Containers::get_placement_names_list()
{
    QStringList placement_name_list;
    foreach(Placement_Setting key, placements_map)
    {
        placement_name_list.append(key.get_name());
    }
    return placement_name_list;
}

QStringList Setting_Containers::get_net_names_list()
{
    QStringList net_name_list;
    foreach(Net_Setting key, networks_map)
    {
        net_name_list.append(key.get_name());
    }
    return net_name_list;
}

int Setting_Containers::get_networkID_by_name(QString name, bool *ok)
{
    foreach(Net_Setting key, networks_map)
    {
        if(name == key.get_name()) {
            *ok = true;
            return key.get_id();
        }
    }
    *ok = false;
    return 0;
}

int Setting_Containers::get_placementID_by_name(QString name, bool *ok)
{
    foreach(Placement_Setting key, placements_map)
    {
        if(name == key.get_name()) {
            *ok = true;
            return key.get_id();
        }
    }
    *ok = false;
    return 0;
}

QStringList Setting_Containers::get_signalValues_names_list()
{
    QStringList signalValue_name_list;
    foreach(Signal_Setting key, signals_map)
    {
        signalValue_name_list.append(key.get_name());
    }
    return signalValue_name_list;
}

int Setting_Containers::get_signalID_by_name(QString name, bool *ok)
{
    foreach(Signal_Setting key, signals_map)
    {
        if(name == key.get_name()) {
            *ok = true;
            return key.get_id();
        }
    }
    *ok = false;
    return 0;
}
