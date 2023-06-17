#ifndef DIALOG_SIGNAL_EDIT_H
#define DIALOG_SIGNAL_EDIT_H

#include <QDialog>
#include "InternalClass/setting_containers.h"
#include "InternalClass/signal_setting.h"

namespace Ui {
class Dialog_Signal_Edit;
}

class Dialog_Signal_Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Signal_Edit(QWidget *parent = nullptr, Setting_Containers * new_containers = nullptr);
    ~Dialog_Signal_Edit();

    void set_signal(Signal_Setting new_signal);
    Signal_Setting get_signal();

private:
    void fill_table_signal_edit();

private slots:
    void on_buttonBox_signal_accepted();

    void on_buttonBox_signal_rejected();

private:
    Ui::Dialog_Signal_Edit *ui;
    Signal_Setting current_signal;
    Setting_Containers * p_containers;
};

#endif // DIALOG_SIGNAL_EDIT_H
