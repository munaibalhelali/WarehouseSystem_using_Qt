#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "admincontrolwidget.h"
#include "workercontrolwidget.h"
#include "signinwidget.h"

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

    QVBoxLayout* vLayout = new QVBoxLayout();
    ui->controlWidget->setLayout(vLayout);

    ui->userTypeLabel->setText("Admin: ");
    AdminControlWidget* adminControlWidget = new AdminControlWidget(ui->controlWidget);
    adminControlWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QLayout* controlWidgetLayout = ui->controlWidget->layout();
    controlWidgetLayout->addWidget(adminControlWidget);
}

void MainWindow::worker()
{
    clearChildren();

    QVBoxLayout* vLayout = new QVBoxLayout();
    ui->controlWidget->setLayout(vLayout);

    ui->userTypeLabel->setText("Staff: ");
    WorkerControlWidget* workControlWidget = new WorkerControlWidget(this);
    workControlWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->controlWidget->layout()->addWidget(workControlWidget);

}

void MainWindow::setupWelcomeDialog()
{
    clearChildren();
    QVBoxLayout* vLayout = new QVBoxLayout();
    ui->controlWidget->setLayout(vLayout);

    ui->userTypeLabel->setText("Welcome to Warehouse system!");
    ui->userNameLabel->setText("");
    SignInWidget* signInWidget = new SignInWidget(this);
    connect(signInWidget->adminButton, &QPushButton::clicked, this, &MainWindow::admin);
    connect(signInWidget->workerButton, &QPushButton::clicked, this, &MainWindow::worker);
    ui->controlWidget->layout()->addWidget(signInWidget);

}

void MainWindow::adminControl()
{

}

void MainWindow::workerControl()
{

}

void MainWindow::clearChildren()
{

    if ( ui->controlWidget->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->controlWidget->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        delete ui->controlWidget->layout();
    }


}


void MainWindow::on_logoutPushButton_clicked()
{
    setupWelcomeDialog();
}
