#include "connecttogame.h"
#include "ui_connecttogame.h"

connectToGame::connectToGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectToGame)
{
    ui->setupUi(this);
}

connectToGame::~connectToGame()
{
    delete ui;
}
