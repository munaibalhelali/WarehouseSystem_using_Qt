#ifndef DISPATCHSTOCKDIALOG_H
#define DISPATCHSTOCKDIALOG_H

#include <QDialog>

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

private:
    Ui::DispatchStockDialog *ui;
};

#endif // DISPATCHSTOCKDIALOG_H
