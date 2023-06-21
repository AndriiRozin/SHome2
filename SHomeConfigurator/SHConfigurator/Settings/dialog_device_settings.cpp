#include "dialog_device_settings.h"
#include "ui_dialog_device_settings.h"

#include <QDebug>
#include <QMessageBox>
#include "Settings/dialog_device_edit.h"

Dialog_Device_Settings::Dialog_Device_Settings(QWidget *parent, Setting_Containers * p_containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Device_Settings),
    p_containers(p_containers)
{
    ui->setupUi(this);
    create_table_device();
    fill_table_device();
}

Dialog_Device_Settings::~Dialog_Device_Settings()
{
    delete ui;
}

void Dialog_Device_Settings::create_table_device()
{
    int tableColumns = table_header.size() ;

    //create table column
    ui->tableWidget_device->setColumnCount(tableColumns);
    ui->tableWidget_device->setShowGrid(true);
    ui->tableWidget_device->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_device->setSelectionBehavior(QAbstractItemView::SelectRows);

    //create table headers (vertical and horizontal)
    ui->tableWidget_device->setHorizontalHeaderLabels(table_header);
    ui->tableWidget_device->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_device->verticalHeader()->setVisible(true);
}

void Dialog_Device_Settings::fill_table_device()
{
    ui->tableWidget_device->setRowCount(0);

    foreach(int key, p_containers->devices_map.keys())
    {
        Device_Setting element =  p_containers->devices_map.value(key);
        add_row_device(element);
    }
}

void Dialog_Device_Settings::add_row_device(Device_Setting elem)
{
    //create new row
    ui->tableWidget_device->insertRow(ui->tableWidget_device->rowCount());

    //create new item in "0" columns with number of row
    ui->tableWidget_device->setItem(ui->tableWidget_device->rowCount()-1,T_NAME, new QTableWidgetItem(elem.get_name()));
    ui->tableWidget_device->setItem(ui->tableWidget_device->rowCount()-1,T_ID, new QTableWidgetItem(QString::number(elem.get_id())));
    ui->tableWidget_device->setItem(ui->tableWidget_device->rowCount()-1,T_DESCRIPTION, new QTableWidgetItem(elem.get_description()));
    //create new items->columns in current row
}

void Dialog_Device_Settings::on_pushButton_Add_clicked()
{
    Dialog_Device_Edit mDialog_Device_edit(this, p_containers);
    mDialog_Device_edit.setModal(true);
    mDialog_Device_edit.exec();

    Device_Setting new_device;
    new_device = mDialog_Device_edit.get_device();

    // added new device to containers
    if(new_device.get_id() >= 0)
    {
        p_containers->devices_map.insert(new_device.get_id(), new_device);
        fill_table_device();
    }
}


void Dialog_Device_Settings::on_pushButton_Delete_clicked()
{
    int select_row = ui->tableWidget_device->currentRow();
    if(ui->tableWidget_device->selectedItems().isEmpty())
    {
        return;
    }

    int warning = QMessageBox::warning(0, "Warning", "Do you really want to delete line " + QString::number(select_row+1) +"?",
                                       QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(warning == QMessageBox::Yes)
    {
        delete_device_from_list(select_row);
        fill_table_device();
    }
}

void Dialog_Device_Settings::delete_device_from_list(int row)
{
    int id = ui->tableWidget_device->item(row, T_ID)->text().toInt();
    p_containers->devices_map.remove(id);
}

void Dialog_Device_Settings::on_pushButton_Save_clicked()
{
    qDebug() << __FUNCTION__;
    p_containers->write_to_xml();
    close();
}

void Dialog_Device_Settings::on_pushButton_Cancel_clicked()
{
    close();
}

void Dialog_Device_Settings::on_tableWidget_device_cellDoubleClicked(int row, int column)
{
    int id = ui->tableWidget_device->item(row, T_ID)->text().toInt();

    Device_Setting currentDevice = p_containers->devices_map.value(id);
    Dialog_Device_Edit mDialog_Device_edit(this, p_containers);
    mDialog_Device_edit.set_device(currentDevice);
    mDialog_Device_edit.setModal(true);
    mDialog_Device_edit.exec();

    Device_Setting new_device;
    new_device = mDialog_Device_edit.get_device();

    // added new device to containers
    if(new_device.get_id() >= 0)
    {
        p_containers->devices_map.remove(id);
        p_containers->devices_map.insert(new_device.get_id(), new_device);
        fill_table_device();
    }
}

