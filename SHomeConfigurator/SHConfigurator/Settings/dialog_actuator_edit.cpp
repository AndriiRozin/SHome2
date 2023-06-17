#include "dialog_actuator_edit.h"
#include "ui_dialog_actuator_edit.h"

#include <QDebug>

Dialog_Actuator_Edit::Dialog_Actuator_Edit(QWidget *parent, Setting_Containers * container):
    QDialog(parent),
    ui(new Ui::Dialog_Actuator_Edit),
    actuator(),
    p_containers(container)
{
    ui->setupUi(this);    
}

Dialog_Actuator_Edit::~Dialog_Actuator_Edit()
{
    delete ui;
}

void Dialog_Actuator_Edit::set_actuator(Actuator_Setting new_actuator)
{
    actuator = new_actuator;
    init_Actuator_Edit();
    print_actuator();
}

Actuator_Setting Dialog_Actuator_Edit::get_actuator()
{
    return actuator;
}

void Dialog_Actuator_Edit::init_Actuator_Edit()
{
    // init comboboxes
    QStringList networks_lst = p_containers->get_net_names_list();
    ui->comboBox_actuator_network->addItems(networks_lst);

    QStringList plasements_lst = p_containers->get_placement_names_list();
    ui->comboBox_actuator_placement2->addItems(plasements_lst);
    ui->comboBox_actuator_placement1->addItems(plasements_lst);
    ui->comboBox_actuator_placement0->addItems(plasements_lst);

    QStringList signalValue_lst = p_containers->get_signalValues_names_list();
    ui->comboBox_actuator_signal->addItems(signalValue_lst);
}

void Dialog_Actuator_Edit::print_actuator()
{
    ui->lineEdit_actuator_name->setText(actuator.get_name());
    ui->spinBox_actuator_id->setValue(actuator.get_id());
    ui->lineEdit_actuator_description->setText(actuator.get_description());

    ui->comboBox_actuator_placement2->setCurrentText(actuator.get_placement2().get_name());
    ui->comboBox_actuator_placement1->setCurrentText(actuator.get_placement1().get_name());
    ui->comboBox_actuator_placement0->setCurrentText(actuator.get_placement0().get_name());

    ui->comboBox_actuator_signal->setCurrentText(actuator.get_signal().get_name());

    ui->comboBox_actuator_network->setCurrentText(actuator.get_network().get_name());
}

void Dialog_Actuator_Edit::on_buttonBox_actuator_accepted()
{
    actuator.set_name(ui->lineEdit_actuator_name->text());
    actuator.set_id(ui->spinBox_actuator_id->value());
    actuator.set_description(ui->lineEdit_actuator_description->text());

    bool ok;
    int placment2_id = p_containers->get_placementID_by_name(ui->comboBox_actuator_placement2->currentText(),&ok);
    if(ok) {
        Placement_Setting place2 = p_containers->placements_map.value(placment2_id);
        actuator.set_plasement2(place2);
    }

    int placment1_id = p_containers->get_placementID_by_name(ui->comboBox_actuator_placement1->currentText(),&ok);
    if(ok) {
        Placement_Setting place1 = p_containers->placements_map.value(placment1_id);
        actuator.set_plasement1(place1);
    }

    int placment0_id = p_containers->get_placementID_by_name(ui->comboBox_actuator_placement0->currentText(),&ok);
    if(ok) {
        Placement_Setting place0 = p_containers->placements_map.value(placment0_id);
        actuator.set_plasement0(place0);
    }

    int signal_id = p_containers->get_signalID_by_name(ui->comboBox_actuator_signal->currentText(),&ok);
    if(ok) {
        Signal_Setting signal = p_containers->signals_map.value(signal_id);
        actuator.set_signal(signal);
    }

    int net_id = p_containers->get_networkID_by_name(ui->comboBox_actuator_network->currentText(),&ok);
    if(ok) {
        Net_Setting net = p_containers->networks_map.value(net_id);
        actuator.set_network(net);
    }
}

void Dialog_Actuator_Edit::on_comboBox_actuator_network_currentTextChanged(const QString &arg1)
{
    bool ok;
    int net_id = p_containers->get_networkID_by_name(arg1,&ok);
    if(ok) {
        Net_Setting net = p_containers->networks_map.value(net_id);
        ui->label_anet_id->setText(QString::number(net.get_id()));
        ui->label_anet_description->setText(net.get_description());
    }
}

void Dialog_Actuator_Edit::on_comboBox_actuator_signal_currentTextChanged(const QString &arg1)
{
    bool ok;
    int signal_id = p_containers->get_signalID_by_name(arg1,&ok);
    if(ok) {
        Signal_Setting signal = p_containers->signals_map.value(signal_id);
        ui->label_as_id->setText(QString::number(signal.get_id()));
        ui->label_as_description->setText(signal.get_description());
    }
}


void Dialog_Actuator_Edit::on_comboBox_actuator_placement2_currentTextChanged(const QString &arg1)
{
    bool ok;
    int placment2_id = p_containers->get_placementID_by_name(arg1,&ok);
    if(ok) {
        Placement_Setting place2 = p_containers->placements_map.value(placment2_id);
        ui->label_a_placement2_id->setText(QString::number(place2.get_id()));
        ui->label_a_placement2_description->setText(place2.get_description());
    }
}


void Dialog_Actuator_Edit::on_comboBox_actuator_placement1_currentTextChanged(const QString &arg1)
{
    bool ok;
    int placment1_id = p_containers->get_placementID_by_name(arg1,&ok);
    if(ok) {
        Placement_Setting place1 = p_containers->placements_map.value(placment1_id);
        ui->label_a_placement1_id->setText(QString::number(place1.get_id()));
        ui->label_a_placement1_description->setText(place1.get_description());
    }
}


void Dialog_Actuator_Edit::on_comboBox_actuator_placement0_currentTextChanged(const QString &arg1)
{
    bool ok;
    int placment0_id = p_containers->get_placementID_by_name(arg1,&ok);
    if(ok) {
        Placement_Setting place0 = p_containers->placements_map.value(placment0_id);
        ui->label_a_placement0_id->setText(QString::number(place0.get_id()));
        ui->label_a_placement0_description->setText(place0.get_description());
    }
}

