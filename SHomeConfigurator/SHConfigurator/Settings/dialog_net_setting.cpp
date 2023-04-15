#include "dialog_net_setting.h"
#include "ui_dialog_net_setting.h"

#include <QSettings>
#include <QDebug>
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
    for(int i = 0; i < p_containers->networks_map.size(); i++)
    {
        Net_Setting tmp =  p_containers->networks_map[i];
        add_row_net(tmp);
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
    bool ok;
    int delete_row = QInputDialog::getInt(this, tr("Input line"),
                                          tr("Line"), 1, 1, p_containers->networks_map.size(), 1, &ok);

    if(ok) {
        delete_net_from_list(delete_row - 1);
        fill_table_net();
    }
}

void Dialog_net_setting::delete_net_from_list(int id)
{
    p_containers->networks_map.remove(id);

    QList<int> keys = p_containers->networks_map.keys();
    foreach(int key, keys) {
        if(key > id){
            Net_Setting current_net = p_containers->networks_map[key];
            QString name = current_net.get_name();
            Net_Setting new_place = Net_Setting(name, key-1,"");

            p_containers->networks_map.remove(key);
            p_containers->networks_map.insert(key-1, new_place);
        }
    }
}

void Dialog_net_setting::on_pushButton_save_clicked()
{
    p_containers->save_all_networks_to_file();
    close();
}

void Dialog_net_setting::on_pushButton_cancel_clicked()
{
    close();
}

void Dialog_net_setting::on_tableWidget_net_cellDoubleClicked(int row, int column)
{
    Net_Setting currentNet = p_containers->networks_map[row];
    Dialog_Net_Edit mDialog_Net_edit(this, p_containers);
    mDialog_Net_edit.edit_net(currentNet);
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

