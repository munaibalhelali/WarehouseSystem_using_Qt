#include "showavailablestockdialog.h"
#include "ui_showavailablestockdialog.h"
#include <QMessageBox>
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

void ShowAvailableStockDialog::on_okPushButton_clicked()
{
    accept();
}
