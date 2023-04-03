#ifndef DIALOG_PLACEMENT_SETTING_H
#define DIALOG_PLACEMENT_SETTING_H

#include <QDialog>
#include <QInputDialog>
#include <QMap>
#include <QList>

#include "Settings/setting_containers.h"
//#include "Application/Settings/InternalClass/placement_setting.h"


namespace Ui {
class Dialog_Placement_Setting;
}

class Dialog_Placement_Setting : public QDialog
{
    Q_OBJECT
    enum tablkeys {T_NAME=0, T_ID, T_DESCRIPTION};

public:
    explicit Dialog_Placement_Setting(QWidget *parent = nullptr, Setting_Containers * p_containers = nullptr);
    ~Dialog_Placement_Setting();

private:
     void create_table_placement();

private:
    Ui::Dialog_Placement_Setting *ui;
    Setting_Containers * p_containers;
    QStringList table_header = {"Name", "ID", "Description"};
};

#endif // DIALOG_PLACEMENT_SETTING_H
