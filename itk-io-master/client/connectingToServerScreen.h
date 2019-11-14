#ifndef CONNECTINGTOSERVERSCREEN_H
#define CONNECTINGTOSERVERSCREEN_H

#include <QStackedWidget>
#include <QWidget>
#include <QLabel>

#include "mainwindow.h"

class MainWindow;

class ConnectingToServerScreen : public QWidget
{
    Q_OBJECT
public:
    explicit ConnectingToServerScreen(MainWindow* w, QStackedWidget* st);

private:
    MainWindow *window;

    QLabel *label;

signals:

public slots:
};

#endif // CONNECTINGTOSERVERSCREEN_H
