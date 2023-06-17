#include "dialog_sensor_setting.h"
#include "ui_dialog_sensor_setting.h"

#include <QDebug>
#include <QMessageBox>
#include "Settings/dialog_sensor_edit.h"

Dialog_Sensor_Setting::Dialog_Sensor_Setting(QWidget *parent, Setting_Containers * containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Sensor_Setting),
    p_containers(containers)
{
    ui->setupUi(this);
    create_table_sensor();
    fill_table_sensor();
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

void Dialog_Sensor_Setting::fill_table_sensor()
{
    ui->tableWidget_sensor->setRowCount(0);

    foreach(int key, p_containers->sensors_map.keys())
    {
        Sensor_Setting element = p_containers->sensors_map.value(key);
        add_row_sensor(element);
    }
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



void Dialog_Sensor_Setting::on_pushButton_add_clicked()
{
    Dialog_Sensor_Edit mDialog_Sensor_edit(this, p_containers);
    mDialog_Sensor_edit.setModal(true);
    mDialog_Sensor_edit.exec();

    Sensor_Setting new_sensor;
    new_sensor = mDialog_Sensor_edit.get_sensor();

    // added new sensor to containers
    if(new_sensor.get_id() >= 0)
    {
        p_containers->sensors_map.insert(new_sensor.get_id(), new_sensor);
        fill_table_sensor();
    }
}

void Dialog_Sensor_Setting::on_pushButton_delete_clicked()
{
    int select_row = ui->tableWidget_sensor->currentRow();
    if(ui->tableWidget_sensor->selectedItems().isEmpty())
    {
        return;
    }

    int warning = QMessageBox::warning(0, "Warning", "Do you really want to delete line " + QString::number(select_row+1) +"?",
                                       QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(warning == QMessageBox::Yes)
    {
        delete_sensor_from_list(select_row);
        fill_table_sensor();
    }
}

void Dialog_Sensor_Setting::delete_sensor_from_list(int row)
{
    int id = ui->tableWidget_sensor->item(row, T_ID)->text().toInt();
    p_containers->sensors_map.remove(id);
}

void Dialog_Sensor_Setting::on_pushButton_save_clicked()
{
    p_containers->write_to_xml();
    close();
}


void Dialog_Sensor_Setting::on_pushButton_cancel_clicked()
{
    close();
}


void Dialog_Sensor_Setting::on_tableWidget_sensor_cellDoubleClicked(int row, int column)
{
    int id = ui->tableWidget_sensor->item(row, T_ID)->text().toInt();


    Sensor_Setting currentSensor = p_containers->sensors_map.value(id);
    Dialog_Sensor_Edit mDialog_Sensor_edit(this, p_containers);
    mDialog_Sensor_edit.set_sensor(currentSensor);
    mDialog_Sensor_edit.setModal(true);
    mDialog_Sensor_edit.exec();

    Sensor_Setting new_sensor;
    new_sensor = mDialog_Sensor_edit.get_sensor();

    // added new net to containers
    if(new_sensor.get_id() >= 0)
    {
        p_containers->sensors_map.remove(id);
        p_containers->sensors_map.insert(new_sensor.get_id(), new_sensor);
    }
}








