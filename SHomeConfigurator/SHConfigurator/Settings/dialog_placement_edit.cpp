#include "dialog_placement_edit.h"
#include "ui_dialog_placement_edit.h"

Dialog_Placement_Edit::Dialog_Placement_Edit(QWidget *parent, Setting_Containers * new_containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Placement_Edit),
    p_containers(new_containers)
{
    ui->setupUi(this);
}

Dialog_Placement_Edit::~Dialog_Placement_Edit()
{
    delete ui;
}

void Dialog_Placement_Edit::set_place(Placement_Setting new_place)
{
    place = new_place;

    ui->lineEdit_name->setText(place.get_name());
    ui->lineEdit_description->setText(place.get_description());
    ui->spinBox_id->setValue(place.get_id());
}

Placement_Setting  Dialog_Placement_Edit::get_place()
{
    return place;
}

void Dialog_Placement_Edit::on_buttonBox_Placement_Edit_accepted()
{
    place.set_name(ui->lineEdit_name->text());
    place.set_id(ui->spinBox_id->value());
    place.set_description(ui->lineEdit_description->text());
}

void Dialog_Placement_Edit::on_buttonBox_Placement_Edit_rejected()
{
    place.set_name("");
    place.set_id(-1);  // set error status
    place.set_description("");
}

