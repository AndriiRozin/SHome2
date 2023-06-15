#include "dialog_placement_setting.h"
#include "ui_dialog_placement_setting.h"

#include <QSettings>
#include <QDebug>
#include "Settings/dialog_placement_edit.h"

Dialog_Placement_Setting::Dialog_Placement_Setting(QWidget *parent, Setting_Containers *containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Placement_Setting),
    p_containers(containers)
{
    ui->setupUi(this);
    create_table_placement();
    fill_table_placement();
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


void Dialog_Placement_Setting::fill_table_placement()
{
    ui->tableWidget_placement->setRowCount(0);
    for(int i = 0; i < p_containers->placements_map.size(); i++)
    {
        Placement_Setting tmp =  p_containers->placements_map[i];
        add_row_placement(tmp);
    }
}

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

void Dialog_Placement_Setting::on_pushButton_add_clicked()
{
    Dialog_Placement_Edit mDialog_Place_edit(this, p_containers);
    mDialog_Place_edit.setModal(true);
    mDialog_Place_edit.exec();

    Placement_Setting new_place;
    new_place = mDialog_Place_edit.get_place();

    // added new net to containers
    if(new_place.get_id() >= 0)
    {
        p_containers->placements_map.insert(new_place.get_id(), new_place);
        fill_table_placement();
    }
}

void Dialog_Placement_Setting::on_pushButton_delete_clicked()
{
    bool ok;
    int delete_row = QInputDialog::getInt(this, tr("Input line"),
                                          tr("Line"), 1, 1, p_containers->placements_map.size(), 1, &ok);

    if(ok) {
        delete_placement_from_list(delete_row - 1);
        fill_table_placement();
    }
}

void Dialog_Placement_Setting::delete_placement_from_list(int id)
{
    p_containers->placements_map.remove(id);

    QList<int> keys = p_containers->placements_map.keys();
    foreach(int key, keys) {
        if(key > id){
            Placement_Setting current_place = p_containers->placements_map[key];
            QString name = current_place.get_name();
            QString description = current_place.get_description();
            Placement_Setting new_place = Placement_Setting(name, key-1, description);

            p_containers->placements_map.remove(key);
            p_containers->placements_map.insert(key-1, new_place);
        }
    }
}

void Dialog_Placement_Setting::on_pushButton_save_clicked()
{
    p_containers->write_to_xml();
    close();
}


void Dialog_Placement_Setting::on_pushButton_close_clicked()
{
    close();
}

void Dialog_Placement_Setting::on_tableWidget_placement_cellDoubleClicked(int row, int column)
{
    Placement_Setting currentPlace = p_containers->placements_map[row];
    Dialog_Placement_Edit mDialog_Place_edit(this, p_containers);
    mDialog_Place_edit.edit_place(currentPlace);
    mDialog_Place_edit.setModal(true);
    mDialog_Place_edit.exec();

    Placement_Setting new_place;
    new_place = mDialog_Place_edit.get_place();

    // added new net to containers
    if(new_place.get_id() >= 0)
    {
        p_containers->placements_map.insert(new_place.get_id(), new_place);
        fill_table_placement();
    }
}

