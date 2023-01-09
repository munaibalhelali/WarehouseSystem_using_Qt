#ifndef REMOVEZONEDIALOG_H
#define REMOVEZONEDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>
#include "warehouseSystem/databaseSQL.hpp"

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

    void on_availableZonesTableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::RemoveZoneDialog *ui;
    DatabaseSQL db;
};

#endif // REMOVEZONEDIALOG_H
