#ifndef DIALOG_SENSOR_EDIT_H
#define DIALOG_SENSOR_EDIT_H

#include <QDialog>

namespace Ui {
class Dialog_Sensor_Edit;
}

class Dialog_Sensor_Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Sensor_Edit(QWidget *parent = nullptr);
    ~Dialog_Sensor_Edit();

private:
    Ui::Dialog_Sensor_Edit *ui;
};

#endif // DIALOG_SENSOR_EDIT_H
