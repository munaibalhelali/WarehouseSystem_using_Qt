#include "addnewproductdialog.h"
#include "ui_addnewproductdialog.h"
#include <QMessageBox>

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


    QString inName = ui->productNameLineEdit->text();
    QString inManufacturer = ui->ManufacturerLineEdit->text();
    int inSize = ui->sizeComboBox->currentIndex();
    int inCategory = ui->CategoryComboBox->currentIndex();
    QString inExpiryDate = ui->expiryDateEdit->text();

    if(!inName.isEmpty() && !inManufacturer.isEmpty()
            && inSize != 0 && inCategory != 0 && !inExpiryDate.isEmpty()){
        name = inName;
        manufacturer = inManufacturer;
        expiryDate = inExpiryDate;
        size = ui->sizeComboBox->currentText();
        category = ui->CategoryComboBox->currentText();
        accept();

    }else{
        if(inName.isEmpty()){
            ui->productNameLineEdit->setStyleSheet(warningStyle);
        }else{
            ui->productNameLineEdit->setStyleSheet(acceptStyle);
        }
        if(inManufacturer.isEmpty()){
            ui->ManufacturerLineEdit->setStyleSheet(warningStyle);
        }else{
            ui->ManufacturerLineEdit->setStyleSheet(acceptStyle);
        }
        if(inSize == 0){
            ui->sizeComboBox->setStyleSheet(warningStyle);
        }else{
            ui->sizeComboBox->setStyleSheet(acceptStyle);
        }
        if(inCategory == 0){
            ui->CategoryComboBox->setStyleSheet(warningStyle);
        }else{
            ui->CategoryComboBox->setStyleSheet(acceptStyle);
        }
        if(inExpiryDate.isEmpty()){
            ui->expiryDateEdit->setStyleSheet(warningStyle);
        }else{
            ui->expiryDateEdit->setStyleSheet(acceptStyle);
        }

        auto ret = QMessageBox::warning(this, "Missing information", "Please make sure you provided all needed data.", QMessageBox::Ok);

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
