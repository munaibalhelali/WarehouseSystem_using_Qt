#include "addnewproductdialog.h"
#include "ui_addnewproductdialog.h"
#include <QMessageBox>
#include "warehouseSystem/product.hpp"
#include "warehouseSystem/databaseSQL.hpp"

AddNewProductDialog::AddNewProductDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewProductDialog)
{
    ui->setupUi(this);
}

AddNewProductDialog::~AddNewProductDialog()
{
    delete ui;
}

void AddNewProductDialog::on_saveButton_clicked()
{
    bool ErrFlag = false;

    if(!ui->productNameLineEdit->text().isEmpty()){
        name = ui->productNameLineEdit->text();
        ui->productNameLineEdit->setStyleSheet(acceptStyle);
    }else{
        ErrFlag = true;
        ui->productNameLineEdit->setStyleSheet(warningStyle);
    }

    if(!ui->ManufacturerLineEdit->text().isEmpty()){
        manufacturer = ui->ManufacturerLineEdit->text();
        ui->ManufacturerLineEdit->setStyleSheet(acceptStyle);
    }else{
        ErrFlag = true;
        ui->ManufacturerLineEdit->setStyleSheet(warningStyle);
    }

    if(ui->sizeComboBox->currentIndex() != 0){
        size = ui->sizeComboBox->currentText();
        ui->sizeComboBox->setStyleSheet(acceptStyle);
    }else{
        ErrFlag = true;
        ui->sizeComboBox->setStyleSheet(warningStyle);
    }

    if(ui->CategoryComboBox->currentIndex() != 0){
        category = ui->CategoryComboBox->currentText();
        ui->CategoryComboBox->setStyleSheet(acceptStyle);
    }else{
        ErrFlag = true;
        ui->CategoryComboBox->setStyleSheet(warningStyle);
    }

    if( !ui->expiryDateEdit->text().isEmpty()){
        expiryDate = ui->expiryDateEdit->text();
        ui->expiryDateEdit->setStyleSheet(acceptStyle);
    }else{
        ErrFlag = true;
        ui->expiryDateEdit->setStyleSheet(warningStyle);
    }

    if(ErrFlag){
        auto ret = QMessageBox::warning(this, "Missing information", "Please make sure you provided all needed data.", QMessageBox::Ok);
    }else{
        saveData();
    }

}

void AddNewProductDialog::on_cancelButton_clicked()
{
    auto ret = QMessageBox::warning(this, "Cancel new product?", "Do you want to discard this task?", QMessageBox::Discard, QMessageBox::Cancel|QMessageBox::Default|QMessageBox::Escape);
    if(ret == QMessageBox::Discard){
        reject();
    }

}

void AddNewProductDialog::on_sizeComboBox_currentIndexChanged(int index)
{
    if(index != 0)
        ui->sizeComboBox->setStyleSheet(acceptStyle);
}

void AddNewProductDialog::on_CategoryComboBox_currentIndexChanged(int index)
{
    if(index != 0)
        ui->CategoryComboBox->setStyleSheet(acceptStyle);
}

void AddNewProductDialog::on_productNameLineEdit_editingFinished()
{
    if(!ui->productNameLineEdit->text().isEmpty())
        ui->productNameLineEdit->setStyleSheet(acceptStyle);
    else
        ui->productNameLineEdit->setStyleSheet(warningStyle);
}

void AddNewProductDialog::on_ManufacturerLineEdit_editingFinished()
{
    if(!ui->ManufacturerLineEdit->text().isEmpty())
        ui->ManufacturerLineEdit->setStyleSheet(acceptStyle);
    else
        ui->ManufacturerLineEdit->setStyleSheet(warningStyle);
}

void AddNewProductDialog::saveData()
{
    DatabaseSQL database;
    std::string id = database.generateID("product");
    Product product(name.toStdString(), id, manufacturer.toStdString(), expiryDate.toStdString(), size.toStdString(), category.toStdString());
    database.addProduct(product);
    accept();

}
