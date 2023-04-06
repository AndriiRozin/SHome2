#include "dialog_sensor_edit.h"
#include "ui_dialog_sensor_edit.h"

#include <QDebug>

Dialog_Sensor_Edit::Dialog_Sensor_Edit(QWidget *parent, Setting_Containers * containers) :
    QDialog(parent),
    ui(new Ui::Dialog_Sensor_Edit),
    sensor(),
    p_containers(containers)
{
    ui->setupUi(this);

    init_dialog();
}

Dialog_Sensor_Edit::~Dialog_Sensor_Edit()
{
    delete ui;
}

void Dialog_Sensor_Edit::set_sensor(Sensor_Setting new_sensor)
{
    sensor = new_sensor;
    print_sensor();
}

void Dialog_Sensor_Edit::init_dialog()
{
    // init comboboxes
    QStringList networks = p_containers->get_net_names_list();
    ui->comboBox_network->addItems(networks);

    QStringList plasements_lst = p_containers->get_placement_names_list();
    ui->comboBox_placement2->addItems(plasements_lst);
    ui->comboBox_placement1->addItems(plasements_lst);
    ui->comboBox_placement0->addItems(plasements_lst);

    QStringList signalValue_lst = p_containers->get_signalValues_names_list();
    ui->comboBox_signal->addItems(signalValue_lst);
}

void Dialog_Sensor_Edit::on_lineEdit_name_editingFinished()
{
    sensor.set_name(ui->lineEdit_name->text());
    print_sensor();
}

void Dialog_Sensor_Edit::on_lineEdit_description_editingFinished()
{
    sensor.set_description(ui->lineEdit_description->text());
    print_sensor();
}

void Dialog_Sensor_Edit::on_comboBox_signal_currentIndexChanged(const QString &arg1)
{
    bool ok;
    int id = p_containers->get_signalID_by_name(arg1,&ok);
    if(ok) {
        sensor.set_signal(p_containers->signals_map[id]);
        print_sensor();
    }
}

void Dialog_Sensor_Edit::on_comboBox_network_currentIndexChanged(const QString &arg1)
{
    bool ok;
    int netID = p_containers->get_networkID_by_name(arg1,&ok);
    if(ok) {
        sensor.set_network(p_containers->networks_map[netID]);
        print_sensor();
    }
}

void Dialog_Sensor_Edit::on_comboBox_placement2_currentIndexChanged(const QString &arg1)
{
    bool ok;
    int id = p_containers->get_placementID_by_name(arg1,&ok);
    if(ok) {
        sensor.set_plasement2(p_containers->placements_map[id]);
    }
}

void Dialog_Sensor_Edit::on_comboBox_placement1_currentIndexChanged(const QString &arg1)
{
    bool ok;
    int id = p_containers->get_placementID_by_name(arg1,&ok);
    if(ok) {
        sensor.set_plasement1(p_containers->placements_map[id]);
    }
}

void Dialog_Sensor_Edit::on_comboBox_placement0_currentIndexChanged(const QString &arg1)
{
    bool ok;
    int id = p_containers->get_placementID_by_name(arg1,&ok);
    if(ok) {
        sensor.set_plasement0(p_containers->placements_map[id]);
    }
}

void Dialog_Sensor_Edit::print_sensor()
{
    ui->lineEdit_name->setText(sensor.get_name());
    ui->lineEdit_description->setText(sensor.get_description());
    ui->label_sensorID->setText(QString::number(sensor.get_id()));

    ui->label_net_name->setText(sensor.get_network().get_name());
    ui->label_net_id->setText(QString::number(sensor.get_network().get_id()));
    ui->label_net_description->setText(sensor.get_network().get_description());

    ui->comboBox_placement2->setCurrentText(sensor.get_placement2().get_name());
    ui->comboBox_placement1->setCurrentText(sensor.get_placement1().get_name());
    ui->comboBox_placement0->setCurrentText(sensor.get_placement0().get_name());

    ui->comboBox_signal->setCurrentIndex(sensor.get_signal().get_id());

    ui->label_name->setText(sensor.get_signal().get_name());
    ui->label_id->setText(QString::number(sensor.get_signal().get_id()));
    ui->label_offset->setText(QString::number(sensor.get_signal().get_offset()));
    ui->label_scale->setText(QString::number(sensor.get_signal().get_scale()));
    ui->label_Init->setText(QString::number(sensor.get_signal().get_initSourceValue()));
    ui->label_Error->setText(QString::number(sensor.get_signal().get_errSourceValue()));
    ui->label_Description->setText(sensor.get_signal().get_description());
    ui->label_Max->setText(QString::number(sensor.get_signal().get_maxValue()));
    ui->label_Min->setText(QString::number(sensor.get_signal().get_minValue()));

    ui->label_SourceValue->setText(QString::number(sensor.get_signal().get_sourceValue()));
    ui->label_CalculatedValue->setText(QString::number(sensor.get_signal().get_calculatedValue()));

    switch (sensor.get_signal().get_signalStatus()) {
    case enum_signal_status::PRE_INIT:
        ui->label_SignalStatus->setText("PRE_INIT");
        break;
    case enum_signal_status::INIT:
        ui->label_SignalStatus->setText("INIT");
        break;
    case enum_signal_status::INIT_SUCCESS:
        ui->label_SignalStatus->setText("INIT_SUCCESS");
        break;
    case enum_signal_status::E_OK:
        ui->label_SignalStatus->setText("E_OK");
        break;
    case enum_signal_status::E_NOT_OK_MAX:
        ui->label_SignalStatus->setText("E_NOT_OK_MAX");
        break;
    case enum_signal_status::E_NOT_OK_MIN:
        ui->label_SignalStatus->setText("E_NOT_OK_MIN");
        break;
    case enum_signal_status::E_NOT_OK_DIVISION:
        ui->label_SignalStatus->setText("E_NOT_OK_DIVISION");
        break;
    default:
        ui->label_SignalStatus->setText("E_NOT_OK");
        break;
    }
}

void Dialog_Sensor_Edit::on_buttonBox_accepted()
{
    p_containers->sensors_map.insert(sensor.get_id(), sensor);
}


void Dialog_Sensor_Edit::on_pushButton_sourceValue_clicked()
{
    Signal_Setting current_signal = sensor.get_signal();
    current_signal.set_sourceValue(ui->spinBox_SourceValue->value());
    sensor.set_signal(current_signal);
    print_sensor();
}

void Dialog_Sensor_Edit::on_pushButton_CalculateValue_clicked()
{
    Signal_Setting current_signal = sensor.get_signal();
    current_signal.set_calculatedValue(ui->doubleSpinBox_CalculateValue->value());
    sensor.set_signal(current_signal);
    print_sensor();
    qDebug() << __FUNCTION__ << ui->doubleSpinBox_CalculateValue->value() << current_signal.get_calculatedValue();
}
