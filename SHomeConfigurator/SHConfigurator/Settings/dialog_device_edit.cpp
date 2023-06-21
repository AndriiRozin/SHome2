#include "dialog_device_edit.h"
#include "ui_dialog_device_edit.h"

Dialog_Device_Edit::Dialog_Device_Edit(QWidget *parent, Setting_Containers * p_containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Device_Edit),
    device(),
    p_containers(p_containers)

{
    ui->setupUi(this);
    create_table_sensors();
    create_table_actuators();
}

Dialog_Device_Edit::~Dialog_Device_Edit()
{
    delete ui;
}

void Dialog_Device_Edit::set_device(Device_Setting new_device)
{
    device = new_device;
    print_device();
    fill_table_sensors();
    fill_table_actuators();
}

Device_Setting  Dialog_Device_Edit::get_device()
{
    return device;
}

void Dialog_Device_Edit::create_table_sensors()
{
    int tableColumns = table_header.size() ;

    //create table column
    ui->tableWidget_D_sensors->setColumnCount(tableColumns);
    ui->tableWidget_D_sensors->setShowGrid(true);
    ui->tableWidget_D_sensors->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_D_sensors->setSelectionBehavior(QAbstractItemView::SelectRows);

    //create table headers (vertical and horizontal)
    ui->tableWidget_D_sensors->setHorizontalHeaderLabels(table_header);
    ui->tableWidget_D_sensors->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_D_sensors->verticalHeader()->setVisible(true);
}

void Dialog_Device_Edit::create_table_actuators()
{
    int tableColumns = table_header.size() ;

    //create table column
    ui->tableWidget_D_actuators->setColumnCount(tableColumns);
    ui->tableWidget_D_actuators->setShowGrid(true);
    ui->tableWidget_D_actuators->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_D_actuators->setSelectionBehavior(QAbstractItemView::SelectRows);

    //create table headers (vertical and horizontal)
    ui->tableWidget_D_actuators->setHorizontalHeaderLabels(table_header);
    ui->tableWidget_D_actuators->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_D_actuators->verticalHeader()->setVisible(true);
}

void Dialog_Device_Edit::fill_table_sensors()
{
    ui->tableWidget_D_sensors->setRowCount(0);

    foreach(int key, device.dev_sensor_map.keys())
    {
        //Net_Setting element =  p_containers->networks_map.value(key);
        QString name = device.dev_sensor_map.value(key);

        add_row_sensor(name, key);
    }
}

void Dialog_Device_Edit::fill_table_actuators()
{
    ui->tableWidget_D_actuators->setRowCount(0);

    foreach(int key, device.dev_actuator_map.keys())
    {
        //Net_Setting element =  p_containers->networks_map.value(key);
        QString name = device.dev_actuator_map.value(key);

        add_row_actuator(name, key);
    }
}

void Dialog_Device_Edit::add_row_sensor(QString name, int ref)
{
    //create new row
    ui->tableWidget_D_sensors->insertRow(ui->tableWidget_D_sensors->rowCount());

    //create new item in "0" columns with number of row
    ui->tableWidget_D_sensors->setItem(ui->tableWidget_D_sensors->rowCount()-1,T_NAME, new QTableWidgetItem(name));
    ui->tableWidget_D_sensors->setItem(ui->tableWidget_D_sensors->rowCount()-1,T_REF, new QTableWidgetItem(QString::number(ref)));
    //create new items->columns in current row
}

void Dialog_Device_Edit::add_row_actuator(QString name, int ref)
{
    //create new row
    ui->tableWidget_D_actuators->insertRow(ui->tableWidget_D_actuators->rowCount());

    //create new item in "0" columns with number of row
    ui->tableWidget_D_actuators->setItem(ui->tableWidget_D_actuators->rowCount()-1,T_NAME, new QTableWidgetItem(name));
    ui->tableWidget_D_actuators->setItem(ui->tableWidget_D_actuators->rowCount()-1,T_REF, new QTableWidgetItem(QString::number(ref)));
    //create new items->columns in current row
}

void Dialog_Device_Edit::print_device()
{
    ui->lineEdit_name->setText(device.get_name());
    ui->lineEdit_description->setText(device.get_description());
    ui->spinBox_id->setValue(device.get_id());
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

