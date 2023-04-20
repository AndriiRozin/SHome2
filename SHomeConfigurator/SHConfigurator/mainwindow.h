#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "Settings/setting_containers.h"

#include "Settings/dialog_sasetting.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Net_clicked();

    void on_pushButton_Placement_clicked();

    void on_pushButton_Actuator_clicked();

    void on_pushButton_Sensor_clicked();

    void on_pushButton_Signals_clicked();

    void on_pushButton_Setup_clicked();

private:
    Ui::MainWindow *ui;
    Setting_Containers * pSettingContainers;
    Dialog_SAsetting * pDialogSaSetting;
};
#endif // MAINWINDOW_H
