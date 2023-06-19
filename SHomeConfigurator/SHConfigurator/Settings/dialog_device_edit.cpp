#include "dialog_device_edit.h"
#include "ui_dialog_device_edit.h"

Dialog_Device_Edit::Dialog_Device_Edit(QWidget *parent, Setting_Containers * p_containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Device_Edit),
    device(),
    p_containers(p_containers)

{
    ui->setupUi(this);
}

Dialog_Device_Edit::~Dialog_Device_Edit()
{
    delete ui;
}

void Dialog_Device_Edit::set_device(Device_Setting new_device)
{
    device = new_device;

    ui->lineEdit_name->setText(device.get_name());
    ui->lineEdit_description->setText(device.get_description());
    ui->spinBox_id->setValue(device.get_id());
}

Device_Setting  Dialog_Device_Edit::get_device()
{
    return device;
}

void Dialog_Device_Edit::on_buttonBox_DeviceEdit_accepted()
{   device.set_name(ui->lineEdit_name->text());
    device.set_id(ui->spinBox_id->value());
    device.set_description(ui->lineEdit_description->text());
}


void Dialog_Device_Edit::on_buttonBox_DeviceEdit_rejected()
{
    device.set_name("");
    device.set_id(-1);  // set error status
    device.set_description("");
}

