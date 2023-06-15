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

    ui->lineEdit_name->setText(actuator.get_name());
    ui->lineEdit_description->setText(actuator.get_description());
    ui->spinBox_id->setValue(actuator.get_id());

    QStringList networks = p_containers->get_net_names_list();
    ui->comboBox_network->addItems(networks);
    ui->label_net_name->setText(actuator.get_network().get_name());
    ui->label_net_id->setText(QString::number(actuator.get_network().get_id()));
    ui->label_net_description->setText(actuator.get_network().get_description());

    QStringList plasements_lst = p_containers->get_placement_names_list();
    ui->comboBox_placement2->addItems(plasements_lst);
    ui->comboBox_placement1->addItems(plasements_lst);
    ui->comboBox_placement0->addItems(plasements_lst);

    ui->comboBox_placement2->setCurrentText(actuator.get_placement2().get_name());
    ui->comboBox_placement1->setCurrentText(actuator.get_placement1().get_name());
    ui->comboBox_placement0->setCurrentText(actuator.get_placement0().get_name());

    ui->comboBox_signalValue->setCurrentIndex(actuator.get_signal().get_id());

    QStringList signalValue_lst = p_containers->get_signalValues_names_list();
    ui->comboBox_signalValue->addItems(signalValue_lst);
    ui->comboBox_signalValue->setCurrentIndex(actuator.get_signal().get_id());
}

void Dialog_Actuator_Edit::on_comboBox_signalValue_currentIndexChanged(const QString &arg1)
{
    bool ok;
    int id = p_containers->get_signalID_by_name(arg1,&ok);
    if(ok) {
        Signal_Setting current = p_containers->signals_map[id];

        ui->label_name->setText(current.get_name());
        ui->label_id->setText(QString::number(current.get_id()));
        ui->label_offset->setText(QString::number(current.get_offset()));
        ui->label_scale->setText(QString::number(current.get_factor()));
        ui->label_Init->setText(QString::number(current.get_initRawValue()));
        ui->label_Error->setText(QString::number(current.get_errRawValue()));
        ui->label_Description->setText(current.get_description());
        qDebug() << __FUNCTION__ << current.get_id();
    }
}


void Dialog_Actuator_Edit::on_buttonBox_Actuator_accepted()
{
    actuator.set_name(ui->lineEdit_name->text());
    actuator.set_id(ui->spinBox_id->value());
    actuator.set_description(ui->lineEdit_description->text());
}


void Dialog_Actuator_Edit::on_buttonBox_Actuator_rejected()
{
    actuator.set_name("");
    actuator.set_id(-1);
    actuator.set_description("");
}

Actuator_Setting Dialog_Actuator_Edit::get_actuator()
{
    return actuator;
}
