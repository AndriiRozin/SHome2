#include "dialog_sensor_edit.h"
#include "ui_dialog_sensor_edit.h"

#include <QDebug>

Dialog_Sensor_Edit::Dialog_Sensor_Edit(QWidget *parent, Setting_Containers * containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Sensor_Edit),
    sensor(),
    p_containers(containers)
{
    ui->setupUi(this);
}

Dialog_Sensor_Edit::~Dialog_Sensor_Edit()
{
    delete ui;
}

void Dialog_Sensor_Edit::set_sensor(Sensor_Setting new_sensor)
{
    sensor = new_sensor;
    init_Sensor_Edit();
    print_sensor();
}

Sensor_Setting  Dialog_Sensor_Edit::get_sensor()
{
    return sensor;
}

void Dialog_Sensor_Edit::init_Sensor_Edit()
{
    // init comboboxes
    QStringList networks_lst = p_containers->get_net_names_list();
    ui->comboBox_sensor_network->addItems(networks_lst);

    QStringList plasements_lst = p_containers->get_placement_names_list();
    ui->comboBox_sensor_placement2->addItems(plasements_lst);
    ui->comboBox_sensor_placement1->addItems(plasements_lst);
    ui->comboBox_sensor_placement0->addItems(plasements_lst);

    QStringList signalValue_lst = p_containers->get_signalValues_names_list();
    ui->comboBox_sensor_signal->addItems(signalValue_lst);
}

void Dialog_Sensor_Edit::print_sensor()
{
    ui->lineEdit_sensor_name->setText(sensor.get_name());    
    ui->spinBox_sensor_id->setValue(sensor.get_id());
    ui->lineEdit_sensor_description->setText(sensor.get_description());

    ui->comboBox_sensor_placement2->setCurrentText(sensor.get_placement2().get_name());
    ui->comboBox_sensor_placement1->setCurrentText(sensor.get_placement1().get_name());
    ui->comboBox_sensor_placement0->setCurrentText(sensor.get_placement0().get_name());

    ui->comboBox_sensor_signal->setCurrentText(sensor.get_signal().get_name());

    ui->comboBox_sensor_network->setCurrentText(sensor.get_network().get_name());
}



void Dialog_Sensor_Edit::on_buttonBox_sensor_accepted()
{
    sensor.set_name(ui->lineEdit_sensor_name->text());
    sensor.set_id(ui->spinBox_sensor_id->value());
    sensor.set_description(ui->lineEdit_sensor_description->text());

    bool ok;
    int placment2_id = p_containers->get_placementID_by_name(ui->comboBox_sensor_placement2->currentText(),&ok);
    if(ok) {
        Placement_Setting place2 = p_containers->placements_map.value(placment2_id);
        sensor.set_plasement2(place2);
    }

    int placment1_id = p_containers->get_placementID_by_name(ui->comboBox_sensor_placement1->currentText(),&ok);
    if(ok) {
        Placement_Setting place1 = p_containers->placements_map.value(placment1_id);
        sensor.set_plasement1(place1);
    }

    int placment0_id = p_containers->get_placementID_by_name(ui->comboBox_sensor_placement0->currentText(),&ok);
    if(ok) {
        Placement_Setting place0 = p_containers->placements_map.value(placment0_id);
        sensor.set_plasement0(place0);
    }

    int signal_id = p_containers->get_signalID_by_name(ui->comboBox_sensor_signal->currentText(),&ok);
    if(ok) {
        Signal_Setting signal = p_containers->signals_map.value(signal_id);
        sensor.set_signal(signal);
    }

    int net_id = p_containers->get_networkID_by_name(ui->comboBox_sensor_network->currentText(),&ok);
    if(ok) {
        Net_Setting net = p_containers->networks_map.value(net_id);
        sensor.set_network(net);
    }
}

void Dialog_Sensor_Edit::on_comboBox_sensor_network_currentTextChanged(const QString &arg1)
{
    bool ok;
    int net_id = p_containers->get_networkID_by_name(arg1,&ok);
    if(ok) {
        Net_Setting net = p_containers->networks_map.value(net_id);
        ui->label_snet_id->setText(QString::number(net.get_id()));
        ui->label_snet_description->setText(net.get_description());
    }
}

void Dialog_Sensor_Edit::on_comboBox_sensor_signal_currentTextChanged(const QString &arg1)
{
    bool ok;
    int signal_id = p_containers->get_signalID_by_name(arg1,&ok);
    if(ok) {
        Signal_Setting signal = p_containers->signals_map.value(signal_id);
        ui->label_ss_id->setText(QString::number(signal.get_id()));
        ui->label_ss_description->setText(signal.get_description());
    }
}


void Dialog_Sensor_Edit::on_comboBox_sensor_placement2_currentTextChanged(const QString &arg1)
{
    bool ok;
    int placment2_id = p_containers->get_placementID_by_name(arg1,&ok);
    if(ok) {
        Placement_Setting place2 = p_containers->placements_map.value(placment2_id);
        ui->label_s_placement2_id->setText(QString::number(place2.get_id()));
        ui->label_s_placement2_description->setText(place2.get_description());
    }
}


void Dialog_Sensor_Edit::on_comboBox_sensor_placement1_currentTextChanged(const QString &arg1)
{
    bool ok;
    int placment1_id = p_containers->get_placementID_by_name(arg1,&ok);
    if(ok) {
        Placement_Setting place1 = p_containers->placements_map.value(placment1_id);
        ui->label_s_placement1_id->setText(QString::number(place1.get_id()));
        ui->label_s_placement1_description->setText(place1.get_description());
    }
}


void Dialog_Sensor_Edit::on_comboBox_sensor_placement0_currentTextChanged(const QString &arg1)
{
    bool ok;
    int placment0_id = p_containers->get_placementID_by_name(arg1,&ok);
    if(ok) {
        Placement_Setting place0 = p_containers->placements_map.value(placment0_id);
        ui->label_s_placement0_id->setText(QString::number(place0.get_id()));
        ui->label_s_placement0_description->setText(place0.get_description());
    }

}




void Dialog_Sensor_Edit::on_buttonBox_sensor_rejected()
{



}














































