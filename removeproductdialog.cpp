#include "removeproductdialog.h"
#include "ui_removeproductdialog.h"
#include <QMessageBox>
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

void RemoveProductDialog::on_removePushButton_clicked()
{
    bool ErrFlag = false;

    if(ErrFlag){
        QMessageBox::warning(this, "Missing information!", "Please make sure you provided all the required information.", QMessageBox::Ok);
    }else{
        accept();
    }
}

void RemoveProductDialog::on_cancelPushButton_clicked()
{
    auto ret = QMessageBox::warning(this, "Cancel remove product?", "Do you want to discard this task?", QMessageBox::Discard, QMessageBox::Cancel|QMessageBox::Default|QMessageBox::Escape);
    if(ret == QMessageBox::Discard){
        reject();
    }
}

void RemoveProductDialog::on_searchPushButton_clicked()
{

}
