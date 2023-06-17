#ifndef DIALOG_SENSOR_EDIT_H
#define DIALOG_SENSOR_EDIT_H

#include <QDialog>
#include "InternalClass/setting_containers.h"
#include "InternalClass/sensor_setting.h"

namespace Ui {
class Dialog_Sensor_Edit;
}

class Dialog_Sensor_Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Sensor_Edit(QWidget *parent = nullptr, Setting_Containers * p_containers = nullptr);
    ~Dialog_Sensor_Edit();

    void set_sensor(Sensor_Setting sensor);
    Sensor_Setting get_sensor();


private slots:
    //void on_comboBox_placement2_currentIndexChanged(const QString &arg1);
    //void on_comboBox_placement1_currentIndexChanged(const QString &arg1);
    //void on_comboBox_placement0_currentIndexChanged(const QString &arg1);

    //void on_comboBox_network_currentIndexChanged(const QString &arg1);

    //void on_comboBox_signal_currentIndexChanged(const QString &arg1);


















    void on_buttonBox_sensor_accepted();

    void on_buttonBox_sensor_rejected();

    void on_comboBox_sensor_network_currentTextChanged(const QString &arg1);

    void on_comboBox_sensor_signal_currentTextChanged(const QString &arg1);

    void on_comboBox_sensor_placement2_currentTextChanged(const QString &arg1);

    void on_comboBox_sensor_placement1_currentTextChanged(const QString &arg1);

    void on_comboBox_sensor_placement0_currentTextChanged(const QString &arg1);

private:
    void init_Sensor_Edit();
    void print_sensor();

private:
    Ui::Dialog_Sensor_Edit *ui;
    Sensor_Setting sensor;
    Setting_Containers * p_containers;
};

#endif // DIALOG_SENSOR_EDIT_H
