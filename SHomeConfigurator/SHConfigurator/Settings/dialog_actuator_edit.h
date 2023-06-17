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


private:
    void print_actuator();
    void init_Actuator_Edit();

private slots:




    void on_comboBox_actuator_network_currentTextChanged(const QString &arg1);

    void on_buttonBox_actuator_accepted();

    void on_comboBox_actuator_signal_currentTextChanged(const QString &arg1);

    void on_comboBox_actuator_placement2_currentTextChanged(const QString &arg1);

    void on_comboBox_actuator_placement1_currentTextChanged(const QString &arg1);

    void on_comboBox_actuator_placement0_currentTextChanged(const QString &arg1);

private:
    Ui::Dialog_Actuator_Edit *ui;
    Actuator_Setting actuator;
    Setting_Containers * p_containers;
};

#endif // DIALOG_ACTUATOR_EDIT_H
