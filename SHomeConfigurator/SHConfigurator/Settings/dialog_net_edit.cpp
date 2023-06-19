#include "dialog_net_edit.h"
#include "ui_dialog_net_edit.h"

#include <QDebug>

Dialog_Net_Edit::Dialog_Net_Edit(QWidget *parent, Setting_Containers * p_containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Net_Edit),
    net(),
    p_containers(p_containers)
{
    ui->setupUi(this);
}

Dialog_Net_Edit::~Dialog_Net_Edit()
{
    delete ui;
}

void Dialog_Net_Edit::set_net(Net_Setting new_net)
{
    net = new_net;

    ui->lineEdit_name->setText(net.get_name());
    ui->lineEdit_description->setText(net.get_description());
    ui->spinBox_id->setValue(net.get_id());
}

Net_Setting  Dialog_Net_Edit::get_net()
{
    return net;
}

void Dialog_Net_Edit::on_buttonBox_Net_Edit_accepted()
{
    net.set_name(ui->lineEdit_name->text());
    net.set_id(ui->spinBox_id->value());
    net.set_description(ui->lineEdit_description->text());
}


void Dialog_Net_Edit::on_buttonBox_Net_Edit_rejected()
{
    net.set_name("");
    net.set_id(-1);  // set error status
    net.set_description("");
}



void Dialog_Net_Edit::on_spinBox_id_valueChanged(int arg1)
{

}

