#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
#include <QTcpSocket>

namespace Ui {
class ConnectDialog;
}

class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDialog(QWidget *parent = nullptr);
    ~ConnectDialog();

private:
    Ui::ConnectDialog *ui;
    QTcpSocket *m_pClientSocket;
private slots:
    void displayError(QAbstractSocket::SocketError socketError);
    void on_pushButtonConnect_clicked();
    void on_pushButtonSend_clicked();
    void readyRead();
};

#endif // CONNECTDIALOG_H


