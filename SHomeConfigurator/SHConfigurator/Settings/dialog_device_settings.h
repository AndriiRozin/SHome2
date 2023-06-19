#ifndef DIALOG_DEVICE_SETTINGS_H
#define DIALOG_DEVICE_SETTINGS_H

#include <QDialog>
#include <QInputDialog>
#include <QMap>

#include "InternalClass/setting_containers.h"
#include "InternalClass/device_setting.h"

namespace Ui {
class Dialog_Device_Settings;
}

class Dialog_Device_Settings : public QDialog
{
    Q_OBJECT
    enum tablkeys {T_NAME=0, T_ID, T_DESCRIPTION, T_SCALE, T_OFFSET};

public:
    explicit Dialog_Device_Settings(QWidget *parent = nullptr, Setting_Containers * p_containers = nullptr);
    ~Dialog_Device_Settings();

private slots:
    void on_pushButton_Add_clicked();

    void on_pushButton_Delete_clicked();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_Save_clicked();

    void on_tableWidget_device_cellDoubleClicked(int row, int column);

private:
    void create_table_device();
    void fill_table_device();
    void add_row_device(Device_Setting elem);
    void delete_device_from_list(int id);

private:
    Ui::Dialog_Device_Settings *ui;
    QStringList table_header = {"Name", "ID", "Description"};

    Setting_Containers * p_containers;

};

#endif // DIALOG_DEVICE_SETTINGS_H
