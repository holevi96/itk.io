#ifndef GAMECORE_H
#define GAMECORE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <map>
#include <set>

#include "environment.h"
#include <../shared/shared/globalconstants.h>
#include "ship.h"

using namespace std;
class Ship;

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
    GameCore(QObject *parent, int sizeX=10000, int sizeY=10000, float drag=0.1, float stepSize=1,  int msPerStep = 100);
    void playerJoined(int id);
    void joinToGame(int id);
    void quitFromGame(int id);
    void quitFromServer(int id);
    void shoot(int id, fireDirection direction);
    void speed(int id, verticalDirection direction);
    void turn(int id, turnDirection direction);

    int getX(int id);
    int getY(int id);
    int getPhi(int id);
    int getLife(int id);
    int getScore(int id);
    int getLevel(int id);
    int getDamage(int id);
    int getReloadTime(int id);
    int getMaxLife(int id);
    float getSize(int id);
    float getRange(int id);
    std::chrono::time_point<std::chrono::steady_clock> getLastLeftShoot(int id, fireDirection direction);
    fireDirection isShooting(int id);
    bool isGettingHit(int id);
    bool isInGame(int id);
    bool isJustSinked(int id);


    void joinPlayer(string name); //TODO kommunikációs csatornával
    void leftPlayer(int id);
public slots:
    void simulationStep();
signals:
};

#endif // GAMECORE_H