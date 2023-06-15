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

    file_config = read_config_path();
    bool ok = false;
    check_write_file_config_xml(&ok);
    if(ok == false)
    {
        qDebug() << __FUNCTION__ << "File CONFIG is not present!" ;
    }
}

Dialog_Setup::~Dialog_Setup()
{
    delete ui;
}

void Dialog_Setup::on_pushButton_file_change_clicked()
{
    file_config = QFileDialog::getOpenFileName(this,
                                                "Select CONFIG File",
                                                dirToIni,
                                                "Images (*.xml )");
    ui->lineEdit_config_file->setText(file_config);
    save_config_path(file_config);
}

void Dialog_Setup::save_config_path(QString file_name)
{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    settings.setValue("ConfigXML", file_name);
    settings.endGroup();
}

QString Dialog_Setup::read_config_path()
{
    QSettings  settings("SHConfig.ini", QSettings::IniFormat);
    settings.beginGroup("INIT_Files");
    QString file_name = settings.value("ConfigXML").toString();
    settings.endGroup();
    return file_name;
}

bool Dialog_Setup::check_write_file_config_xml(bool* ok)
{

    QFileInfo fi_config(file_config);
    *ok = fi_config.exists();

    qDebug()<<__FUNCTION__<<"file_config"<<file_config << fi_config.exists();

    if(fi_config.exists()) {
        ui->lineEdit_config_file->setText(file_config);
    }
    else {
        ui->lineEdit_config_file->setText("");
    }
    return *ok;
}
