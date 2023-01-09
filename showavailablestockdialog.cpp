#include "showavailablestockdialog.h"
#include "ui_showavailablestockdialog.h"
#include <QMessageBox>
ShowAvailableStockDialog::ShowAvailableStockDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowAvailableStockDialog)
{
    ui->setupUi(this);
}

ShowAvailableStockDialog::~ShowAvailableStockDialog()
{
    delete ui;
}

void ShowAvailableStockDialog::on_okPushButton_clicked()
{
    accept();
}

void ShowAvailableStockDialog::on_searchPushButton_clicked()
{
    ui->productStockTableWidget->setRowCount(0);
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
        int rowCount = ui->productStockTableWidget->rowCount();
        ui->productStockTableWidget->insertRow(rowCount);

        std::string avId = product.second[0];
        std::string avName = product.second[1];
        std::string avZone = product.second[2];
        std::string avAmount = product.second[3];

        QTableWidgetItem* newItem = new QTableWidgetItem(QString(avId.c_str()));
        ui->productStockTableWidget->setItem(rowCount, 0, newItem);

        newItem = new QTableWidgetItem(QString(avName.c_str()));
        ui->productStockTableWidget->setItem(rowCount, 1, newItem);

        newItem = new QTableWidgetItem(QString(avZone.c_str()));
        ui->productStockTableWidget->setItem(rowCount, 2, newItem);

        newItem = new QTableWidgetItem(QString(avAmount.c_str()));
        ui->productStockTableWidget->setItem(rowCount, 3, newItem);

    }
    ui->productStockTableWidget->sortByColumn(0, Qt::AscendingOrder);
}
