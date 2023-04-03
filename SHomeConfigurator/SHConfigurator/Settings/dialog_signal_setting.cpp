#include "dialog_signal_setting.h"
#include "ui_dialog_signal_setting.h"

#include <QDebug>

Dialog_Signal_Setting::Dialog_Signal_Setting(QWidget *parent, Setting_Containers * containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Signal_Setting),
    p_containers(containers)
{
    ui->setupUi(this);
    create_table_signal();
}

Dialog_Signal_Setting::~Dialog_Signal_Setting()
{
    delete ui;
}

void Dialog_Signal_Setting::create_table_signal()
{

    int tableColumns = table_header.size() ;

    //create table column
    ui->tableWidget_signal ->setColumnCount(tableColumns);
    ui->tableWidget_signal->setShowGrid(true);
    ui->tableWidget_signal->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_signal->setSelectionBehavior(QAbstractItemView::SelectRows);

    //create table headers (vertical and horizontal)
    ui->tableWidget_signal->setHorizontalHeaderLabels(table_header);
    ui->tableWidget_signal->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_signal->verticalHeader()->setVisible(true);
}
