#ifndef INGAMEMENU_H
#define INGAMEMENU_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>

#include "mainwindow.h"

class MainWindow;

class InGameMenu : public QWidget
{
    Q_OBJECT
public:
    explicit InGameMenu(MainWindow *w, QStackedWidget* st);

private:
    MainWindow* window;

    QPushButton* joinButton;

    QLabel* lastScoreLabel,*highScoreLabel;

    int lastScore=0,highScore=0;
public:


signals:

public slots:
    void  setLastScore(int score);
};

#endif // INGAMEMENU_H
