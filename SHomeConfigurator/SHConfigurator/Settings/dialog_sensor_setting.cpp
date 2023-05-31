#include "dialog_sensor_setting.h"
#include "ui_dialog_sensor_setting.h"

#include <QSettings>
#include <QDebug>

#include "Settings/dialog_sensor_edit.h"

Dialog_Sensor_Setting::Dialog_Sensor_Setting(QWidget *parent, Setting_Containers * containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Sensor_Setting),
    p_containers(containers)
{
    ui->setupUi(this);
    create_table_sensor();
    fill_table_sensor();
}

Dialog_Sensor_Setting::~Dialog_Sensor_Setting()
{
    delete ui;
}

void Dialog_Sensor_Setting::create_table_sensor()
{
    int tableColumns = table_header.size() ;

    //create table column
    ui->tableWidget_sensor->setColumnCount(tableColumns);
    ui->tableWidget_sensor->setShowGrid(true);
    ui->tableWidget_sensor->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_sensor->setSelectionBehavior(QAbstractItemView::SelectRows);

    //create table headers (vertical and horizontal)
    ui->tableWidget_sensor->setHorizontalHeaderLabels(table_header);
    ui->tableWidget_sensor->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_sensor->verticalHeader()->setVisible(true);
}

void Dialog_Sensor_Setting::add_row_sensor(Sensor_Setting elem)
{
    //create new row
    ui->tableWidget_sensor->insertRow(ui->tableWidget_sensor->rowCount());

    //create new item in "0" columns with number of row
    ui->tableWidget_sensor->setItem(ui->tableWidget_sensor->rowCount()-1,T_NAME, new QTableWidgetItem(elem.get_name()));
    ui->tableWidget_sensor->setItem(ui->tableWidget_sensor->rowCount()-1,T_ID, new QTableWidgetItem(QString::number(elem.get_id())));
    ui->tableWidget_sensor->setItem(ui->tableWidget_sensor->rowCount()-1,T_DESRIPTION, new QTableWidgetItem(elem.get_description()));
    //create new items->columns in current row
}

void Dialog_Sensor_Setting::fill_table_sensor()
{
    ui->tableWidget_sensor->setRowCount(0);
    for(int i = 0; i < p_containers->sensors_map.size(); i++)
    {
        Sensor_Setting tmp = p_containers->sensors_map[i];
        add_row_sensor(tmp);
    }
}

void Dialog_Sensor_Setting::on_pushButton_add_clicked()
{
    Dialog_Sensor_Edit mDialog_Sensor_edit(this, p_containers);
    mDialog_Sensor_edit.setModal(true);
    mDialog_Sensor_edit.exec();

    Sensor_Setting new_sensor;
    new_sensor = mDialog_Sensor_edit.get_sensor();

    // added new sensor to containers
    if(new_sensor.get_id() >= 0)
    {
        p_containers->sensors_map.insert(new_sensor.get_id(), new_sensor);
        fill_table_sensor();
    }
}


void Dialog_Sensor_Setting::on_pushButton_delete_clicked()
{
    bool ok;
    int delete_row = QInputDialog::getInt(this, tr("Input line"),
                                          tr("Line"), 1, 1, p_containers->sensors_map.size(), 1, &ok);

    if(ok) {
        delete_sensor_from_list(delete_row - 1);
        fill_table_sensor();
    }
}

void Dialog_Sensor_Setting::delete_sensor_from_list(int id)
{
    p_containers->sensors_map.remove(id);

    QList<int> keys = p_containers->sensors_map.keys();
    foreach(int key, keys) {
        if(key > id){
            Sensor_Setting current_sensor = p_containers->sensors_map[key];
            QString name = current_sensor.get_name();
            Sensor_Setting new_sensor = Sensor_Setting(name, key-1);

            p_containers->sensors_map.remove(key);
            p_containers->sensors_map.insert(key-1, new_sensor);
        }
    }
}

void Dialog_Sensor_Setting::on_pushButton_save_clicked()
{
    p_containers->save_all_sensors_to_file();
    close();
}


void Dialog_Sensor_Setting::on_pushButton_cancel_clicked()
{
    close();
}


void Dialog_Sensor_Setting::on_tableWidget_sensor_cellDoubleClicked(int row, int column)
{
    Sensor_Setting currentSensor = p_containers->sensors_map[row];
    Dialog_Sensor_Edit mDialog_Sensor_edit(this, p_containers);
    mDialog_Sensor_edit.edit_sensor(currentSensor);
    mDialog_Sensor_edit.setModal(true);
    mDialog_Sensor_edit.exec();

    ui->tableWidget_sensor->setRowCount(0);
    fill_table_sensor();
}

