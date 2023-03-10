#ifndef REPORTDIALOG_HPP
#define REPORTDIALOG_HPP

#include <QDialog>

namespace Ui {
class ReportDialog;
}

class ReportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReportDialog(QWidget *parent = nullptr);
    ~ReportDialog();

private slots:
    void on_exportPushButton_clicked();

    void on_closePushButton_clicked();

    void on_generatePushButton_clicked();

private:
    Ui::ReportDialog *ui;
};

#endif // REPORTDIALOG_HPP
