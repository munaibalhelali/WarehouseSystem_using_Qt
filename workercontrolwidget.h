#ifndef WORKERCONTROLWIDGET_H
#define WORKERCONTROLWIDGET_H

#include <QWidget>

class WorkerControlWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WorkerControlWidget(QWidget *parent = nullptr);

private slots:
    void addStock();
    void dispatchStock();
    void showAvailableStock();

signals:

};

#endif // WORKERCONTROLWIDGET_H
