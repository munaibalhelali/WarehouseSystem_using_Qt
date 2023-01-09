#ifndef REMOVEUSERDIALOG_H
#define REMOVEUSERDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>

#include "warehouseSystem/databaseSQL.hpp"
namespace Ui {
class RemoveUserDialog;
}

class RemoveUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveUserDialog(QWidget *parent = nullptr);
    ~RemoveUserDialog();

private slots:
    void on_removePushButton_clicked();

    void on_cancelPushButton_clicked();

    void on_searchPushButton_clicked();

    void on_availableUsersTableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::RemoveUserDialog *ui;
    DatabaseSQL db;
};

#endif // REMOVEUSERDIALOG_H
