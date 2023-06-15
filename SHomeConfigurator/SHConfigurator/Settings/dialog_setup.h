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
    void save_config_path(QString file_name);
    QString read_config_path();
    bool check_write_file_config_xml(bool* ok);

private slots:
//    void on_pushButton_Net_Change_clicked();
//    void on_pushButton_Placement_Change_clicked();
//    void on_pushButton_Signal_Change_clicked();
//    void on_pushButton_Sensor_Change_clicked();
//    void on_pushButton_ACtuator_Change_clicked();

    void on_pushButton_file_change_clicked();

private:
    Ui::Dialog_Setup *ui;
    QString dirToIni;
    QString file_net;
    QString file_place;
    QString file_signal;
    QString file_sensor;
    QString file_actuator;

    QString file_config;
};

#endif // DIALOG_SETUP_H
