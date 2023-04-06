#ifndef PLACEMENT_SETTING_H
#define PLACEMENT_SETTING_H

#include <QString>

class Placement_Setting
{
public:
    Placement_Setting();
    Placement_Setting(const QString name, const int id, const QString description);

    QString get_name();
    void set_name(const QString);

    int get_id();
    void set_id(const int);

    QString get_description();
    void set_description(const QString);

private:
    QString name;
    int id;
    QString description;
};

#endif // PLACEMENT_SETTING_H
