#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "admincontrolwidget.h"
#include "workercontrolwidget.h"
#include "signinwidget.h"
#include <QPushButton>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateTimeLabel->setStyleSheet("color: white");
    ui->userTypeLabel->setStyleSheet("color: white; font: 16pt \"Ubuntu\";");
    ui->userNameLabel->setStyleSheet("color: white; font: 16pt \"Ubuntu\";");

    t = new QDateTime();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimeDateLabel);
    timer->start(500);

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

void MainWindow::signIn(QString userId)
{

    currentUser = db.getUser(userId.toStdString());
    ui->userNameLabel->setText(QString(currentUser.getName().c_str()));
    if(currentUser.getRole() == "Admin"){
        admin();
    }else{
        worker();
    }
    ui->logoutPushButton->setHidden(false);
}

void MainWindow::setupWelcomeDialog()
{
    clearChildren();
    QVBoxLayout* vLayout = new QVBoxLayout();
    ui->controlWidget->setLayout(vLayout);

    ui->userTypeLabel->setText("Welcome to Warehouse system!");
    ui->userNameLabel->setText("");
    ui->logoutPushButton->setHidden(true);
    SignInWidget* signInWidget = new SignInWidget(this);
    connect(signInWidget, &SignInWidget::successfullSignIn, this, &MainWindow::signIn);

    ui->controlWidget->layout()->addWidget(signInWidget);

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

void MainWindow::updateTimeDateLabel()
{
    ui->dateTimeLabel->setText(t->currentDateTime().toString("dddd dd.MM.yyyy  hh:mm AP"));
}
