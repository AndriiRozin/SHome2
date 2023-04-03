#include "dialog_sasetting.h"
#include "ui_dialog_sasetting.h"

Dialog_SAsetting::Dialog_SAsetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_SAsetting)
{
    ui->setupUi(this);
}

Dialog_SAsetting::~Dialog_SAsetting()
{
    delete ui;
}
