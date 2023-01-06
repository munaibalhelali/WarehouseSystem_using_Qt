#ifndef ADDSTOCKDIALOG_H
#define ADDSTOCKDIALOG_H

#include <QDialog>
#include <QListWidgetItem>

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

    void on_availableProductsListWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::AddStockDialog *ui;
};

#endif // ADDSTOCKDIALOG_H
