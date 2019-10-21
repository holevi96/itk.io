#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QTcpSocket>
#include <mainwindow.h>
namespace Ui {
class ConnectDialog;
}

class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDialog(MainWindow *window,QWidget *parent = nullptr);
    ~ConnectDialog();
private:
    Ui::ConnectDialog *ui;

    MainWindow *window;
private slots:

    void on_pushButtonConnect_clicked();


};

#endif // CONNECTDIALOG_H


