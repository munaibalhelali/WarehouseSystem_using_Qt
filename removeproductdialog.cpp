#include "removeproductdialog.h"
#include "ui_removeproductdialog.h"

RemoveProductDialog::RemoveProductDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveProductDialog)
{
    ui->setupUi(this);
}

RemoveProductDialog::~RemoveProductDialog()
{
    delete ui;
}
