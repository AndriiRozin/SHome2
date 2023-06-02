#include "dialog_setup.h"
#include "ui_dialog_setup.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QSettings>
#include <QDebug>

Dialog_Setup::Dialog_Setup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Setup),
    dirToIni(),
    file_net(),
    file_place(),
    file_signal(),
    file_sensor(),
    file_actuator()
{
    ui->setupUi(this);

    dirToIni = read_Init_Folder();
    ui->lineEdit_Path->setText(dirToIni);

    file_net = read_Init_net();
    check_write_file_name_net();

    file_place = read_Init_place();
    check_write_file_name_place();

    file_signal = read_Init_signal();
    check_write_file_name_signal();

    file_sensor = read_Init_sensor();
    check_write_file_name_sensor();

    file_actuator = read_Init_actuator();
    check_write_file_name_actuator();
}

Dialog_Setup::~Dialog_Setup()
{
    delete ui;
}

void Dialog_Setup::check_write_file_name_net()
{
    QFileInfo fi_net(file_net);
    QString fileName_net = fi_net.fileName();

    if(fi_net.exists()) {
//        ui->lineEdit_file_net->setStyleSheet("color: black;  background-color: white");
    }
    else {
//        ui->lineEdit_file_net->setStyleSheet("color: white;  background-color: red");
    }
    ui->lineEdit_file_net->setText(fileName_net);
}

void Dialog_Setup::check_write_file_name_place()
{
    QFileInfo fi_place(file_place);
    QString fileName_place = fi_place.fileName();

    if(fi_place.exists()) {
//        ui->lineEdit_file_place->setStyleSheet("color: black;  background-color: white");
    }
    else {
//        ui->lineEdit_file_place->setStyleSheet("color: white;  background-color: red");
    }
    ui->lineEdit_file_place->setText(fileName_place);
}


void Dialog_Setup::check_write_file_name_signal()
{
    QFileInfo fi_signal(file_signal);
    QString fileName_signal = fi_signal.fileName();

    if(fi_signal.exists()) {
//        ui->lineEdit_file_signal->setStyleSheet("color: black;  background-color: white");
    }
    else {
//        ui->lineEdit_file_signal->setStyleSheet("color: white;  background-color: red");
    }
    ui->lineEdit_file_signal->setText(fileName_signal);
}

void Dialog_Setup::check_write_file_name_sensor()
{
    QFileInfo fi_sensor(file_sensor);
    QString fileName_sensor = fi_sensor.fileName();

    if(fi_sensor.exists()) {
//        ui->lineEdit_file_sensor->setStyleSheet("color: black;  background-color: white");
    }
    else {
//        ui->lineEdit_file_sensor->setStyleSheet("color: white;  background-color: red");
    }
    ui->lineEdit_file_sensor->setText(fileName_sensor);
}

void Dialog_Setup::check_write_file_name_actuator()
{
    QFileInfo fi_actuator(file_actuator);
    QString fileName_actuator = fi_actuator.fileName();

    if(fi_actuator.exists()) {
//        ui->lineEdit_file_actuator->setStyleSheet("color: black;  background-color: white");
    }
    else {
//        ui->lineEdit_file_actuator->setStyleSheet("color: white;  background-color: red");
    }
    ui->lineEdit_file_actuator->setText(fileName_actuator);
}

void Dialog_Setup::save_Init_Path(QString absPath)
{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    settings.setValue("Folder", absPath);
    settings.endGroup();
}

void Dialog_Setup::save_Init_net(QString file_name)
{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    settings.setValue("Net", file_name);
    settings.endGroup();
}

void Dialog_Setup::save_Init_place(QString file_name)
{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    settings.setValue("Place", file_name);
    settings.endGroup();
}

void Dialog_Setup::save_Init_signal(QString file_name)
{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    settings.setValue("Signal", file_name);
    settings.endGroup();
}

void Dialog_Setup::save_Init_sensor(QString file_name)
{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    settings.setValue("Sensor", file_name);
    settings.endGroup();
}

void Dialog_Setup::save_Init_actuator(QString file_name)
{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    settings.setValue("Actuator", file_name);
    settings.endGroup();
}

QString Dialog_Setup::read_Init_Folder()
{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    QString dir = settings.value("Folder").toString();
    settings.endGroup();
    return dir;
}

QString Dialog_Setup::read_Init_net()
{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    QString file_name = settings.value("Net").toString();
    settings.endGroup();
    return file_name;
}

QString Dialog_Setup::read_Init_place()
{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    QString file_name = settings.value("Place").toString();
    settings.endGroup();
    return file_name;
}

QString Dialog_Setup::read_Init_signal()
{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    QString file_name = settings.value("Signal").toString();
    settings.endGroup();
    return file_name;
}

QString Dialog_Setup::read_Init_sensor()
{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    QString file_name = settings.value("Sensor").toString();
    settings.endGroup();
    return file_name;
}

QString Dialog_Setup::read_Init_actuator()
{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    QString file_name = settings.value("Actuator").toString();
    settings.endGroup();
    return file_name;
}

void Dialog_Setup::on_pushButton_Net_Change_clicked()
{
    file_net = QFileDialog::getOpenFileName(this,
                                            "Select INI File",
                                            dirToIni,
                                            "Images (*.ini )");
    // get directory
    QDir dir(file_net);
    dir.cdUp();
    QString path = dir.absolutePath();

    save_Init_net(file_net);
    save_Init_Path(path);

    check_write_file_name_net();
}

void Dialog_Setup::on_pushButton_Placement_Change_clicked()
{
    file_place = QFileDialog::getOpenFileName(this,
                                              "Select INI File",
                                              dirToIni,
                                              "Images (*.ini )");
    // get directory
    QDir dir(file_place);
    dir.cdUp();
    QString path = dir.absolutePath();

    save_Init_place(file_place);
    save_Init_Path(path);

    check_write_file_name_place();
}

void Dialog_Setup::on_pushButton_Signal_Change_clicked()
{
    file_signal = QFileDialog::getOpenFileName(this,
                                               "Select INI File",
                                               dirToIni,
                                               "Images (*.ini )");
    // get directory
    QDir dir(file_signal);
    dir.cdUp();
    QString path = dir.absolutePath();

    save_Init_signal(file_signal);
    save_Init_Path(path);

    check_write_file_name_signal();
}

void Dialog_Setup::on_pushButton_Sensor_Change_clicked()
{
    file_sensor = QFileDialog::getOpenFileName(this,
                                               "Select INI File",
                                               dirToIni,
                                               "Images (*.ini )");
    // get directory
    QDir dir(file_sensor);
    dir.cdUp();
    QString path = dir.absolutePath();

    save_Init_sensor(file_sensor);
    save_Init_Path(path);

    check_write_file_name_sensor();
}

void Dialog_Setup::on_pushButton_ACtuator_Change_clicked()
{
    file_actuator = QFileDialog::getOpenFileName(this,
                                                 "Select INI File",
                                                 dirToIni,
                                                 "Images (*.ini )");
    // get directory
    QDir dir(file_actuator);
    dir.cdUp();
    QString path = dir.absolutePath();

    save_Init_actuator(file_actuator);
    save_Init_Path(path);

    check_write_file_name_actuator();
}
