#include "dialog_sensor_edit.h"
#include "ui_dialog_sensor_edit.h"

Dialog_Sensor_Edit::Dialog_Sensor_Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Sensor_Edit)
{
    ui->setupUi(this);
}

Dialog_Sensor_Edit::~Dialog_Sensor_Edit()
{
    delete ui;
}
