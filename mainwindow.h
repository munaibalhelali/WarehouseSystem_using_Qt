#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;

    //private methods
    void setupWelcomeDialog();
    void adminControl();
    void workerControl();
    void clearChildren();

};
#endif // MAINWINDOW_H
