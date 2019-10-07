#ifndef SERVERNETCOMMUNICATION_H
#define SERVERNETCOMMUNICATION_H

#include <QTcpServer>

class serverNetCommunication : public QTcpServer
{
public:
    Q_OBJECT

    serverNetCommunication();
};

#endif // SERVERNETCOMMUNICATION_H
