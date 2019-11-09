#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>

#include "login.h"
#include "ingameview.h"
#include "client.h"

class Client;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int gui_width=500, int gui_height=500, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Client *client;
    Login* login;
    IngameView* ingameView;

public slots:
    void startgame();


};
#endif // MAINWINDOW_H
