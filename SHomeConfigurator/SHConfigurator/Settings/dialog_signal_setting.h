#ifndef DIALOG_SIGNAL_SETTING_H
#define DIALOG_SIGNAL_SETTING_H

#include <QDialog>
#include <QInputDialog>

#include "Settings/setting_containers.h"

namespace Ui {
class Dialog_Signal_Setting;
}

class Dialog_Signal_Setting : public QDialog
{
    Q_OBJECT
    enum tablkeys {T_NAME=0, T_ID, T_OFFSET, T_SCALE, T_INIT, T_ERROR, T_DESRIPTION};

public:
    explicit Dialog_Signal_Setting(QWidget *parent = nullptr, Setting_Containers * p_containers = nullptr);
    ~Dialog_Signal_Setting();

private:
   void create_table_signal();

private:
   Ui::Dialog_Signal_Setting *ui;
   Setting_Containers * p_containers;

   QStringList table_header = {"Name", "ID", "Offset", "Scale", "Init Value", "Error Value", "Description"};
};

#endif // DIALOG_SIGNAL_SETTING_H
