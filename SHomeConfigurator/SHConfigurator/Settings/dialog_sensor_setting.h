#ifndef DIALOG_SENSOR_SETTING_H
#define DIALOG_SENSOR_SETTING_H

#include <QDialog>
#include <QInputDialog>
#include <QMap>

#include "InternalClass/setting_containers.h"
#include "InternalClass/sensor_setting.h"

namespace Ui {
class Dialog_Sensor_Setting;
}

class Dialog_Sensor_Setting : public QDialog
{
    Q_OBJECT
    enum tablkeys {T_NAME=0, T_ID, T_DESRIPTION, T_SCALE, T_OFFSET};

public:
    explicit Dialog_Sensor_Setting(QWidget *parent = nullptr, Setting_Containers * p_containers = nullptr);
    ~Dialog_Sensor_Setting();

private slots:
    void on_pushButton_add_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_save_clicked();
    void on_pushButton_cancel_clicked();
    void on_tableWidget_sensor_cellDoubleClicked(int row, int column);

private:
    void create_table_sensor();
    void fill_table_sensor();
    void add_row_sensor(Sensor_Setting elem);
    void delete_sensor_from_list(int id);

private:
    Ui::Dialog_Sensor_Setting *ui;
    QStringList table_header = {"Name", "ID", "Description"};
    Setting_Containers * p_containers;
};

#endif // DIALOG_SENSOR_SETTING_H
