#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "admincontrolwidget.h"
#include "workercontrolwidget.h"

#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout* vLayout = new QVBoxLayout();
    ui->controlWidget->setLayout(vLayout);
    setupWelcomeDialog();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::admin()
{
    clearChildren();

    ui->userTypeLabel->setText("Admin: ");
    AdminControlWidget* adminControlWidget = new AdminControlWidget(ui->controlWidget);
    adminControlWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout* vLayout = new QVBoxLayout();
    QLayout* controlWidgetLayout = ui->controlWidget->layout();
    controlWidgetLayout->addWidget(adminControlWidget);
}

void MainWindow::worker()
{
    clearChildren();
    ui->userTypeLabel->setText("Staff: ");
    WorkerControlWidget* workControlWidget = new WorkerControlWidget(this);
    workControlWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->controlWidget->layout()->addWidget(workControlWidget);

}

void MainWindow::setupWelcomeDialog()
{
    QPushButton* adminButton = new QPushButton(ui->controlWidget);
    adminButton->setText("Admin");
    adminButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    connect(adminButton, &QPushButton::clicked, this, &MainWindow::admin);

    QPushButton* workerButton = new QPushButton(ui->controlWidget);
    workerButton->setText("Staff");
    workerButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    connect(workerButton, &QPushButton::clicked, this, &MainWindow::worker);

    QHBoxLayout* hBox = new QHBoxLayout();
    hBox->addWidget(adminButton);
    hBox->addWidget(workerButton);

    ui->controlWidget->layout()->addItem(hBox);

}

void MainWindow::adminControl()
{

}

void MainWindow::workerControl()
{

}

void MainWindow::clearChildren()
{
//    QObjectList children = ui->controlWidget->children();
    QList<QPushButton *> allPButtons = ui->controlWidget->findChildren<QPushButton *>();
    for(auto child: allPButtons){
        child->deleteLater();
    }

}

