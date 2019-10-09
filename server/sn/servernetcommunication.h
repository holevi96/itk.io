#ifndef SERVERNETCOMMUNICATION_H
#define SERVERNETCOMMUNICATION_H

#include <QTcpServer>

class serverNetCommunication : public QTcpServer
{
    Q_OBJECT
public:
    serverNetCommunication(QWidget *parent = 0);
};

#endif // SERVERNETCOMMUNICATION_H
