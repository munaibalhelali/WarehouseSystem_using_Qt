#ifndef ADMINCONTROLWIDGET_H
#define ADMINCONTROLWIDGET_H

#include <QWidget>

class AdminControlWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AdminControlWidget(QWidget *parent = nullptr);

private slots:
    void addNewUser();
    void removeUser();
    void addNewProduct();
    void removeProduct();
    void addNewZone();
    void removeZone();
    void addStock();
    void dispatchStock();
    void generateReport();

signals:

};

#endif // ADMINCONTROLWIDGET_H
