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
    fill_table_signal();
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

void Dialog_Signal_Setting::add_row_signal(Signal_Setting elem)
{
    //create new row
    ui->tableWidget_signal->insertRow(ui->tableWidget_signal->rowCount());

    //create new item in "0" columns with number of row
    ui->tableWidget_signal->setItem(ui->tableWidget_signal->rowCount()-1,T_NAME, new QTableWidgetItem(elem.get_name()));
    ui->tableWidget_signal->setItem(ui->tableWidget_signal->rowCount()-1,T_ID, new QTableWidgetItem(QString::number(elem.get_id())));
    ui->tableWidget_signal->setItem(ui->tableWidget_signal->rowCount()-1,T_OFFSET, new QTableWidgetItem(QString::number(elem.get_offset())));
    ui->tableWidget_signal->setItem(ui->tableWidget_signal->rowCount()-1,T_SCALE, new QTableWidgetItem(QString::number(elem.get_scale())));
    ui->tableWidget_signal->setItem(ui->tableWidget_signal->rowCount()-1,T_INIT, new QTableWidgetItem(QString::number(elem.get_initSourceValue())));
    ui->tableWidget_signal->setItem(ui->tableWidget_signal->rowCount()-1,T_ERROR, new QTableWidgetItem(QString::number(elem.get_errSourceValue())));
    ui->tableWidget_signal->setItem(ui->tableWidget_signal->rowCount()-1,T_DESRIPTION, new QTableWidgetItem(elem.get_description()));
    //create new items->columns in current row
}

void Dialog_Signal_Setting::fill_table_signal()
{
    ui->tableWidget_signal->setRowCount(0);
    for(int i = 0; i < p_containers->signals_map.size(); i++)
    {
        Signal_Setting tmp = p_containers->signals_map[i];
        add_row_signal(tmp);
    }
}
