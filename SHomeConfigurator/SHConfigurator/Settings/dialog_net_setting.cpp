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
    //qDebug() << p_containers->
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
    QString new_name = QInputDialog::getText(this, tr("Input placement name"),
                                              tr("Name"), QLineEdit::Normal);

     int last_key = 0;
     Net_Setting last_net;
     Net_Setting new_net;

     if(p_containers->networks_map.isEmpty()) {
         new_net = Net_Setting(new_name, last_net.get_id(), last_net.get_description());
     }
     else {
         last_key = p_containers->networks_map.lastKey();
         last_net = p_containers->networks_map[last_key];
         new_net = Net_Setting(new_name, last_net.get_id() + 1, "...");
     }

     p_containers->networks_map.insert(new_net.get_id(), new_net);
     add_row_net(new_net);
     fill_table_net();
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

