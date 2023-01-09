#ifndef SIGNINWIDGET_H
#define SIGNINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "ui_signinwidget.h"
#include "warehouseSystem/databaseSQL.hpp"

namespace Ui {
class SignInWidget;
}
class SignInWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SignInWidget(QWidget *parent = nullptr);
    ~SignInWidget();
    QPushButton* adminButton;
    QPushButton* workerButton;
signals:
    void successfullSignIn(QString);

private slots:
    void on_signInPushButton_clicked();

private:
    Ui::SignInWidget* ui;
    DatabaseSQL db;

    QString warningStyle = "border-color: rgb(255,106,77); border-style: solid; border-width: 2px;";
    QString acceptStyle = "border-color: rgb(166,255,77); border-style: solid; border-width: 2px;";
};

#endif // SIGNINWIDGET_H
