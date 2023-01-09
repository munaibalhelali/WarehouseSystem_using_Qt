#include "signinwidget.h"

#include <QPushButton>
#include <QHBoxLayout>
#include "warehouseSystem/person.hpp"
#include <QDebug>
SignInWidget::SignInWidget(QWidget *parent) : QWidget(parent), ui(new Ui::SignInWidget)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
}

SignInWidget::~SignInWidget(){
    delete ui;
}

void SignInWidget::on_signInPushButton_clicked()
{
    QString userId = ui->userIDLineEdit->text();
    if(!userId.isEmpty()){
       Person person = db.getUser(userId.toStdString());
       if(person.isEmpty()){
           ui->userIDLineEdit->setStyleSheet(warningStyle);
           ui->notesLabel->setText("ERROR: User ID does not exist!");
           ui->notesLabel->setStyleSheet("color: red;");
       }else{
           QString password = ui->passwordLineEdit->text();
           bool ret = person.isPasswordCorrect(password.toStdString());
           if(ret){
               emit successfullSignIn(userId);
           }else {
              ui->passwordLineEdit->setStyleSheet(warningStyle);
              ui->notesLabel->setText("Error: Wrong password!");
              ui->notesLabel->setStyleSheet("color: red;");
           }
       }

    }
}

void SignInWidget::on_passwordLineEdit_cursorPositionChanged(int arg1, int arg2)
{

}
