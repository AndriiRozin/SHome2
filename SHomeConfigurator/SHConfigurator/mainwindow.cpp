#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QStatusBar>

#include "Settings/dialog_setup.h"
#include "Settings/dialog_net_setting.h"
#include "Settings/dialog_placement_setting.h"
#include "Settings/dialog_actuator_setting.h"
#include "Settings/dialog_sensor_setting.h"
#include "Settings/dialog_signal_setting.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , pSettingContainers(new Setting_Containers)
    , pDialogSaSetting(new Dialog_SAsetting(this))

{
    ui->setupUi(this);

    //pDialogSaSetting->setModal(false);
    //qDebug() << pSettingContainers.
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Net_clicked()
{
    Dialog_net_setting mDialogNet(this, pSettingContainers);
    mDialogNet.setModal(true);
    mDialogNet.exec();
}


void MainWindow::on_pushButton_Placement_clicked()
{
    Dialog_Placement_Setting mDialogPlacement(this, pSettingContainers);
    mDialogPlacement.setModal(true);
    mDialogPlacement.exec();
}


void MainWindow::on_pushButton_Actuator_clicked()
{
    Dialog_Actuator_Setting  mDialogActuator(this, pSettingContainers);
    mDialogActuator.setModal(true);
    mDialogActuator.exec();
}


void MainWindow::on_pushButton_Sensor_clicked()
{
    Dialog_Sensor_Setting mDialogSensor(this, pSettingContainers);
    mDialogSensor.setModal(true);
    mDialogSensor.exec();
}


void MainWindow::on_pushButton_Signals_clicked()
{
    Dialog_Signal_Setting mDialogSensor(this, pSettingContainers);
    mDialogSensor.setModal(true);
    mDialogSensor.exec();
}


void MainWindow::on_pushButton_Setup_clicked()
{
    Dialog_Setup mDialogSetup(this);
    mDialogSetup.setModal(true);
    mDialogSetup.exec();
}
