#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "warehouseSystem/databaseSQL.hpp"
#include "warehouseSystem/person.hpp"
#include <QDateTime>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void admin();
    void worker();
    void signIn(QString);
    void on_logoutPushButton_clicked();
    void updateTimeDateLabel();

private:
    Ui::MainWindow *ui;
    QVBoxLayout* currentControlLayout;
    Person currentUser;
    DatabaseSQL db;
    QDateTime* t;
    QTimer *timer;
    //private methods
    void setupWelcomeDialog();
    void clearChildren();

};
#endif // MAINWINDOW_H
