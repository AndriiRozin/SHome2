#include "dialog_actuator_setting.h"
#include "ui_dialog_actuator_setting.h"

#include <QDebug>

Dialog_Actuator_Setting::Dialog_Actuator_Setting(QWidget *parent, Setting_Containers * containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Actuator_Setting),
    p_containers(containers)
{
    ui->setupUi(this);
    create_table_actuator();
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
