#ifndef DIALOG_NET_EDIT_H
#define DIALOG_NET_EDIT_H

#include <QDialog>
#include "InternalClass/setting_containers.h"
#include "InternalClass/net_setting.h"

namespace Ui {
class Dialog_Net_Edit;
}

class Dialog_Net_Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Net_Edit(QWidget *parent = nullptr, Setting_Containers * p_containers = nullptr);
    ~Dialog_Net_Edit();

    void set_net(Net_Setting net);
    Net_Setting get_net();

private slots:
    void on_buttonBox_Net_Edit_accepted();
    void on_buttonBox_Net_Edit_rejected();
    void on_spinBox_id_valueChanged(int arg1);

private:
    Ui::Dialog_Net_Edit *ui;
    Net_Setting net;    
    Setting_Containers * p_containers;
};

#endif // DIALOG_NET_EDIT_H
