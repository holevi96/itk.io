#ifndef CONNECTTOGAME_H
#define CONNECTTOGAME_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class connectToGame;
}

class connectToGame : public QDialog
{
    Q_OBJECT

public:
    explicit connectToGame(MainWindow *window,QWidget *parent = nullptr);
    ~connectToGame();

private slots:
    void on_pushButtonConnectGame_clicked();

private:
    Ui::connectToGame *ui;
    MainWindow *window;
};

#endif // CONNECTTOGAME_H
