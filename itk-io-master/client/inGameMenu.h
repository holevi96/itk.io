#ifndef INGAMEMENU_H
#define INGAMEMENU_H

#include <QWidget>
#include <QMainWindow>

class InGameMenu : public QWidget
{
    Q_OBJECT
public:
    explicit InGameMenu(QMainWindow *w);

private:
    QMainWindow* window;

signals:

public slots:
};

#endif // INGAMEMENU_H
