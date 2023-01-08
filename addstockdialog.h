#ifndef ADDSTOCKDIALOG_H
#define ADDSTOCKDIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include <QTableWidget>
#include "warehouseSystem/databaseSQL.hpp"
namespace Ui {
class AddStockDialog;
}

class AddStockDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStockDialog(QWidget *parent = nullptr);
    ~AddStockDialog();

private slots:
    void on_savePushButton_clicked();

    void on_cancelPushButton_clicked();

    void on_searchPushButton_clicked();

    void on_availableProductsTableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::AddStockDialog *ui;
    DatabaseSQL db;
    QString currentProductID;
    QString zone;
    QString amount;

    QString warningStyle = "border-color: rgb(255,106,77); border-style: solid; border-width: 2px;";
    QString acceptStyle = "border-color: rgb(166,255,77); border-style: solid; border-width: 2px;";

    //private function
    void saveData();
};

#endif // ADDSTOCKDIALOG_H
