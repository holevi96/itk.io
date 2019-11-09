#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QMainWindow>

class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QMainWindow* w);

private:
    QMainWindow* window;
    QPushButton* joinButton;

signals:

public slots:
};

#endif // LOGIN_H
