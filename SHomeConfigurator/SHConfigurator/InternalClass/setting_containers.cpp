#include "setting_containers.h"

#include <QSettings>
#include <QDebug>

Setting_Containers::Setting_Containers():
    networks_map(),
    placements_map(),
    signals_map(),
    actuators_map(),
    sensors_map()
{
    xml_filename = read_xml_filename();
    read_from_xml();
}

QString Setting_Containers::read_xml_filename()
{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    xml_filename = settings.value("ConfigXML").toString();
    settings.endGroup();
    return xml_filename;
}

void Setting_Containers::write_to_xml()
{
    QDomDocument document;

    QDomProcessingInstruction instr = document.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");
    document.appendChild(instr);

    QDomElement root = document.createElement("ENVIRONMENT");
    document.appendChild(root);

    create_xml_nets(document, root);
    create_xml_places(document, root);
    create_xml_signals(document, root);
    create_xml_actuators(document, root);
    create_xml_sensors(document, root);

    QFile xmlFile(xml_filename);
    if (!xmlFile.open(QFile::WriteOnly | QFile::Text ))
    {
        qDebug() << "Open the file for writing failed";
    }
    else {
        QTextStream xmlContent(&xmlFile);
        xmlContent << document.toString();
        xmlFile.close();
    }
}

void Setting_Containers::create_xml_nets(QDomDocument document_xml, QDomElement root)
{
    QDomElement networks_tag = document_xml.createElement("NETWORKS");
    root.appendChild(networks_tag);

    foreach(int key, networks_map.keys())
    {
        Net_Setting myNet = networks_map.value(key);

        QDomElement net_tag = document_xml.createElement("NET");
        networks_tag.appendChild(net_tag);

        QDomElement short_name_tag = document_xml.createElement("SHORT-NAME");
        net_tag.appendChild(short_name_tag);
        QDomText textName = document_xml.createTextNode(myNet.get_name());
        short_name_tag.appendChild(textName);

        QDomElement id_tag = document_xml.createElement("ID");
        net_tag.appendChild(id_tag);
        QDomText id_text = document_xml.createTextNode(QString::number(myNet.get_id()));
        id_tag.appendChild(id_text);

        QDomElement description_tag = document_xml.createElement("DESCRIPTION");
        net_tag.appendChild(description_tag);
        QDomText description_text = document_xml.createTextNode(myNet.get_description());
        description_tag.appendChild(description_text);
    }
}

void Setting_Containers::create_xml_places(QDomDocument document_xml, QDomElement root)
{
    QDomElement placements_tag = document_xml.createElement("PLACEMENTS");
    root.appendChild(placements_tag);

    foreach(int key, placements_map.keys())
    {
        Placement_Setting myPlacement = placements_map.value(key);

        QDomElement place_tag = document_xml.createElement("PLACE");
        placements_tag.appendChild(place_tag);

        QDomElement short_name_tag = document_xml.createElement("SHORT-NAME");
        place_tag.appendChild(short_name_tag);
        QDomText name_text = document_xml.createTextNode(myPlacement.get_name());
        short_name_tag.appendChild(name_text);

        QDomElement id_tag = document_xml.createElement("ID");
        place_tag.appendChild(id_tag);
        QDomText id_text = document_xml.createTextNode(QString::number(myPlacement.get_id()));
        id_tag.appendChild(id_text);

        QDomElement description_tag = document_xml.createElement("DESCRIPTION");
        place_tag.appendChild(description_tag);
        QDomText description_text = document_xml.createTextNode(myPlacement.get_description());
        description_tag.appendChild(description_text);
    }
}

void Setting_Containers::create_xml_signals(QDomDocument document_xml, QDomElement root)
{
    QDomElement signals_tag = document_xml.createElement("SIGNALS");
    root.appendChild(signals_tag);

    foreach(int key, signals_map.keys())
    {
        Signal_Setting mySig = signals_map.value(key);

        QDomElement signal_tag = document_xml.createElement("SIGNAL");
        signals_tag.appendChild(signal_tag);

        QDomElement short_name_tag = document_xml.createElement("SHORT-NAME");
        signal_tag.appendChild(short_name_tag);
        QDomText name_text = document_xml.createTextNode(mySig.get_name());
        short_name_tag.appendChild(name_text);

        QDomElement id_tag = document_xml.createElement("ID");
        signal_tag.appendChild(id_tag);
        QDomText id_text = document_xml.createTextNode(QString::number(mySig.get_id()));
        id_tag.appendChild(id_text);

        QDomElement description_tag = document_xml.createElement("DESCRIPTION");
        signal_tag.appendChild(description_tag);
        QDomText description_text = document_xml.createTextNode(mySig.get_description());
        description_tag.appendChild(description_text);

        QDomElement offset_tag = document_xml.createElement("OFFSET");
        signal_tag.appendChild(offset_tag);
        QDomText offset_text = document_xml.createTextNode(QString::number(mySig.get_offset()));
        offset_tag.appendChild(offset_text);

        QDomElement factor_tag = document_xml.createElement("FACTOR");
        signal_tag.appendChild(factor_tag);
        QDomText factor_text = document_xml.createTextNode(QString::number(mySig.get_factor()));
        factor_tag.appendChild(factor_text);

        QDomElement init_tag = document_xml.createElement("INIT-VALUE");
        signal_tag.appendChild(init_tag);
        QDomText init_text = document_xml.createTextNode(QString::number(mySig.get_initRawValue()));
        init_tag.appendChild(init_text);

        QDomElement max_tag = document_xml.createElement("MAX-VALUE");
        signal_tag.appendChild(max_tag);
        QDomText max_text = document_xml.createTextNode(QString::number(mySig.get_maxValue()));
        max_tag.appendChild(max_text);

        QDomElement min_tag = document_xml.createElement("MIN-VALUE");
        signal_tag.appendChild(min_tag);
        QDomText min_text = document_xml.createTextNode(QString::number(mySig.get_minValue()));
        min_tag.appendChild(min_text);

        QDomElement error_tag = document_xml.createElement("ERROR-VALUE");
        signal_tag.appendChild(error_tag);
        QDomText error_text = document_xml.createTextNode(QString::number(mySig.get_errRawValue()));
        error_tag.appendChild(error_text);
    }
}

void Setting_Containers::create_xml_actuators(QDomDocument document_xml, QDomElement root)
{
    QDomElement actuators_tag = document_xml.createElement("ACTUATORS");
    root.appendChild(actuators_tag);

    foreach(int key, actuators_map.keys())
    {
        Actuator_Setting myActuator = actuators_map.value(key);

        QDomElement actuator_tag = document_xml.createElement("ACTUATOR");
        actuators_tag.appendChild(actuator_tag);

        QDomElement short_name_tag = document_xml.createElement("SHORT-NAME");
        actuator_tag.appendChild(short_name_tag);
        QDomText name_text = document_xml.createTextNode(myActuator.get_name());
        short_name_tag.appendChild(name_text);

        QDomElement id_tag = document_xml.createElement("ID");
        actuator_tag.appendChild(id_tag);
        QDomText id_text = document_xml.createTextNode(QString::number(myActuator.get_id()));
        id_tag.appendChild(id_text);

        QDomElement description_tag = document_xml.createElement("DESCRIPTION");
        actuator_tag.appendChild(description_tag);
        QDomText description_text = document_xml.createTextNode(myActuator.get_description());
        description_tag.appendChild(description_text);

        QDomElement placement2_tag = document_xml.createElement("PLACEMENT-2");
        actuator_tag.appendChild(placement2_tag);
        QDomText placement2_text = document_xml.createTextNode(QString::number(myActuator.get_placement2().get_id()));
        placement2_tag.appendChild(placement2_text);

        QDomElement placement1_tag = document_xml.createElement("PLACEMENT-1");
        actuator_tag.appendChild(placement1_tag);
        QDomText placement1_text = document_xml.createTextNode(QString::number(myActuator.get_placement1().get_id()));
        placement1_tag.appendChild(placement1_text);

        QDomElement placement0_tag = document_xml.createElement("PLACEMENT-0");
        actuator_tag.appendChild(placement0_tag);
        QDomText placement0_text = document_xml.createTextNode(QString::number(myActuator.get_placement0().get_id()));
        placement0_tag.appendChild(placement0_text);

        QDomElement signal_id_tag = document_xml.createElement("REF-SIGNAL-ID");
        actuator_tag.appendChild(signal_id_tag);
        QDomText signal_id_text = document_xml.createTextNode(QString::number( myActuator.get_signal().get_id()));
        signal_id_tag.appendChild(signal_id_text);

        QDomElement net_id_tag = document_xml.createElement("REF-NET-ID");
        actuator_tag.appendChild(net_id_tag);
        QDomText net_id_text = document_xml.createTextNode(QString::number( myActuator.get_network().get_id()));
        net_id_tag.appendChild(net_id_text);
    }
}

void Setting_Containers::create_xml_sensors(QDomDocument document_xml, QDomElement root)
{
    QDomElement sensors_tag = document_xml.createElement("SENSORS");
    root.appendChild(sensors_tag);

    foreach(int key, sensors_map.keys())
    {
        Sensor_Setting mySensor = sensors_map[key];

        QDomElement sensor_tag = document_xml.createElement("SENSOR");
        sensors_tag.appendChild(sensor_tag);

        QDomElement short_name_tag = document_xml.createElement("SHORT-NAME");
        sensor_tag.appendChild(short_name_tag);
        QDomText name_text = document_xml.createTextNode( mySensor.get_name());
        short_name_tag.appendChild(name_text);

        QDomElement id_tag = document_xml.createElement("ID");
        sensor_tag.appendChild(id_tag);
        QDomText id_text = document_xml.createTextNode(QString::number(mySensor.get_id()));
        id_tag.appendChild(id_text);

        QDomElement description_tag = document_xml.createElement("DESCRIPTION");
        sensor_tag.appendChild(description_tag);
        QDomText description_text = document_xml.createTextNode(mySensor.get_description());
        description_tag.appendChild(description_text);

        QDomElement placement2_tag = document_xml.createElement("PLACEMENT-2");
        sensor_tag.appendChild(placement2_tag);
        QDomText placement2_text = document_xml.createTextNode(QString::number(mySensor.get_placement2().get_id()));
        placement2_tag.appendChild(placement2_text);

        QDomElement placement1_tag = document_xml.createElement("PLACEMENT-1");
        sensor_tag.appendChild(placement1_tag);
        QDomText placement1_text = document_xml.createTextNode(QString::number(mySensor.get_placement1().get_id()));
        placement1_tag.appendChild(placement1_text);

        QDomElement placement0_tag = document_xml.createElement("PLACEMENT-0");
        sensor_tag.appendChild(placement0_tag);
        QDomText placement0_text = document_xml.createTextNode(QString::number(mySensor.get_placement0().get_id()));
        placement0_tag.appendChild(placement0_text);

        QDomElement signal_id_tag = document_xml.createElement("REF-SIGNAL-ID");
        sensor_tag.appendChild(signal_id_tag);
        QDomText signal_id_text = document_xml.createTextNode(QString::number( mySensor.get_signal().get_id()));
        signal_id_tag.appendChild(signal_id_text);

        QDomElement net_id_tag = document_xml.createElement("REF-NET-ID");
        sensor_tag.appendChild(net_id_tag);
        QDomText net_id_text = document_xml.createTextNode(QString::number( mySensor.get_network().get_id()));
        net_id_tag.appendChild(net_id_text);
    }
}

void Setting_Containers::read_from_xml()
{
    QDomDocument documentXML;

    // read xml file
    QFile xmlFile(xml_filename);
    if (!xmlFile.open(QIODevice::ReadOnly | QFile::Text ))
    {
        qDebug() << "Failed to open the file for reading.";
    }
    documentXML.setContent(&xmlFile);
    xmlFile.close();

    parsing_xml(documentXML);
    qDebug() << "Reading finished" ;
}

void Setting_Containers::parsing_xml(QDomDocument document_xml)
{
    QDomElement root = document_xml.documentElement();
    QDomElement elements = root.firstChild().toElement();
    QDomElement element;
    QDomElement property;

    qDebug() << __FUNCTION__ << "networks_map.clear" << networks_map.size();

    while(elements.isNull() == false)
    {
        element = elements.firstChild().toElement();
        while(!element.isNull())
        {
            if(element.tagName() == "NET")
            {
                property = element.firstChild().toElement();
                parsing_xml_net(property);
                element = element.nextSibling().toElement();
            }
            else if(element.tagName() == "PLACE")
            {
                property = element.firstChild().toElement();
                parsing_xml_place(property);
                element = element.nextSibling().toElement();
            }
            else if(element.tagName() == "SIGNAL")
            {
                property = element.firstChild().toElement();
                parsing_xml_signal(property);
                element = element.nextSibling().toElement();
            }
            else if(element.tagName() == "ACTUATOR")
            {
                property = element.firstChild().toElement();
                parsing_xml_actuator(property);
                element = element.nextSibling().toElement();
            }
            else if(element.tagName() == "SENSOR")
            {
                property = element.firstChild().toElement();
                parsing_xml_sensor(property);
                element = element.nextSibling().toElement();
            }
            else
            {
                element = element.nextSibling().toElement();
            }
        }
        elements = elements.nextSibling().toElement();
    }
}

void Setting_Containers::parsing_xml_net(QDomElement property)
{
    QString name;
    int id;
    QString description;

    while(!property.isNull())
    {
        if(property.tagName() == "SHORT-NAME")
        {
            name = property.firstChild().toText().data();
        }
        if(property.tagName() == "ID")
        {
            id = (property.firstChild().toText().data()).toInt();
        }
        if(property.tagName() == "DESCRIPTION")
        {
            description = property.firstChild().toText().data();
        }
        property = property.nextSibling().toElement();
    }
    Net_Setting new_element(name,id,description);
    networks_map.insert(id, new_element);
}

void Setting_Containers::parsing_xml_place(QDomElement property)
{
    QString name;
    int id;
    QString description;

    while(!property.isNull())
    {
        if(property.tagName() == "SHORT-NAME")
        {
            name = property.firstChild().toText().data();
        }
        if(property.tagName() == "ID")
        {
            id = (property.firstChild().toText().data()).toInt();
        }
        if(property.tagName() == "DESCRIPTION")
        {
            description = property.firstChild().toText().data();
        }
        property = property.nextSibling().toElement();
    }
    Placement_Setting new_element(name,id,description);
    placements_map.insert(id, new_element);
}

void Setting_Containers::parsing_xml_signal(QDomElement property)
{
    QString  name = "";
    int      id = 0;
    QString  description = "";
    double   offset = 0.0;
    double   factor = 0.0;
    int      init = 0;
    int      error = 0;
    double   max = 0.0;
    double   min = 0.0;

    while(!property.isNull())
    {
        if(property.tagName() == "SHORT-NAME")
        {
            name = property.firstChild().toText().data();
        }
        if(property.tagName() == "ID")
        {
            id = (property.firstChild().toText().data()).toInt();
        }
        if(property.tagName() == "DESCRIPTION")
        {
            description = property.firstChild().toText().data();
        }
        if(property.tagName() == "OFFSET")
        {
            offset = property.firstChild().toText().data().toDouble();
        }
        if(property.tagName() == "FACTOR")
        {
            factor = property.firstChild().toText().data().toDouble();
        }
        if(property.tagName() == "INIT-VALUE")
        {
            init = property.firstChild().toText().data().toInt();
        }
        if(property.tagName() == "MAX-VALUE")
        {
            max = property.firstChild().toText().data().toDouble();
        }
        if(property.tagName() == "MIN-VALUE")
        {
            min = property.firstChild().toText().data().toDouble();
        }
        if(property.tagName() == "ERROR-VALUE")
        {
            error = property.firstChild().toText().data().toInt();
        }
        property = property.nextSibling().toElement();
    }
    Signal_Setting new_element;
    new_element.set_name(name);
    new_element.set_id(id);
    new_element.set_description(description);
    new_element.set_offset(offset);
    new_element.set_factor(factor);
    new_element.set_initRawValue(init);
    new_element.set_maxValue(max);
    new_element.set_minValue(min);
    new_element.set_errRawValue(error);

    signals_map.insert(id, new_element);
}

void Setting_Containers::parsing_xml_actuator(QDomElement property)
{
    QString name;
    int id = 0;
    QString description;
    int pl2_id = 0;
    int pl1_id = 0;
    int pl0_id = 0;
    int net_id = 0;
    int sig_id = 0;

    while(!property.isNull())
    {
        if(property.tagName() == "SHORT-NAME")
        {
            name = property.firstChild().toText().data();
        }
        if(property.tagName() == "ID")
        {
            id = (property.firstChild().toText().data()).toInt();
        }
        if(property.tagName() == "DESCRIPTION")
        {
            description = property.firstChild().toText().data();
        }
        if(property.tagName() == "PLACEMENT-2")
        {
            pl2_id = property.firstChild().toText().data().toInt();
        }
        if(property.tagName() == "PLACEMENT-1")
        {
            pl1_id = property.firstChild().toText().data().toInt();
        }
        if(property.tagName() == "PLACEMENT-0")
        {
            pl0_id = property.firstChild().toText().data().toInt();
        }
        if(property.tagName() == "REF-NET-ID")
        {
            net_id = property.firstChild().toText().data().toInt();
        }
        if(property.tagName() == "REF-SIGNAL-ID")
        {
            sig_id = property.firstChild().toText().data().toInt();
        }
        property = property.nextSibling().toElement();
    }

    Actuator_Setting new_element;
    new_element.set_name(name);
    new_element.set_id(id);
    new_element.set_description(description);
    new_element.set_plasement2(placements_map.value(pl2_id));
    new_element.set_plasement1(placements_map.value(pl1_id));
    new_element.set_plasement0(placements_map.value(pl0_id));
    new_element.set_network(networks_map.value(net_id));
    new_element.set_signal(signals_map.value(sig_id));
    actuators_map.insert(id, new_element);
}

void Setting_Containers::parsing_xml_sensor(QDomElement property)
{
    QString name;
    int id = 0;
    QString description;
    int pl2_id = 0;
    int pl1_id = 0;
    int pl0_id = 0;
    int net_id = 0;
    int sig_id = 0;

    while(!property.isNull())
    {
        if(property.tagName() == "SHORT-NAME")
        {
            name = property.firstChild().toText().data();
        }
        if(property.tagName() == "ID")
        {
            id = (property.firstChild().toText().data()).toInt();
        }
        if(property.tagName() == "DESCRIPTION")
        {
            description = property.firstChild().toText().data();
        }
        if(property.tagName() == "PLACEMENT-2")
        {
            pl2_id = property.firstChild().toText().data().toInt();
        }
        if(property.tagName() == "PLACEMENT-1")
        {
            pl1_id = property.firstChild().toText().data().toInt();
        }
        if(property.tagName() == "PLACEMENT-0")
        {
            pl0_id = property.firstChild().toText().data().toInt();
        }
        if(property.tagName() == "REF-NET-ID")
        {
            net_id = property.firstChild().toText().data().toInt();
        }
        if(property.tagName() == "REF-SIGNAL-ID")
        {
            sig_id = property.firstChild().toText().data().toInt();
        }
        property = property.nextSibling().toElement();
    }

    Sensor_Setting new_element;
    new_element.set_name(name);
    new_element.set_id(id);
    new_element.set_description(description);
    new_element.set_plasement2(placements_map.value(pl2_id));
    new_element.set_plasement1(placements_map.value(pl1_id));
    new_element.set_plasement0(placements_map.value(pl0_id));
    new_element.set_network(networks_map.value(net_id));
    new_element.set_signal(signals_map.value(sig_id));

    sensors_map.insert(id, new_element);
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
