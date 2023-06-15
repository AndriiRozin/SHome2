#ifndef DIALOG_ACTUATOR_EDIT_H
#define DIALOG_ACTUATOR_EDIT_H

#include <QDialog>
#include "InternalClass/setting_containers.h"
#include "InternalClass/actuator_setting.h"

namespace Ui {
class Dialog_Actuator_Edit;
}

class Dialog_Actuator_Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Actuator_Edit(QWidget *parent = nullptr, Setting_Containers * p_containers = nullptr);
    ~Dialog_Actuator_Edit();

    void set_actuator(Actuator_Setting sensor);
    Actuator_Setting get_actuator();

private slots:
    void on_comboBox_signalValue_currentIndexChanged(const QString &arg1);
    void on_buttonBox_Actuator_accepted();

    void on_buttonBox_Actuator_rejected();

private:
    Ui::Dialog_Actuator_Edit *ui;
    Actuator_Setting actuator;
    Setting_Containers * p_containers;
};

#endif // DIALOG_ACTUATOR_EDIT_H
