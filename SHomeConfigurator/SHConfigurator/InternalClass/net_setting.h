#ifndef NET_SETTING_H
#define NET_SETTING_H

#include <QString>

class Net_Setting
{
public:
    Net_Setting();
    Net_Setting(QString Name, int ID, QString description);

    QString  get_name();
    int get_id();
    QString get_description();

private:
    QString name;
    int id;
    QString description;
};

#endif // NET_SETTING_H
