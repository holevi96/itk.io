#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QLineEdit>

#include "mainwindow.h"

class MainWindow;

class LoginScreen : public QWidget
{
    Q_OBJECT
public:
    QString getName();
    QString getIP();
    int getPort();

    explicit LoginScreen(MainWindow* w, QStackedWidget* st);

private:
    int lineWidth=200;
    int lineHeight=25;

    MainWindow* window;

    QLineEdit* nameBox;
    QLineEdit* ipBox;
    QLineEdit* portBox;
    QPushButton* joinButton;

signals:

public slots:
};

#endif // LOGIN_H
