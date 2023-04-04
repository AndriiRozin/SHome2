#include "signal_setting.h"
#include <QDebug>

Signal_Setting::Signal_Setting():
    offset(0),
    scale(1),
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

void Signal_Setting::set_scale(const double value)
{
    scale = value;
}

double Signal_Setting::get_scale()
{
    return scale;
}

void Signal_Setting::set_sourceValue(const uint value)
{
    sourceValue = value;
    calculatedValue = (sourceValue*scale)+ offset;

    if(calculatedValue > maxValue) {
        calculatedValue = maxValue;
        signalStatus = E_NOT_OK_MAX;
    }
    else if (calculatedValue < minValue) {
        calculatedValue = minValue;
        signalStatus = E_NOT_OK_MIN;
    }
    else {
        signalStatus = E_OK;
    }
}

uint Signal_Setting::get_sourceValue()
{
    return sourceValue;
}

void Signal_Setting::set_calculatedValue(const double value)
{
    if(scale == 0) {
        signalStatus = E_NOT_OK_DIVISION;
        set_sourceValue(err_sourceValue);
    }
    else {
        if(value > maxValue) {
            calculatedValue = maxValue;
            signalStatus = E_NOT_OK_MAX;
        }
        else if (value < minValue) {
            calculatedValue = minValue;
            signalStatus = E_NOT_OK_MIN;
        }
        else {
            calculatedValue = value;
            signalStatus = E_OK;
        }
        sourceValue = (calculatedValue - offset) / scale;
    }
}

double Signal_Setting::get_calculatedValue()
{
    return calculatedValue;
}

void Signal_Setting::set_initSourceValue(const uint value)
{
    init_sourceValue = value;
}

uint Signal_Setting::get_initSourceValue()
{
    return init_sourceValue;
}

void Signal_Setting::set_errSourceValue(const uint value){
    err_sourceValue = value;
}

uint Signal_Setting::get_errSourceValue()
{
    return err_sourceValue;
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
        set_sourceValue(init_sourceValue);
        signalStatus = INIT;
    }
}
int Signal_Setting::get_signalStatus()
{
    return signalStatus;
}

