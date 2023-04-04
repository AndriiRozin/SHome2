#ifndef SIGNAL_SETTING_H
#define SIGNAL_SETTING_H

#include <QtGlobal>
#include <QString>
#include <QDebug>

enum enum_signal_status {
    E_OK = 0,
    E_NOT_OK,
    E_NOT_OK_MAX,
    E_NOT_OK_MIN,
    E_NOT_OK_DIVISION,
    PRE_INIT = 252,
    INIT,
    INIT_SUCCESS
};

class Signal_Setting
{
public:
    Signal_Setting();

    void set_name(const QString value);
    QString get_name();

    void set_id(const uint value);
    uint get_id();

    void set_description(const QString value);
    QString get_description();



    void set_initSourceValue(const uint value);
    uint get_initSourceValue();

    void set_errSourceValue(const uint value);
    uint get_errSourceValue();

    void set_sourceValue(const uint value);
    uint get_sourceValue();

    void set_calculatedValue(const double value);
    double get_calculatedValue();



    void set_offset(const double value);
    double get_offset();

    void set_scale(const double value);
    double get_scale();


    void set_maxValue(const double value);
    double get_maxValue();

    void set_minValue(const double value);
    double get_minValue();

    void set_signalStatus(const int value);
    int get_signalStatus();

private:
    QString name;
    int signal_id;
    QString description;

    uint init_sourceValue;
    uint err_sourceValue;

    uint sourceValue;
    double  calculatedValue;

    double offset;
    double scale;
    double maxValue;
    double minValue;

    int signalStatus;
};

#endif // SIGNAL_SETTING_H
