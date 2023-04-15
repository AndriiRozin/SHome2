#ifndef NET_SETTING_H
#define NET_SETTING_H

#include <QString>

class Net_Setting
{
public:
    Net_Setting();
    Net_Setting(QString Name, int ID, QString description);

    QString  get_name();
    void set_name(QString new_name);
    int get_id();
    void set_id(int new_id);
    QString get_description();
    void set_description(QString new_description);

private:
    QString name;
    int id;
    QString description;
};

#endif // NET_SETTING_H
