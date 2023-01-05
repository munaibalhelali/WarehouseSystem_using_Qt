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

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

    void on_sizeComboBox_currentIndexChanged(int index);

    void on_CategoryComboBox_currentIndexChanged(int index);

    void on_productNameLineEdit_editingFinished();

    void on_ManufacturerLineEdit_editingFinished();

private:
    Ui::AddNewProductDialog *ui;
    QString name;
    QString manufacturer;
    QString size;
    QString category;
    QString expiryDate;

    QString warningStyle = "border-color: rgb(255,106,77); border-style: solid; border-width: 2px;";
    QString acceptStyle = "border-color: rgb(166,255,77); border-style: solid; border-width: 2px;";
};

#endif // ADDNEWPRODUCTDIALOG_H
