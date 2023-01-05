#include "workercontrolwidget.h"
#include <QPushButton>
#include <QGridLayout>

WorkerControlWidget::WorkerControlWidget(QWidget *parent) : QWidget(parent)
{

    QPushButton* addStockButton = new QPushButton(this);
    addStockButton->setText("Add stock");
    addStockButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(addStockButton, &QPushButton::clicked, this, &WorkerControlWidget::addStock);

    QPushButton* dispatchStockButton = new QPushButton(this);
    dispatchStockButton->setText("Dispatch stock");
    dispatchStockButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(dispatchStockButton, &QPushButton::clicked, this, &WorkerControlWidget::dispatchStock);

    QPushButton* showAvailableStockButton = new QPushButton(this);
    showAvailableStockButton->setText("Show stock");
    showAvailableStockButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(showAvailableStockButton, &QPushButton::clicked, this, &WorkerControlWidget::showAvailableStock);

    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->addWidget(addStockButton, 0, 0);
    gridLayout->addWidget(dispatchStockButton, 0, 1);
    gridLayout->addWidget(showAvailableStockButton, 1, 0);

    this->setLayout(gridLayout);


}

void WorkerControlWidget::addStock()
{

}

void WorkerControlWidget::dispatchStock()
{

}

void WorkerControlWidget::showAvailableStock()
{

}
