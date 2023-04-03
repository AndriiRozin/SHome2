#ifndef DIALOG_ACTUATOR_SETTING_H
#define DIALOG_ACTUATOR_SETTING_H

#include <QDialog>
#include <QInputDialog>
#include <QMap>

//#include "Application/Settings/InternalClass/actuator_setting.h"
#include "Settings/dialog_actuator_edit.h"
#include "Settings/dialog_placement_setting.h"

namespace Ui {
class Dialog_Actuator_Setting;
}

class Dialog_Actuator_Setting : public QDialog
{
    Q_OBJECT
    enum tablkeys {T_NAME=0, T_ID, T_DESRIPTION, T_SCALE, T_OFFSET};

public:
    explicit Dialog_Actuator_Setting(QWidget *parent = nullptr, Setting_Containers * p_containers = nullptr);
    ~Dialog_Actuator_Setting();

private:
    void create_table_actuator();

private:
    Ui::Dialog_Actuator_Setting *ui;
    QStringList table_header = {"Name", "ID", "Description"};

    Setting_Containers * p_containers;
};

#endif // DIALOG_ACTUATOR_SETTING_H
