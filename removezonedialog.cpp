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
    ui->availableZonesTableWidget->setRowCount(0);
    QString searchType;
    if(ui->areaRadioButton->isChecked()){
        searchType = "Area";
    }else if (ui->idRadioButton->isChecked()){
        searchType = "id";
    }

    std::map<std::string, std::vector<std::string>> users = db.search(ui->searchKeywordLineEdit->text().toStdString(), searchType.toStdString(), "zones");

    for(auto user: users){
        if(user.first == "headers"){
            continue;
        }
        int rowCount = ui->availableZonesTableWidget->rowCount();
        ui->availableZonesTableWidget->insertRow(rowCount);

        std::map<std::string, int> stocks = db.getZoneStock(user.second[0]);
        int currZoneStock = 0;
        for(auto stock: stocks){
            currZoneStock += stock.second;
        }

        //ID
        QTableWidgetItem* item = new QTableWidgetItem(QString(user.second[0].c_str()));
        ui->availableZonesTableWidget->setItem(rowCount, 0, item);

        //Stock
        item = new QTableWidgetItem(QString::number(currZoneStock));
        ui->availableZonesTableWidget->setItem(rowCount, 1, item);

        //Area
        item = new QTableWidgetItem(QString(user.second[1].c_str()));
        ui->availableZonesTableWidget->setItem(rowCount, 2, item);

        //Category
        item = new QTableWidgetItem(QString(user.second[2].c_str()));
        ui->availableZonesTableWidget->setItem(rowCount, 3, item);

        //Location
        item = new QTableWidgetItem(QString(user.second[3].c_str()));
        ui->availableZonesTableWidget->setItem(rowCount, 4, item);

    }
    ui->availableZonesTableWidget->sortByColumn(0, Qt::AscendingOrder);
}

void RemoveZoneDialog::on_removePushButton_clicked()
{
    bool ErrFlag = false;

    int rowIndex = ui->availableZonesTableWidget->currentRow();
    QString zoneId = ui->availableZonesTableWidget->item(rowIndex, 0)->text();
    int zoneStock = ui->availableZonesTableWidget->item(rowIndex, 1)->text().toInt();
    if(zoneStock > 0){
        ErrFlag = true;
    }
    if(ErrFlag){
        QMessageBox::warning(this, "Zone is not empty!",
                             "Please make sure no stock in the zone before removing it.",
                             QMessageBox::Ok|QMessageBox::Default|QMessageBox::Escape);
    }else{
        int ret = db.removeZone(zoneId.toStdString());
        if(ret){
            QMessageBox::information(this, "Successful!", "Zone "+ zoneId+" was removed successfully!", QMessageBox::Ok);
            on_searchPushButton_clicked();
        }else{
            QMessageBox::warning(this, "Cannot remove zone "+ zoneId,
                                 "Something went wrong!",
                                 QMessageBox::Ok|QMessageBox::Default|QMessageBox::Escape);
        }
    }
}

void RemoveZoneDialog::on_cancelPushButton_clicked()
{
    auto ret = QMessageBox::warning(this, "Cancel remove zone?", "Do you want to discard this task?", QMessageBox::Discard, QMessageBox::Cancel|QMessageBox::Default|QMessageBox::Escape);
    if(ret == QMessageBox::Discard){
        reject();
    }
}

void RemoveZoneDialog::on_availableZonesTableWidget_itemClicked(QTableWidgetItem *item)
{
    ui->availableZonesTableWidget->selectRow(item->row());
    ui->removePushButton->setEnabled(true);
}
