#include "admincontrolwidget.h"
#include <QPushButton>
#include <QGridLayout>
#include <QPalette>
#include <QSizePolicy>

#include "addnewuserdialog.h"
#include "addnewproductdialog.h"

AdminControlWidget::AdminControlWidget(QWidget *parent) : QWidget(parent)
{
    QSizePolicy po;
    po.setHorizontalPolicy(QSizePolicy::Expanding);
    po.setVerticalPolicy(QSizePolicy::Expanding);
    po.setVerticalStretch(1);
    po.setHorizontalStretch(1);
    this->setSizePolicy(po);
    this->setStyleSheet("border-color: rgb(252, 233, 79);");

    QPushButton* addNewUserButton = new QPushButton(this);
    addNewUserButton->setText("Add user");
    addNewUserButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(addNewUserButton, &QPushButton::clicked, this, &AdminControlWidget::addNewUser);

    QPushButton* removeUserButton = new QPushButton(this);
    removeUserButton->setText("Remove user");
    removeUserButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(removeUserButton, &QPushButton::clicked, this, &AdminControlWidget::removeUser);

    QPushButton* addNewProductButton = new QPushButton(this);
    addNewProductButton->setText("Add product");
    addNewProductButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(addNewProductButton, &QPushButton::clicked, this, &AdminControlWidget::addNewProduct);

    QPushButton* removeProductButton = new QPushButton(this);
    removeProductButton->setText("Remove product");
    removeProductButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(removeProductButton, &QPushButton::clicked, this, &AdminControlWidget::removeProduct);

    QPushButton* addNewZoneButton = new QPushButton(this);
    addNewZoneButton->setText("Add zone");
    addNewZoneButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(addNewZoneButton, &QPushButton::clicked, this, &AdminControlWidget::addNewZone);

    QPushButton* removeZoneButton = new QPushButton(this);
    removeZoneButton->setText("Remove zone");
    removeZoneButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(removeZoneButton, &QPushButton::clicked, this, &AdminControlWidget::removeZone);

    QPushButton* generateReportButton = new QPushButton(this);
    generateReportButton->setText("Generate report");
    generateReportButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(generateReportButton, &QPushButton::clicked, this, &AdminControlWidget::generateReport);

    QPushButton* addStockButton = new QPushButton(this);
    addStockButton->setText("Add stock");
    addStockButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(addStockButton, &QPushButton::clicked, this, &AdminControlWidget::addStock);

    QPushButton* dispatchStockButton = new QPushButton(this);
    dispatchStockButton->setText("Dispatch stock");
    dispatchStockButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(dispatchStockButton, &QPushButton::clicked, this, &AdminControlWidget::dispatchStock);

    QGridLayout* gridLayout = new QGridLayout();

    gridLayout->addWidget(addNewUserButton, 0, 0);
    gridLayout->addWidget(removeUserButton, 0, 1);
    gridLayout->addWidget(addNewProductButton, 0, 2);
    gridLayout->addWidget(removeProductButton, 0, 3);
    gridLayout->addWidget(addNewZoneButton, 1, 0);
    gridLayout->addWidget(removeZoneButton, 1, 1);
    gridLayout->addWidget(generateReportButton, 1, 2);
    gridLayout->addWidget(addStockButton, 1, 3);
    gridLayout->addWidget(dispatchStockButton, 2, 0);

    this->setLayout(gridLayout);

}

void AdminControlWidget::addNewUser()
{
    AddNewUserDialog* newUserDialog = new AddNewUserDialog(this);
    newUserDialog->show();
}

void AdminControlWidget::removeUser()
{

}

void AdminControlWidget::addNewProduct()
{
    AddNewProductDialog* newProductDialog = new AddNewProductDialog(this);
    newProductDialog->show();
}

void AdminControlWidget::removeProduct()
{

}

void AdminControlWidget::addNewZone()
{

}

void AdminControlWidget::removeZone()
{

}

void AdminControlWidget::addStock()
{

}

void AdminControlWidget::dispatchStock()
{

}

void AdminControlWidget::generateReport()
{

}
