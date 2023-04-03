#include "dialog_placement_setting.h"
#include "ui_dialog_placement_setting.h"

Dialog_Placement_Setting::Dialog_Placement_Setting(QWidget *parent, Setting_Containers *containers) :
  QDialog(parent)
  , ui(new Ui::Dialog_Placement_Setting)
  , p_containers(containers)
{
    ui->setupUi(this);
    create_table_placement();
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
