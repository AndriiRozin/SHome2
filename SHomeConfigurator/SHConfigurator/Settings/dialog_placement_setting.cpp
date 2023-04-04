#include "dialog_placement_setting.h"
#include "ui_dialog_placement_setting.h"

#include <QSettings>
#include <QDebug>

Dialog_Placement_Setting::Dialog_Placement_Setting(QWidget *parent, Setting_Containers *containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Placement_Setting),
    p_containers(containers)
{
    ui->setupUi(this);
    create_table_placement();

    //qDebug() << p_containers->
    //fill_table_placement();
}

Dialog_Placement_Setting::~Dialog_Placement_Setting()
{
    delete ui;
}

void Dialog_Placement_Setting::create_table_placement()
{
    int tableColumns = table_header.size() ;
    //create table column
    ui->tableWidget_placement->setColumnCount(tableColumns);
    ui->tableWidget_placement->setShowGrid(true);
    ui->tableWidget_placement->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_placement->setSelectionBehavior(QAbstractItemView::SelectRows);

    //create table headers (vertical and horizontal)
    ui->tableWidget_placement->setHorizontalHeaderLabels(table_header);
    ui->tableWidget_placement->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_placement->verticalHeader()->setVisible(true);
}

/*
void Dialog_Placement_Setting::fill_table_placement()
{
    ui->tableWidget_placement->setRowCount(0);
    for(int i = 0; i < p_containers->placements_map.size(); i++)
    {
        Placement_Setting tmp =  p_containers->placements_map[i];
        add_row_placement(tmp);
    }
}
*/


void Dialog_Placement_Setting::add_row_placement(Placement_Setting elem)
{
    //create new row
    ui->tableWidget_placement->insertRow(ui->tableWidget_placement->rowCount());

    //create new item in "0" columns with number of row
    ui->tableWidget_placement->setItem(ui->tableWidget_placement->rowCount()-1,T_NAME, new QTableWidgetItem(elem.get_name()));
    ui->tableWidget_placement->setItem(ui->tableWidget_placement->rowCount()-1,T_ID, new QTableWidgetItem(QString::number(elem.get_id())));
    ui->tableWidget_placement->setItem(ui->tableWidget_placement->rowCount()-1,T_DESCRIPTION, new QTableWidgetItem(elem.get_description()));
    //create new items->columns in current row
}


