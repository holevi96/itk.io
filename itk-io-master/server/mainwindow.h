#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "server/sn/servernetcommunication.h"

namespace Ui {
class MainWindow;
}
class serverNetCommunication;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addMessage(QString Msg);
    serverNetCommunication* m_pBoxServer;

private slots:
    void on_pushButtonStart_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
