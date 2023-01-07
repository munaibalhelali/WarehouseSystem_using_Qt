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

private slots:
    void on_removePushButton_clicked();

    void on_cancelPushButton_clicked();

    void on_searchPushButton_clicked();

private:
    Ui::RemoveUserDialog *ui;
};

#endif // REMOVEUSERDIALOG_H
