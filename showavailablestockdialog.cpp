#include "showavailablestockdialog.h"
#include "ui_showavailablestockdialog.h"

ShowAvailableStockDialog::ShowAvailableStockDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowAvailableStockDialog)
{
    ui->setupUi(this);
}

ShowAvailableStockDialog::~ShowAvailableStockDialog()
{
    delete ui;
}
