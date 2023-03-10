#include "addnewuserdialog.h"
#include "ui_addnewuserdialog.h"
#include <QMessageBox>

AddNewUserDialog::AddNewUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewUserDialog)
{
    ui->setupUi(this);
    ui->adminRadioButton->setChecked(true);
}

AddNewUserDialog::~AddNewUserDialog()
{
    delete ui;
}

void AddNewUserDialog::on_saveButton_clicked()
{
    QString inName =  ui->nameLineEdit->text();
    QString inPassword = ui->passwordLineEdit->text();
    QString inConfPassword = ui->confirmPasswordLineEdit->text();
    bool adminRadio = ui->adminRadioButton->isChecked();
    bool staffRadio = ui->staffRadioButton->isChecked();
    if (!inName.isEmpty() && !inPassword.isEmpty() && inPassword == inConfPassword){
        name = inName;
        password = inPassword;
        if(adminRadio){
            role = ui->adminRadioButton->text();
        }else if(staffRadio){
            role = ui->staffRadioButton->text();
        }
        saveData();
    }else if(!inPassword.isEmpty() && inPassword != inConfPassword){
        ui->confirmPasswordLineEdit->setStyleSheet("background:rgb(255,106,77)");
    }else{
        auto ret = QMessageBox::warning(this, "Missing information", "Please make sure you provided all needed data.", QMessageBox::Ok);

    }

}

void AddNewUserDialog::on_cancelButton_clicked()
{
    auto ret = QMessageBox::warning(this, "Cancel new user?", "Do you want to discard this task?", QMessageBox::Discard, QMessageBox::Cancel|QMessageBox::Default|QMessageBox::Escape);
    if(ret == QMessageBox::Discard){
        reject();
    }

}

void AddNewUserDialog::saveData()
{
    std::string id = database.generateID("person");
    Person person(name.toStdString(), id, role.toStdString(), password.toStdString());
    bool ret = database.addUser(person);
    if(ret){
        QMessageBox::information(this,
                                 "Successful!",
                                 "New user was recored!",
                                 QMessageBox::Ok);
    }
}
