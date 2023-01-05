#include "addnewproductdialog.h"
#include "ui_addnewproductdialog.h"

AddNewProductDialog::AddNewProductDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewProductDialog)
{
    ui->setupUi(this);
}

AddNewProductDialog::~AddNewProductDialog()
{
    delete ui;
}
