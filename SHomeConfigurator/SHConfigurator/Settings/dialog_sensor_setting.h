#ifndef DIALOG_SENSOR_SETTING_H
#define DIALOG_SENSOR_SETTING_H

#include <QDialog>
#include <QInputDialog>
#include <QMap>

#include "Settings/setting_containers.h"
//#include "Settings/InternalClass/sensor_setting.h"
//#include "Settings/dialog_sensor_edit.h"
//#include "Settings/dialog_placement_setting.h"

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

private:
    void create_table_sensor();

private:
    Ui::Dialog_Sensor_Setting *ui;
    QStringList table_header = {"Name", "ID", "Description"};
    Setting_Containers * p_containers;
};

#endif // DIALOG_SENSOR_SETTING_H
