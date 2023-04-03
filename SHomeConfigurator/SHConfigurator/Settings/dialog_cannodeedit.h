#ifndef DIALOG_CANNODEEDIT_H
#define DIALOG_CANNODEEDIT_H

#include <QDialog>

namespace Ui {
class Dialog_CanNodeEdit;
}

class Dialog_CanNodeEdit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_CanNodeEdit(QWidget *parent = nullptr);
    ~Dialog_CanNodeEdit();

private:
    Ui::Dialog_CanNodeEdit *ui;
};

#endif // DIALOG_CANNODEEDIT_H
