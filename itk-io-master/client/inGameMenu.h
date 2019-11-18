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


signals:

public slots:
};

#endif // INGAMEMENU_H
