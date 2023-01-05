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

private:
    Ui::RemoveZoneDialog *ui;
};

#endif // REMOVEZONEDIALOG_H
