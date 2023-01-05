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

private:
    Ui::AddNewZoneDialog *ui;
};

#endif // ADDNEWZONEDIALOG_H
