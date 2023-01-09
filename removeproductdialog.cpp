#include "removeproductdialog.h"
#include "ui_removeproductdialog.h"
#include <QMessageBox>
#include <QDebug>

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
        int rowIndex = ui->availableProductsTableWidget->currentRow();
        QString productID = ui->availableProductsTableWidget->item(rowIndex, 0)->text();
        int stock =db.getProductStock(productID.toStdString());
        if(stock == 0){
            bool ret = db.removeProduct(productID.toStdString());
            if(ret){
                QMessageBox::information(this,
                                         "Successful!",
                                         "Product was removed successfully!",
                                         QMessageBox::Ok);
                on_searchPushButton_clicked();
            }
        }else{
            QMessageBox::warning(this, "Product stock is not zero!",
                                 "Please make sure the product stock is zero before you remove the product.",
                                 QMessageBox::Ok|QMessageBox::Default|QMessageBox::Escape);
        }

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
    ui->availableProductsTableWidget->setRowCount(0);
    QString searchType;
    if(ui->nameRadioButton->isChecked()){
        searchType = "Product_name";
    }else if (ui->idRadioButton->isChecked()){
        searchType = "Product_id";
    }else if(ui->categoryRadioButton->isChecked()){
        searchType = "Category";
    }

    std::map<std::string, std::vector<std::string>> stock = db.search(ui->searchKeywordLineEdit->text().toStdString(), searchType.toStdString(), "stock");

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
    ui->availableProductsTableWidget->sortByColumn(0, Qt::AscendingOrder);

}

void RemoveProductDialog::on_availableProductsTableWidget_itemClicked(QTableWidgetItem *item)
{
    ui->removePushButton->setEnabled(true);
    ui->availableProductsTableWidget->selectRow(item->row());
}
