#ifndef REMOVEUSERDIALOG_H
#define REMOVEUSERDIALOG_H

#include <QDialog>

namespace Ui {
class RemoveUserDialog;
}

class RemoveUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveUserDialog(QWidget *parent = nullptr);
    ~RemoveUserDialog();

private:
    Ui::RemoveUserDialog *ui;
};

#endif // REMOVEUSERDIALOG_H
