#include "dialog_cannodeedit.h"
#include "ui_dialog_cannodeedit.h"

Dialog_CanNodeEdit::Dialog_CanNodeEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_CanNodeEdit)
{
    ui->setupUi(this);
}

Dialog_CanNodeEdit::~Dialog_CanNodeEdit()
{
    delete ui;
}
