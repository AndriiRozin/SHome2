#include "dialog_net_setting.h"
#include "ui_dialog_net_setting.h"

#include <QDebug>
#include <QMessageBox>
#include "Settings/dialog_net_edit.h"

Dialog_net_setting::Dialog_net_setting(QWidget *parent, Setting_Containers *containers) :
    QDialog(parent),
    ui(new Ui::Dialog_net_setting),
    p_containers(containers)
{
    ui->setupUi(this);
    create_table_net();
    fill_table_net();
}

Dialog_net_setting::~Dialog_net_setting()
{
    delete ui;
}

void Dialog_net_setting::create_table_net()
{
    int tableColumns = table_header.size() ;

    //create table column
    ui->tableWidget_net->setColumnCount(tableColumns);
    ui->tableWidget_net->setShowGrid(true);
    ui->tableWidget_net->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_net->setSelectionBehavior(QAbstractItemView::SelectRows);

    //create table headers (vertical and horizontal)
    ui->tableWidget_net->setHorizontalHeaderLabels(table_header);
    ui->tableWidget_net->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_net->verticalHeader()->setVisible(true);
}

void Dialog_net_setting::fill_table_net()
{
    ui->tableWidget_net->setRowCount(0);

    foreach(int key, p_containers->networks_map.keys())
    {
        Net_Setting element =  p_containers->networks_map.value(key);
        add_row_net(element);
    }
}

void Dialog_net_setting::add_row_net(Net_Setting elem)
{
    //create new row
    ui->tableWidget_net->insertRow(ui->tableWidget_net->rowCount());

    //create new item in "0" columns with number of row
    ui->tableWidget_net->setItem(ui->tableWidget_net->rowCount()-1,T_NAME, new QTableWidgetItem(elem.get_name()));
    ui->tableWidget_net->setItem(ui->tableWidget_net->rowCount()-1,T_ID, new QTableWidgetItem(QString::number(elem.get_id())));
    ui->tableWidget_net->setItem(ui->tableWidget_net->rowCount()-1,T_DESCRIPTION, new QTableWidgetItem(elem.get_description()));
    //create new items->columns in current row
}

void Dialog_net_setting::on_pushButton_add_clicked()
{
    Dialog_Net_Edit mDialog_Net_edit(this, p_containers);
    mDialog_Net_edit.setModal(true);
    mDialog_Net_edit.exec();

    Net_Setting new_net;
    new_net = mDialog_Net_edit.get_net();

    // added new net to containers
    if(new_net.get_id() >= 0)
    {
        p_containers->networks_map.insert(new_net.get_id(), new_net);
        fill_table_net();
    }
}

void Dialog_net_setting::on_pushButton_delete_clicked()
{
    int select_row = ui->tableWidget_net->currentRow();
    if(ui->tableWidget_net->selectedItems().isEmpty())
    {
        return;
    }

    int warning = QMessageBox::warning(0, "Warning", "Do you really want to delete line " + QString::number(select_row+1) +"?",
                                       QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(warning == QMessageBox::Yes)
    {
        delete_net_from_list(select_row);
        fill_table_net();
    }
}

void Dialog_net_setting::delete_net_from_list(int row)
{
    int id = ui->tableWidget_net->item(row, T_ID)->text().toInt();
    p_containers->networks_map.remove(id);
}

void Dialog_net_setting::on_pushButton_save_clicked()
{
    p_containers->write_to_xml();
    close();
}

void Dialog_net_setting::on_pushButton_cancel_clicked()
{
    close();
}

void Dialog_net_setting::on_tableWidget_net_cellDoubleClicked(int row, int column)
{
    int id = ui->tableWidget_net->item(row, T_ID)->text().toInt();

    Net_Setting currentNet = p_containers->networks_map.value(id);
    Dialog_Net_Edit mDialog_Net_edit(this, p_containers);
    mDialog_Net_edit.set_net(currentNet);
    mDialog_Net_edit.setModal(true);
    mDialog_Net_edit.exec();

    Net_Setting new_net;
    new_net = mDialog_Net_edit.get_net();

    // added new net to containers
    if(new_net.get_id() >= 0)
    {
        p_containers->networks_map.remove(id);
        p_containers->networks_map.insert(new_net.get_id(), new_net);
        fill_table_net();
    }
}

