#ifndef DIALOG_NET_SETTING_H
#define DIALOG_NET_SETTING_H

#include <QDialog>
#include <QInputDialog>
#include <QMap>

#include "Settings/setting_containers.h"
//#include "Application/Settings/InternalClass/net_setting.h"

namespace Ui {
class Dialog_net_setting;
}

class Dialog_net_setting : public QDialog
{
    Q_OBJECT
    enum tablkeys {T_NAME=0, T_ID, T_DESCRIPTION};

public:
    explicit Dialog_net_setting(QWidget *parent = nullptr, Setting_Containers * p_containers = nullptr);
    ~Dialog_net_setting();

private:
    void create_table_net();

private:
    Ui::Dialog_net_setting *ui;
    Setting_Containers * p_containers;

    QStringList table_header = {"Name", "ID", "Description"};
    // QMap<int, Net_setting> net_map;
};

#endif // DIALOG_NET_SETTING_H
