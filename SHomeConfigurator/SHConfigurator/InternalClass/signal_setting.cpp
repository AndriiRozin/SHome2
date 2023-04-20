#include "signal_setting.h"
#include <QDebug>

Signal_Setting::Signal_Setting():
    offset(0),
    factor(1),
    signalStatus(PRE_INIT)
{}

void Signal_Setting::set_name(const QString value)
{
    name = value;
}
QString Signal_Setting::get_name()
{
    return name;
}

void Signal_Setting::set_id(const uint value)
{
    signal_id = value;
}
uint Signal_Setting::get_id()
{
    return signal_id;
}

void Signal_Setting::set_description(const QString value)
{
    description = value;
}
QString Signal_Setting::get_description()
{
    return description;
}

void Signal_Setting::set_offset(const double value)
{
    offset = value;
}

double Signal_Setting::get_offset()
{
    return offset;
}

void Signal_Setting::set_factor(const double value)
{
    factor = value;
}

double Signal_Setting::get_factor()
{
    return factor;
}

void Signal_Setting::set_rawValue(const uint value)
{
    rawValue = value;
    physicalValue = (rawValue*factor)+ offset;

    if(physicalValue > maxValue) {
        physicalValue = maxValue;
        signalStatus = E_NOT_OK_MAX;
    }
    else if (physicalValue < minValue) {
        physicalValue = minValue;
        signalStatus = E_NOT_OK_MIN;
    }
    else {
        signalStatus = E_OK;
    }
}

uint Signal_Setting::get_rawValue()
{
    return rawValue;
}

void Signal_Setting::set_physicalValue(const double value)
{
    if(factor == 0) {
        signalStatus = E_NOT_OK_DIVISION;
        set_rawValue(err_rawValue);
    }
    else {
        if(value > maxValue) {
            physicalValue = maxValue;
            signalStatus = E_NOT_OK_MAX;
        }
        else if (value < minValue) {
            physicalValue = minValue;
            signalStatus = E_NOT_OK_MIN;
        }
        else {
            physicalValue = value;
            signalStatus = E_OK;
        }
        rawValue = (physicalValue - offset) / factor;
    }
}

double Signal_Setting::get_physicalValue()
{
    return physicalValue;
}

void Signal_Setting::set_initRawValue(const uint value)
{
    init_rawValue = value;
}

uint Signal_Setting::get_initRawValue()
{
    return init_rawValue;
}

void Signal_Setting::set_errRawValue(const uint value){
    err_rawValue = value;
}

uint Signal_Setting::get_errRawValue()
{
    return err_rawValue;
}

void Signal_Setting::set_maxValue(const double value)
{
    maxValue = value;
}

double Signal_Setting::get_maxValue()
{
    return maxValue;
}

void Signal_Setting::set_minValue(const double value)
{
    minValue = value;
}

double Signal_Setting::get_minValue()
{
    return minValue;
}

void Signal_Setting::set_signalStatus(const int value)
{
    signalStatus = value;
    if(signalStatus == INIT) {
        set_rawValue(init_rawValue);
        signalStatus = INIT;
    }
}
int Signal_Setting::get_signalStatus()
{
    return signalStatus;
}

