#ifndef DIALOG_DEVICE_EDIT_H
#define DIALOG_DEVICE_EDIT_H

#include <QDialog>
#include "InternalClass/setting_containers.h"
#include "InternalClass/device_setting.h"

namespace Ui {
class Dialog_Device_Edit;
}

class Dialog_Device_Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Device_Edit(QWidget *parent = nullptr, Setting_Containers * p_containers = nullptr);
    ~Dialog_Device_Edit();

    void set_device(Device_Setting device);
    Device_Setting get_device();

private slots:
    void on_buttonBox_DeviceEdit_accepted();

    void on_buttonBox_DeviceEdit_rejected();

private:
    Ui::Dialog_Device_Edit *ui;
    Device_Setting device;
    Setting_Containers * p_containers;
};

#endif // DIALOG_DEVICE_EDIT_H
