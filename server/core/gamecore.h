#ifndef GAMECORE_H
#define GAMECORE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <map>
#include <set>
#include "ship.h"
#include "environment.h"

using namespace std;

class GameCore : public QObject
{
    Q_OBJECT
private:
    Environment environment;
    map<int, Ship> ships;
    set<int> inGameIDs;
    int nextShipID;
    bool stepInProgress;
public:
    GameCore(QObject *parent);
    void joinPlayer(string name); //TODO kommunikációs csatornával
    void leftPlayer(int id);
public slots:
    void simulationStep();
signals:
};

#endif // GAMECORE_H
