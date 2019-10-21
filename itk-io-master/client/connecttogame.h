#ifndef CONNECTTOGAME_H
#define CONNECTTOGAME_H

#include <QDialog>

namespace Ui {
class connectToGame;
}

class connectToGame : public QDialog
{
    Q_OBJECT

public:
    explicit connectToGame(QWidget *parent = nullptr);
    ~connectToGame();

private:
    Ui::connectToGame *ui;
};

#endif // CONNECTTOGAME_H
