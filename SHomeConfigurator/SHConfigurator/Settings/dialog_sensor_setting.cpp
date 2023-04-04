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
    fill_table_sensor();

    //qDebud() << p_containers->
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

void Dialog_Sensor_Setting::add_row_sensor(Sensor_Setting elem)
{
    //create new row
    ui->tableWidget_sensor->insertRow(ui->tableWidget_sensor->rowCount());

    //create new item in "0" columns with number of row
    ui->tableWidget_sensor->setItem(ui->tableWidget_sensor->rowCount()-1,T_NAME, new QTableWidgetItem(elem.get_name()));
    ui->tableWidget_sensor->setItem(ui->tableWidget_sensor->rowCount()-1,T_ID, new QTableWidgetItem(QString::number(elem.get_id())));
    ui->tableWidget_sensor->setItem(ui->tableWidget_sensor->rowCount()-1,T_DESRIPTION, new QTableWidgetItem(elem.get_description()));
    //create new items->columns in current row
}

void Dialog_Sensor_Setting::fill_table_sensor()
{
    ui->tableWidget_sensor->setRowCount(0);
    for(int i = 0; i < p_containers->sensors_map.size(); i++)
    {
        Sensor_Setting tmp = p_containers->sensors_map[i];
        add_row_sensor(tmp);
    }
}
