#include "dispatchstockdialog.h"
#include "ui_dispatchstockdialog.h"

DispatchStockDialog::DispatchStockDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DispatchStockDialog)
{
    ui->setupUi(this);
}

DispatchStockDialog::~DispatchStockDialog()
{
    delete ui;
}
