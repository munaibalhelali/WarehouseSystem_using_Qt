#include "signinwidget.h"
#include <QPushButton>
#include <QHBoxLayout>

SignInWidget::SignInWidget(QWidget *parent) : QWidget(parent)
{

    adminButton = new QPushButton(this);
    adminButton->setText("Admin");
    adminButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    workerButton = new QPushButton(this);
    workerButton->setText("Staff");
    workerButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    QHBoxLayout* hBox = new QHBoxLayout();
    hBox->addWidget(adminButton);
    hBox->addWidget(workerButton);

    this->setLayout(hBox);


}
