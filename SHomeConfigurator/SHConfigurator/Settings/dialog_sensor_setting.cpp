#include "dialog_sensor_setting.h"
#include "ui_dialog_sensor_setting.h"

#include <QSettings>
#include <QDebug>

Dialog_Sensor_Setting::Dialog_Sensor_Setting(QWidget *parent, Setting_Containers * containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Sensor_Setting),
    p_containers(containers)
{
    ui->setupUi(this);
    create_table_sensor();
}

Dialog_Sensor_Setting::~Dialog_Sensor_Setting()
{
    delete ui;
}

void Dialog_Sensor_Setting::create_table_sensor()
{

    int tableColumns = table_header.size() ;

    //create table column
    ui->tableWidget_sensor->setColumnCount(tableColumns);
    ui->tableWidget_sensor->setShowGrid(true);
    ui->tableWidget_sensor->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_sensor->setSelectionBehavior(QAbstractItemView::SelectRows);

    //create table headers (vertical and horizontal)
    ui->tableWidget_sensor->setHorizontalHeaderLabels(table_header);
    ui->tableWidget_sensor->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_sensor->verticalHeader()->setVisible(true);
}
