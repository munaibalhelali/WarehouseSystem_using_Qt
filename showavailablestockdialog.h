#ifndef SHOWAVAILABLESTOCKDIALOG_H
#define SHOWAVAILABLESTOCKDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>
#include "warehouseSystem/databaseSQL.hpp"

namespace Ui {
class ShowAvailableStockDialog;
}

class ShowAvailableStockDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowAvailableStockDialog(QWidget *parent = nullptr);
    ~ShowAvailableStockDialog();

private slots:
    void on_okPushButton_clicked();

    void on_searchPushButton_clicked();

private:
    Ui::ShowAvailableStockDialog *ui;
    DatabaseSQL db;
};

#endif // SHOWAVAILABLESTOCKDIALOG_H
