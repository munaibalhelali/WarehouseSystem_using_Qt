#ifndef ADDNEWZONEDIALOG_H
#define ADDNEWZONEDIALOG_H

#include <QDialog>

namespace Ui {
class AddNewZoneDialog;
}

class AddNewZoneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewZoneDialog(QWidget *parent = nullptr);
    ~AddNewZoneDialog();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::AddNewZoneDialog *ui;

    QString name;
    QString area;
    QString category;
    QString location;

    QString warningStyle = "border-color: rgb(255,106,77); border-style: solid; border-width: 2px;";
    QString acceptStyle = "border-color: rgb(166,255,77); border-style: solid; border-width: 2px;";

};

#endif // ADDNEWZONEDIALOG_H
