#ifndef SHOWAVAILABLESTOCKDIALOG_H
#define SHOWAVAILABLESTOCKDIALOG_H

#include <QDialog>

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

private:
    Ui::ShowAvailableStockDialog *ui;
};

#endif // SHOWAVAILABLESTOCKDIALOG_H
