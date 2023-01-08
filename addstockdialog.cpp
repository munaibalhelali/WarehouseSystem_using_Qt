#include "addstockdialog.h"
#include "ui_addstockdialog.h"
#include <QMessageBox>
#include "warehouseSystem/zone.hpp"
#include "warehouseSystem/databaseSQL.hpp"

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

    if(ui->amountSpinBox->text().toInt() != 0){
        amount = ui->amountSpinBox->text();
        ui->amountSpinBox->setStyleSheet(acceptStyle);
    }else{
        ui->amountSpinBox->setStyleSheet(warningStyle);
        ErrFlag = true;
    }

    if(ui->zoneComboBox->currentIndex() != -1){
        zone = ui->zoneComboBox->currentText();
        ui->zoneComboBox->setStyleSheet(acceptStyle);
    }else{
        ui->zoneComboBox->setStyleSheet(warningStyle);
        ErrFlag = true;
    }

    if(ErrFlag){
        QMessageBox::warning(this, "Missing information!", "Please make sure you provided all the required information.", QMessageBox::Ok);
    }else{
        saveData();
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
    QString searchType;
    if(ui->nameRadioButton->isChecked()){
        searchType = "Name";
    }else if (ui->idRadioButton->isChecked()){
        searchType = "id";
    }else if(ui->categoryRadioButton->isChecked()){
        searchType = "Category";
    }
    ui->availableProductsTableWidget->setRowCount(0);

    std::map<std::string, std::vector<std::string>> products = db.search(ui->searchKeywordLineEdit->text().toStdString(), searchType.toStdString(), "products");

    for(auto product: products){
        if(product.first == "headers"){
            continue;
        }
        int columns = 0;
        int rowCount = ui->availableProductsTableWidget->rowCount();
        ui->availableProductsTableWidget->insertRow(rowCount);
        for(auto data: product.second){
            QTableWidgetItem* newItem = new QTableWidgetItem(QString(data.c_str()));
            ui->availableProductsTableWidget->setItem(rowCount, columns, newItem);
            columns++;
        }
    }
}


void AddStockDialog::saveData()
{
    db.addStock(currentProductID.toStdString(), zone.toStdString(), amount.toInt());
    accept();
}

void AddStockDialog::on_availableProductsTableWidget_itemClicked(QTableWidgetItem *item)
{
    ui->availableProductsTableWidget->selectRow(item->row());
    currentProductID = ui->availableProductsTableWidget->item(item->row(), 0)->text();
    std::vector<std::string> zones = db.getAvailableZones();
    ui->zoneComboBox->clear();
    for(auto zone: zones){
        ui->zoneComboBox->addItem(QString(zone.c_str()));
    }
    ui->amountSpinBox->setEnabled(true);
    ui->zoneComboBox->setEnabled(true);
    ui->expiryDateEdit->setEnabled(true);
}
