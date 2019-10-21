#include "connecttogame.h"
#include "ui_connecttogame.h"

connectToGame::connectToGame(MainWindow *window,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectToGame),
    window(window)
{
    ui->setupUi(this);
}

connectToGame::~connectToGame()
{
    delete ui;
}

void connectToGame::on_pushButtonConnectGame_clicked()
{

}
