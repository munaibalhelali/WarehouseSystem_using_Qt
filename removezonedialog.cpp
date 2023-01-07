#include "removezonedialog.h"
#include "ui_removezonedialog.h"
#include <QMessageBox>
RemoveZoneDialog::RemoveZoneDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveZoneDialog)
{
    ui->setupUi(this);
}

RemoveZoneDialog::~RemoveZoneDialog()
{
    delete ui;
}

void RemoveZoneDialog::on_searchPushButton_clicked()
{

}

void RemoveZoneDialog::on_removePushButton_clicked()
{
    bool ErrFlag = false;

    if(ErrFlag){
        QMessageBox::warning(this, "Missing information!", "Please make sure you provided all the required information.", QMessageBox::Ok);
    }else{
        accept();
    }
}

void RemoveZoneDialog::on_cancelPushButton_clicked()
{
    auto ret = QMessageBox::warning(this, "Cancel remove zone?", "Do you want to discard this task?", QMessageBox::Discard, QMessageBox::Cancel|QMessageBox::Default|QMessageBox::Escape);
    if(ret == QMessageBox::Discard){
        reject();
    }
}
