#ifndef REMOVEZONEDIALOG_H
#define REMOVEZONEDIALOG_H

#include <QDialog>

namespace Ui {
class RemoveZoneDialog;
}

class RemoveZoneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveZoneDialog(QWidget *parent = nullptr);
    ~RemoveZoneDialog();

private slots:
    void on_searchPushButton_clicked();

    void on_removePushButton_clicked();

    void on_cancelPushButton_clicked();

private:
    Ui::RemoveZoneDialog *ui;
};

#endif // REMOVEZONEDIALOG_H
