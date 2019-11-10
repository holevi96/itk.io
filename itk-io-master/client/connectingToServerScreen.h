#ifndef CONNECTINGTOSERVERSCREEN_H
#define CONNECTINGTOSERVERSCREEN_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>

class ConnectingToServerScreen : public QWidget
{
    Q_OBJECT
public:
    explicit ConnectingToServerScreen(QMainWindow* w);

private:
    QMainWindow *window;

    QLabel *label;

signals:

public slots:
};

#endif // CONNECTINGTOSERVERSCREEN_H
