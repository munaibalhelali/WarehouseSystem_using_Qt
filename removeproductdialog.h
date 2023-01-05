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

private:
    Ui::RemoveProductDialog *ui;
};

#endif // REMOVEPRODUCTDIALOG_H
