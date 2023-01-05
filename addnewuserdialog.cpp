#include "addnewuserdialog.h"
#include "ui_addnewuserdialog.h"

AddNewUserDialog::AddNewUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewUserDialog)
{
    ui->setupUi(this);
}

AddNewUserDialog::~AddNewUserDialog()
{
    delete ui;
}
