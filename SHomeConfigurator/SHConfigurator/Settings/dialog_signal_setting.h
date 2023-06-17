#ifndef DIALOG_SIGNAL_SETTING_H
#define DIALOG_SIGNAL_SETTING_H

#include <QDialog>
#include <QInputDialog>

#include "InternalClass/setting_containers.h"

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

private slots:
    void on_pushButton_add_clicked();

    void on_tableWidget_signal_cellDoubleClicked(int row, int column);

    void on_pushButton_save_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_cancel_clicked();

private:
    void create_table_signal();
    void fill_table_signal();
    void add_row_signal(Signal_Setting elem);
    void delete_signal_from_list(int id);

private:
    Ui::Dialog_Signal_Setting *ui;
    Setting_Containers * p_containers;

    QStringList table_header = {"Name", "ID", "Offset", "Scale", "Init Value", "Error Value", "Description"};
};

#endif // DIALOG_SIGNAL_SETTING_H
