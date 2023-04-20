#ifndef DIALOG_SETUP_H
#define DIALOG_SETUP_H

#include <QDialog>


namespace Ui {
class Dialog_Setup;
}

class Dialog_Setup : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Setup(QWidget *parent = nullptr);
    ~Dialog_Setup();

private:
    void save_Init_Path(QString absPath);
    void save_Init_net(QString file_Net);
    void save_Init_place(QString file_place);
    void save_Init_signal(QString file_place);
    void save_Init_sensor(QString file_place);
    void save_Init_actuator(QString file_place);

    QString read_Init_Folder();
    QString read_Init_net();
    QString read_Init_place();
    QString read_Init_signal();
    QString read_Init_sensor();
    QString read_Init_actuator();

    void check_write_file_name_net();
    void check_write_file_name_place();
    void check_write_file_name_signal();
    void check_write_file_name_sensor();
    void check_write_file_name_actuator();

private slots:
    void on_pushButton_Net_Change_clicked();
    void on_pushButton_Placement_Change_clicked();
    void on_pushButton_Signal_Change_clicked();
    void on_pushButton_Sensor_Change_clicked();
    void on_pushButton_ACtuator_Change_clicked();

private:
    Ui::Dialog_Setup *ui;
    QString dirToIni;
    QString file_net;
    QString file_place;
    QString file_signal;
    QString file_sensor;
    QString file_actuator;
};

#endif // DIALOG_SETUP_H
