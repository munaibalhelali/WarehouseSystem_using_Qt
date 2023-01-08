#include "addnewzonedialog.h"
#include "ui_addnewzonedialog.h"

#include <QMessageBox>
#include "warehouseSystem/databaseSQL.hpp"
#include "warehouseSystem/zone.hpp"
#include <QDebug>

AddNewZoneDialog::AddNewZoneDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewZoneDialog)
{
    ui->setupUi(this);
}

AddNewZoneDialog::~AddNewZoneDialog()
{
    delete ui;
}

void AddNewZoneDialog::on_saveButton_clicked()
{
    bool ErrFlag = false;

    if(!ui->nameLineEdit->text().isEmpty()){
      name = ui->nameLineEdit->text();
      ui->nameLineEdit->setStyleSheet(acceptStyle);
    }  else{
      ui->nameLineEdit->setStyleSheet(warningStyle);
      ErrFlag = true;
    }

    if(ui->areaComboBox->currentIndex() != 0){
        area = "area_"+ui->areaComboBox->currentText();
        ui->areaComboBox->setStyleSheet(acceptStyle);
    }else{
        ui->areaComboBox->setStyleSheet(warningStyle);
        ErrFlag = true;
    }

    if(ui->categoryComboBox->currentIndex() != 0){
        category = ui->categoryComboBox->currentText();
        ui->categoryComboBox->setStyleSheet(acceptStyle);
    }else{
        ui->categoryComboBox->setStyleSheet(warningStyle);
        ErrFlag = true;
    }

    if(!ui->locationLineEdit->text().isEmpty()){
        location = ui->locationLineEdit->text();
        ui->locationLineEdit->setStyleSheet(acceptStyle);
    }else{
        ui->locationLineEdit->setStyleSheet(warningStyle);
        ErrFlag = true;
    }
    if(ErrFlag){
        QMessageBox::warning(this, "Missing information!", "Please make sure you provided all the required information.", QMessageBox::Ok);
    }else{
        saveData();
    }
}

void AddNewZoneDialog::on_cancelButton_clicked()
{
    auto ret = QMessageBox::warning(this, "Cancel new zone?", "Do you want to discard this task?", QMessageBox::Discard, QMessageBox::Cancel|QMessageBox::Default|QMessageBox::Escape);
    if(ret == QMessageBox::Discard){
        reject();
    }
}

void AddNewZoneDialog::saveData()
{
    DatabaseSQL database;
    std::string id = database.generateID("zone");
    std::map<std::string, int> stock;
    Zone zone(id, area.toStdString(), category.toStdString(), location.toStdString(), stock);
    database.addZone(zone);
    accept();

}
