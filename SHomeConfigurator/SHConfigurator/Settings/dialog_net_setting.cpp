#include "dialog_net_setting.h"
#include "ui_dialog_net_setting.h"

#include <QSettings>
#include <QDebug>

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
