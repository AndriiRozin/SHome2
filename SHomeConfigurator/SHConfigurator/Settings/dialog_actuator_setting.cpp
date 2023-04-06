#include "dialog_actuator_setting.h"
#include "ui_dialog_actuator_setting.h"

#include <QDebug>

#include "Settings/dialog_actuator_edit.h"

Dialog_Actuator_Setting::Dialog_Actuator_Setting(QWidget *parent, Setting_Containers * containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Actuator_Setting),
    p_containers(containers)
{
    ui->setupUi(this);
    create_table_actuator();
    fill_table_actuator();
}

Dialog_Actuator_Setting::~Dialog_Actuator_Setting()
{
    delete ui;
}

void Dialog_Actuator_Setting::create_table_actuator()
{

    int tableColumns = table_header.size() ;

    //create table column
    ui->tableWidget_actuators->setColumnCount(tableColumns);
    ui->tableWidget_actuators->setShowGrid(true);
    ui->tableWidget_actuators->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_actuators->setSelectionBehavior(QAbstractItemView::SelectRows);

    //create table headers (vertical and horizontal)
    ui->tableWidget_actuators->setHorizontalHeaderLabels(table_header);
    ui->tableWidget_actuators->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_actuators->verticalHeader()->setVisible(true);
}

void Dialog_Actuator_Setting::add_row_actuator(Actuator_Setting elem)
{
    //create new row
    ui->tableWidget_actuators->insertRow(ui->tableWidget_actuators->rowCount());

    //create new item in "0" columns with number of row
    ui->tableWidget_actuators->setItem(ui->tableWidget_actuators->rowCount()-1,T_NAME, new QTableWidgetItem(elem.get_name()));
    ui->tableWidget_actuators->setItem(ui->tableWidget_actuators->rowCount()-1,T_ID, new QTableWidgetItem(QString::number(elem.get_id())));
    ui->tableWidget_actuators->setItem(ui->tableWidget_actuators->rowCount()-1,T_DESRIPTION, new QTableWidgetItem(elem.get_description()));
    //create new items->columns in current row
}

void Dialog_Actuator_Setting::fill_table_actuator()
{
    ui->tableWidget_actuators->setRowCount(0);
    for(int i = 0; i < p_containers->actuators_map.size(); i++)
    {
        Actuator_Setting tmp = p_containers->actuators_map[i];
        add_row_actuator(tmp);
    }
}


void Dialog_Actuator_Setting::on_tableWidget_actuators_cellDoubleClicked(int row, int column)
{
    // Need to correct to edit Actuators !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     Actuator_Setting currentActuator = p_containers->actuators_map[row];
     Dialog_Actuator_Edit mDialog_Actuator_edit(this, p_containers);
     mDialog_Actuator_edit.set_actuator(currentActuator);
     mDialog_Actuator_edit.setModal(true);
     mDialog_Actuator_edit.exec();
}

