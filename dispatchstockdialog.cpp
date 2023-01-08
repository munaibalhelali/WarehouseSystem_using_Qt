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
    ui->availableProductsTableWidget->setRowCount(0);
    QString searchType;
    if(ui->nameRadioButton->isChecked()){
        searchType = "Product_name";
    }else if (ui->idRadioButton->isChecked()){
        searchType = "Product_id";
    }else if(ui->zoneIdRadioButton->isChecked()){
        searchType = "Zone_id";
    }

    std::map<std::string, std::vector<std::string>> stock = db.search(ui->searchKeyWordLineEdit->text().toStdString(), searchType.toStdString(), "stock");

    for(auto product: stock){
        if(product.first == "headers"){
            continue;
        }
        int rowCount = ui->availableProductsTableWidget->rowCount();
        ui->availableProductsTableWidget->insertRow(rowCount);

        std::string avId = product.second[0];
        std::string avName = product.second[1];
        std::string avZone = product.second[2];
        std::string avAmount = product.second[3];
        std::cout<<"avs: "<< avId<<", "<<avZone<<", "<<avAmount<<std::endl;

        QTableWidgetItem* newItem = new QTableWidgetItem(QString(avId.c_str()));
        ui->availableProductsTableWidget->setItem(rowCount, 0, newItem);

        newItem = new QTableWidgetItem(QString(avName.c_str()));
        ui->availableProductsTableWidget->setItem(rowCount, 1, newItem);

        newItem = new QTableWidgetItem(QString(avZone.c_str()));
        ui->availableProductsTableWidget->setItem(rowCount, 2, newItem);

        newItem = new QTableWidgetItem(QString(avAmount.c_str()));
        ui->availableProductsTableWidget->setItem(rowCount, 3, newItem);

    }
    ui->availableProductsTableWidget->sortByColumn(0);

}

void DispatchStockDialog::on_availableProductsTableWidget_itemClicked(QTableWidgetItem *item)
{
    ui->availableProductsTableWidget->selectRow(item->row());
    currentProductID = ui->availableProductsTableWidget->item(item->row(), 0)->text();
    std::vector<std::string> zones = db.getProductAvailableZones(currentProductID.toStdString());
    ui->zoneComboBox->clear();
    for(auto zone: zones){
        ui->zoneComboBox->addItem(QString(zone.c_str()));
    }
    ui->amountSpinBox->setEnabled(true);
    ui->zoneComboBox->setEnabled(true);
}

void DispatchStockDialog::saveData(){
    db.addStock(currentProductID.toStdString(), zone.toStdString(), amount.toInt());
    accept();
}
