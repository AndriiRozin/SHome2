#include "dialog_signal_edit.h"
#include "ui_dialog_signal_edit.h"

#include <QDialog>


Dialog_Signal_Edit::Dialog_Signal_Edit(QWidget *parent, Setting_Containers * new_containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Signal_Edit),
    current_signal(),
    p_containers(new_containers)

{
    ui->setupUi(this);
}


Dialog_Signal_Edit::~Dialog_Signal_Edit()
{
    delete ui;
}

void Dialog_Signal_Edit::fill_table_signal_edit()
{
    ui->lineEdit_name->setText(current_signal.get_name());
    ui->spinBox_id->setValue(current_signal.get_id());
    ui->lineEdit_description->setText(current_signal.get_description());
    ui->spinBox_InitRaw->setValue(current_signal.get_initRawValue());
    ui->spinBox_ErrRaw->setValue(current_signal.get_errRawValue());
    ui->doubleSpinBox_Factor->setValue(current_signal.get_factor());
    ui->doubleSpinBox_Offset->setValue(current_signal.get_offset());
    ui->doubleSpinBox_Min->setValue(current_signal.get_minValue());
    ui->doubleSpinBox_Max->setValue(current_signal.get_maxValue());
}

void Dialog_Signal_Edit::edit_signal(Signal_Setting new_signal)
{
    current_signal = new_signal;
    fill_table_signal_edit();
}

Signal_Setting  Dialog_Signal_Edit::get_signal()
{
    return current_signal;
}

void Dialog_Signal_Edit::on_buttonBox_signal_accepted()
{
    current_signal.set_name(ui->lineEdit_name->text());
    current_signal.set_id(ui->spinBox_id->value());
    current_signal.set_description(ui->lineEdit_description->text());
    current_signal.set_initRawValue(ui->spinBox_InitRaw->value());
    current_signal.set_errRawValue(ui->spinBox_ErrRaw->value());
    current_signal.set_factor(ui->doubleSpinBox_Factor->value());
    current_signal.set_offset(ui->doubleSpinBox_Offset->value());
    current_signal.set_minValue(ui->doubleSpinBox_Min->value());
    current_signal.set_maxValue(ui->doubleSpinBox_Max->value());
}


void Dialog_Signal_Edit::on_buttonBox_signal_rejected()
{
    current_signal.set_name("");
    current_signal.set_id(-1);  // set error status
    current_signal.set_description("");
}
