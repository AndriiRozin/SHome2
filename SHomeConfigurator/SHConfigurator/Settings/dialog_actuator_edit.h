#ifndef DIALOG_ACTUATOR_EDIT_H
#define DIALOG_ACTUATOR_EDIT_H

#include <QDialog>

namespace Ui {
class Dialog_Actuator_Edit;
}

class Dialog_Actuator_Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Actuator_Edit(QWidget *parent = nullptr);
    ~Dialog_Actuator_Edit();

private:
    Ui::Dialog_Actuator_Edit *ui;
};

#endif // DIALOG_ACTUATOR_EDIT_H
