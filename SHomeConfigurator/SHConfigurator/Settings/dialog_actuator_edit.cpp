#include "dialog_actuator_edit.h"
#include "ui_dialog_actuator_edit.h"

Dialog_Actuator_Edit::Dialog_Actuator_Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Actuator_Edit)
{
    ui->setupUi(this);
}

Dialog_Actuator_Edit::~Dialog_Actuator_Edit()
{
    delete ui;
}
