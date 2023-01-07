#ifndef SIGNINWIDGET_H
#define SIGNINWIDGET_H

#include <QWidget>
#include <QPushButton>

class SignInWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SignInWidget(QWidget *parent = nullptr);
    QPushButton* adminButton;
    QPushButton* workerButton;
signals:

};

#endif // SIGNINWIDGET_H
