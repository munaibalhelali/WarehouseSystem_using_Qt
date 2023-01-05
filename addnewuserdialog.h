#ifndef ADDNEWUSERDIALOG_H
#define ADDNEWUSERDIALOG_H

#include <QDialog>

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
    QString Password;
    QString role;

    QList<QString> availableRoles{"Admin", "Staff"};
};

#endif // ADDNEWUSERDIALOG_H
