#ifndef REMOVEPRODUCTDIALOG_H
#define REMOVEPRODUCTDIALOG_H

#include <QDialog>
#include "warehouseSystem/databaseSQL.hpp"
#include <QTableWidgetItem>

namespace Ui {
class RemoveProductDialog;
}

class RemoveProductDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveProductDialog(QWidget *parent = nullptr);
    ~RemoveProductDialog();

private slots:
    void on_removePushButton_clicked();

    void on_cancelPushButton_clicked();

    void on_searchPushButton_clicked();

    void on_availableProductsTableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::RemoveProductDialog *ui;

    DatabaseSQL db;
};

#endif // REMOVEPRODUCTDIALOG_H
