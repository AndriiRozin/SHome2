#ifndef DIALOG_PLACEMENT_EDIT_H
#define DIALOG_PLACEMENT_EDIT_H

#include <QDialog>
#include "InternalClass/setting_containers.h"
#include "InternalClass/placement_setting.h"

namespace Ui {
class Dialog_Placement_Edit;
}

class Dialog_Placement_Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Placement_Edit(QWidget *parent = nullptr, Setting_Containers * p_containers = nullptr);
    ~Dialog_Placement_Edit();

    //void edit_place(Net_Setting net);
    Placement_Setting get_place();
    void set_place(Placement_Setting new_place);

private slots:
    void on_buttonBox_Placement_Edit_accepted();
    void on_buttonBox_Placement_Edit_rejected();

private:
    Ui::Dialog_Placement_Edit *ui;
    Placement_Setting place;
    Setting_Containers * p_containers;

};

#endif // DIALOG_PLACEMENT_EDIT_H
