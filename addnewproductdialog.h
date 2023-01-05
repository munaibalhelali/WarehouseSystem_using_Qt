#ifndef ADDNEWPRODUCTDIALOG_H
#define ADDNEWPRODUCTDIALOG_H

#include <QDialog>

namespace Ui {
class AddNewProductDialog;
}

class AddNewProductDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewProductDialog(QWidget *parent = nullptr);
    ~AddNewProductDialog();

private:
    Ui::AddNewProductDialog *ui;
};

#endif // ADDNEWPRODUCTDIALOG_H
