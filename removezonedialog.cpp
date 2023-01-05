#include "removezonedialog.h"
#include "ui_removezonedialog.h"

RemoveZoneDialog::RemoveZoneDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveZoneDialog)
{
    ui->setupUi(this);
}

RemoveZoneDialog::~RemoveZoneDialog()
{
    delete ui;
}
