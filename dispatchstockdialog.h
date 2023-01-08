#ifndef DISPATCHSTOCKDIALOG_H
#define DISPATCHSTOCKDIALOG_H

#include <QDialog>
#include "warehouseSystem/databaseSQL.hpp"
#include <QTableWidgetItem>

namespace Ui {
class DispatchStockDialog;
}

class DispatchStockDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DispatchStockDialog(QWidget *parent = nullptr);
    ~DispatchStockDialog();

private slots:
    void on_savePushButton_clicked();

    void on_cancelPushButton_clicked();

    void on_searchPushButton_clicked();

    void on_availableProductsTableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::DispatchStockDialog *ui;
    DatabaseSQL db;
    QString currentProductID;
    QString amount;
    QString zone;

    QString warningStyle = "border-color: rgb(255,106,77); border-style: solid; border-width: 2px;";
    QString acceptStyle = "border-color: rgb(166,255,77); border-style: solid; border-width: 2px;";

    //private functions
    void saveData();
};

#endif // DISPATCHSTOCKDIALOG_H
