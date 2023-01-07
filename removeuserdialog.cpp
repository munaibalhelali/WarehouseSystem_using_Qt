#include "removeuserdialog.h"
#include "ui_removeuserdialog.h"
#include <QMessageBox>
RemoveUserDialog::RemoveUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveUserDialog)
{
    ui->setupUi(this);
}

RemoveUserDialog::~RemoveUserDialog()
{
    delete ui;
}

void RemoveUserDialog::on_removePushButton_clicked()
{
    bool ErrFlag = false;

    if(ErrFlag){
        QMessageBox::warning(this, "Missing information!", "Please make sure you provided all the required information.", QMessageBox::Ok);
    }else{
        accept();
    }
}

void RemoveUserDialog::on_cancelPushButton_clicked()
{
    auto ret = QMessageBox::warning(this, "Cancel remove user?", "Do you want to discard this task?", QMessageBox::Discard, QMessageBox::Cancel|QMessageBox::Default|QMessageBox::Escape);
    if(ret == QMessageBox::Discard){
        reject();
    }
}

void RemoveUserDialog::on_searchPushButton_clicked()
{

}
