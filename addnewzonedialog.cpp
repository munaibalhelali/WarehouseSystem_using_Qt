#include "addnewzonedialog.h"
#include "ui_addnewzonedialog.h"

AddNewZoneDialog::AddNewZoneDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewZoneDialog)
{
    ui->setupUi(this);
}

AddNewZoneDialog::~AddNewZoneDialog()
{
    delete ui;
}
