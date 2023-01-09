#include "removeuserdialog.h"
#include "ui_removeuserdialog.h"
#include <QMessageBox>
#include <QTableWidgetItem>

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
        int rowIndex = ui->availableUsersTableWidget->currentRow();
        QString userId = ui->availableUsersTableWidget->item(rowIndex, 0)->text();
        int ret = db.removeUser(userId.toStdString());
        if(ret){
            QMessageBox::information(this,
                                     "Successful!",
                                     "User was removed successfully!",
                                     QMessageBox::Ok);
            on_searchPushButton_clicked();
        }else{
            QMessageBox::warning(this, "Couldn't remove user!",
                                 "Something went wrong!",
                                 QMessageBox::Ok|QMessageBox::Default|QMessageBox::Escape);
        }
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
    ui->availableUsersTableWidget->setRowCount(0);
    QString searchType;
    if(ui->nameRadioButton->isChecked()){
        searchType = "Name";
    }else if (ui->idRadioButton->isChecked()){
        searchType = "id";
    }

    std::map<std::string, std::vector<std::string>> users = db.search(ui->searchKeywordLineEdit->text().toStdString(), searchType.toStdString(), "persons");

    for(auto user: users){
        if(user.first == "headers"){
            continue;
        }
        int rowCount = ui->availableUsersTableWidget->rowCount();
        ui->availableUsersTableWidget->insertRow(rowCount);

        QTableWidgetItem* item = new QTableWidgetItem(QString(user.second[0].c_str()));
        ui->availableUsersTableWidget->setItem(rowCount, 0, item);

        item = new QTableWidgetItem(QString(user.second[1].c_str()));
        ui->availableUsersTableWidget->setItem(rowCount, 1, item);

        item = new QTableWidgetItem(QString(user.second[2].c_str()));
        ui->availableUsersTableWidget->setItem(rowCount, 2, item);

    }
    ui->availableUsersTableWidget->sortByColumn(0, Qt::AscendingOrder);
}

void RemoveUserDialog::on_availableUsersTableWidget_itemClicked(QTableWidgetItem *item)
{
    ui->removePushButton->setEnabled(true);
    ui->availableUsersTableWidget->selectRow(item->row());
}
