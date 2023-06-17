#include "dialog_actuator_setting.h"
#include "ui_dialog_actuator_setting.h"

#include <QDebug>
#include <QMessageBox>
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

void Dialog_Actuator_Setting::fill_table_actuator()
{
    ui->tableWidget_actuators->setRowCount(0);

    foreach(int key, p_containers->actuators_map.keys())
    {
        Actuator_Setting element = p_containers->actuators_map.value(key);
        add_row_actuator(element);
    }
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

void Dialog_Actuator_Setting::on_pushButton_add_clicked()
{
    Dialog_Actuator_Edit mDialog_Actuator_edit(this, p_containers);
    mDialog_Actuator_edit.setModal(true);
    mDialog_Actuator_edit.exec();

    Actuator_Setting new_actuator;
    new_actuator = mDialog_Actuator_edit.get_actuator();

    // added new net to containers
    if(new_actuator.get_id() >= 0)
    {
        p_containers->actuators_map.insert(new_actuator.get_id(), new_actuator);
        fill_table_actuator();
    }
}

void Dialog_Actuator_Setting::on_pushButton_delete_clicked()
{
    int select_row = ui->tableWidget_actuators->currentRow();
    if(ui->tableWidget_actuators->selectedItems().isEmpty())
    {
        return;
    }

    int warning = QMessageBox::warning(0, "Warning", "Do you really want to delete line " + QString::number(select_row+1) +"?",
                                       QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(warning == QMessageBox::Yes)
    {
        delete_actuator_from_list(select_row);
        fill_table_actuator();
    }
}

void Dialog_Actuator_Setting::delete_actuator_from_list(int row)
{
    int id = ui->tableWidget_actuators->item(row, T_ID)->text().toInt();
    p_containers->actuators_map.remove(id);

}

void Dialog_Actuator_Setting::on_pushButton_save_clicked()
{
    p_containers->write_to_xml();
    close();
}


void Dialog_Actuator_Setting::on_pushButton_cancel_clicked()
{
    close();
}

void Dialog_Actuator_Setting::on_tableWidget_actuators_cellDoubleClicked(int row, int column)
{
    int id = ui->tableWidget_actuators->item(row, T_ID)->text().toInt();

    Actuator_Setting currentActuator = p_containers->actuators_map.value(id);
    Dialog_Actuator_Edit mDialog_Actuator_edit(this, p_containers);
    mDialog_Actuator_edit.set_actuator(currentActuator);
    mDialog_Actuator_edit.setModal(true);
    mDialog_Actuator_edit.exec();

    Actuator_Setting new_actuator;
    new_actuator = mDialog_Actuator_edit.get_actuator();

    // added new net to containers
    if(new_actuator.get_id() >= 0)
    {
        p_containers->actuators_map.remove(id);
        p_containers->actuators_map.insert(new_actuator.get_id(), new_actuator);
        fill_table_actuator();
    }
}



