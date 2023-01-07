#ifndef REMOVEPRODUCTDIALOG_H
#define REMOVEPRODUCTDIALOG_H

#include <QDialog>

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

private:
    Ui::RemoveProductDialog *ui;
};

#endif // REMOVEPRODUCTDIALOG_H
