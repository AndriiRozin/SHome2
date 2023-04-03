#include "dialog_net_setting.h"
#include "ui_dialog_net_setting.h"

#include <QSettings>
#include <QDebug>

Dialog_net_setting::Dialog_net_setting(QWidget *parent, Setting_Containers *containers) :
    QDialog(parent)
  , ui(new Ui::Dialog_net_setting)
  , p_containers(containers)

{
    ui->setupUi(this);
    create_table_net();
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
