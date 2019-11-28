#include "mybutton.h"
#include "QPushButton"

myButton::myButton(QWidget *parent) : QMainWindow(parent)
{
    QPushButton *b = new QPushButton("Move down",parent);
    b->setGeometry(300,20,100,50);
    QObject::connect(b, SIGNAL (clicked()), parent, SLOT (button_clicked()));
}
