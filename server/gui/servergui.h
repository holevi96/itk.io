#ifndef SERVERGUI_H
#define SERVERGUI_H

#include <QMainWindow>
#include <server/sn/servernetcommunication.h>

namespace Ui {
class serverGui;
}

class serverGui : public QMainWindow
{
    Q_OBJECT
public:
    serverGui(QWidget *parent = 0);
    void addMessage(QString Msg);
    serverNetCommunication* server;
private slots:
    void on_pushButtonStart_clicked();

private:
    Ui::serverGui *ui;
};

#endif // SERVERGUI_H
