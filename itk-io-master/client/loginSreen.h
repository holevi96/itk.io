#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QMainWindow>
#include <QLineEdit>

class LoginScreen : public QWidget
{
    Q_OBJECT
public:
    QString getName();
    QString getIP();
    int getPort();

    explicit LoginScreen(QMainWindow* w);

private:
    int lineWidth=200;
    int lineHeight=25;

    QMainWindow* window;
    QLineEdit* nameBox;
    QLineEdit* ipBox;
    QLineEdit* portBox;
    QPushButton* joinButton;

signals:

public slots:
};

#endif // LOGIN_H
