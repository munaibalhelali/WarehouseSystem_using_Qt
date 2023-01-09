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
        saveData();
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

        QString avId = QString(product.second[0].c_str());
        QString avName = QString(product.second[1].c_str());
        QString avZone = QString(product.second[2].c_str());
        QString avAmount = QString(product.second[3].c_str());

        QTableWidgetItem* newItem = new QTableWidgetItem(QString(avId));
        ui->availableProductsTableWidget->setItem(rowCount, 0, newItem);

        QTableWidgetItem* newItem1 = new QTableWidgetItem(QString(avName));
        ui->availableProductsTableWidget->setItem(rowCount, 1, newItem1);

        QTableWidgetItem* newItem2 = new QTableWidgetItem(QString(avZone));
        ui->availableProductsTableWidget->setItem(rowCount, 2, newItem2);

        QTableWidgetItem* newItem3 = new QTableWidgetItem(QString(avAmount));
        ui->availableProductsTableWidget->setItem(rowCount, 3, newItem3);

    }
    ui->availableProductsTableWidget->sortByColumn(0, Qt::AscendingOrder);

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
    bool ret = db.reduceStock(currentProductID.toStdString(), zone.toStdString(), amount.toInt());
    if(ret){
        QMessageBox::information(this,
                                 "Successful!",
                                 "Product was dispatched successfully!",
                                 QMessageBox::Ok);
    } else{
        QMessageBox::warning(this, "Cannot dispatch stock!",
                             "Please make sure there is enough stock!",
                             QMessageBox::Ok|QMessageBox::Default|QMessageBox::Escape);
    }
    on_searchPushButton_clicked();
}
