#ifndef DIALOG_PLACEMENT_SETTING_H
#define DIALOG_PLACEMENT_SETTING_H

#include <QDialog>
#include <QInputDialog>
#include <QMap>

#include "InternalClass/setting_containers.h"
#include "InternalClass/placement_setting.h"

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

    Placement_Setting get_place();

private slots:
    void on_pushButton_add_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_save_clicked();
    void on_pushButton_close_clicked();

    void on_tableWidget_placement_cellDoubleClicked(int row, int column);

private:
     void create_table_placement();
     void fill_table_placement();
     void add_row_placement(Placement_Setting elem);
     void delete_placement_from_list(int id);

private:
    Ui::Dialog_Placement_Setting *ui;
    Setting_Containers * p_containers;
    QStringList table_header = {"Name", "ID", "Description"};
};

#endif // DIALOG_PLACEMENT_SETTING_H
