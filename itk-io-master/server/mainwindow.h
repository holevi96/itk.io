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
    int sentDataFreq;

private slots:
    void on_pushButtonStart_clicked();

    void on_pauseStart_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
