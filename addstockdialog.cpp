#include "addstockdialog.h"
#include "ui_addstockdialog.h"
#include <QMessageBox>

AddStockDialog::AddStockDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStockDialog)
{
    ui->setupUi(this);
}

AddStockDialog::~AddStockDialog()
{
    delete ui;
}

void AddStockDialog::on_savePushButton_clicked()
{
    bool ErrFlag = false;


    if(ErrFlag){
        QMessageBox::warning(this, "Missing information!", "Please make sure you provided all the required information.", QMessageBox::Ok);
    }else{
        accept();
    }

}

void AddStockDialog::on_cancelPushButton_clicked()
{
    auto ret = QMessageBox::warning(this, "Cancel new stock?", "Do you want to discard this task?", QMessageBox::Discard, QMessageBox::Cancel|QMessageBox::Default|QMessageBox::Escape);
    if(ret == QMessageBox::Discard){
        reject();
    }
}

void AddStockDialog::on_searchPushButton_clicked()
{

}

void AddStockDialog::on_availableProductsListWidget_itemClicked(QListWidgetItem *item)
{
    ui->amountSpinBox->setEnabled(true);
    ui->zoneComboBox->setEnabled(true);
    ui->expiryDateEdit->setEnabled(true);
}
