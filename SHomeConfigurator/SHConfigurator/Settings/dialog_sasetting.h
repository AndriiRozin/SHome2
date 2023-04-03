#ifndef DIALOG_SASETTING_H
#define DIALOG_SASETTING_H

#include <QDialog>

namespace Ui {
class Dialog_SAsetting;
}

class Dialog_SAsetting : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_SAsetting(QWidget *parent = nullptr);
    ~Dialog_SAsetting();

private:
    Ui::Dialog_SAsetting *ui;
};

#endif // DIALOG_SASETTING_H
