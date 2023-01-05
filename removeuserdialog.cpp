#include "removeuserdialog.h"
#include "ui_removeuserdialog.h"

RemoveUserDialog::RemoveUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveUserDialog)
{
    ui->setupUi(this);
}

RemoveUserDialog::~RemoveUserDialog()
{
    delete ui;
}
