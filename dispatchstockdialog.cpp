#include "dispatchstockdialog.h"
#include "ui_dispatchstockdialog.h"
#include <QMessageBox>

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

void DispatchStockDialog::on_savePushButton_clicked()
{
    bool ErrFlag = false;

    if(ErrFlag){
        QMessageBox::warning(this, "Missing information!", "Please make sure you provided all the required information.", QMessageBox::Ok);
    }else{
        accept();
    }
}

void DispatchStockDialog::on_cancelPushButton_clicked()
{
    auto ret = QMessageBox::warning(this, "Cancel dispatch stock?", "Do you want to discard this task?", QMessageBox::Discard, QMessageBox::Cancel|QMessageBox::Default|QMessageBox::Escape);
    if(ret == QMessageBox::Discard){
        reject();
    }
}

void DispatchStockDialog::on_searchPushButton_clicked()
{

}
