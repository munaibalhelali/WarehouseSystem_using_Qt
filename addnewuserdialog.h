#ifndef ADDNEWUSERDIALOG_H
#define ADDNEWUSERDIALOG_H

#include <QDialog>
#include "warehouseSystem/databaseSQL.hpp"

namespace Ui {
class AddNewUserDialog;
}

class AddNewUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewUserDialog(QWidget *parent = nullptr);
    ~AddNewUserDialog();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::AddNewUserDialog *ui;
    QString name;
    QString password;
    QString role;
    DatabaseSQL database;

    QList<QString> availableRoles{"Admin", "Staff"};

    QString warningStyle = "border-color: rgb(255,106,77); border-style: solid; border-width: 2px;";
    QString acceptStyle = "border-color: rgb(166,255,77); border-style: solid; border-width: 2px;";

    //private functions
    void saveData();
};

#endif // ADDNEWUSERDIALOG_H
