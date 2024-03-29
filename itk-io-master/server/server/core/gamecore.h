#ifndef GAMECORE_H
#define GAMECORE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <map>
#include <set>
#include <list>
#include <mutex>

#include "environment.h"
#include "globalconstants.h"
#include "ship.h"

#include <cstdlib>
#include <ctime>
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
    list<pair<int,string>> joinQueue;
    list<int> exitQueue;
    mutex joinQueueMutex;
    mutex exitQueueMutex;
public:
    GameCore(int sizeX=env_sizeX, int sizeY=env_sizey, float drag=env_drag, float stepSize=env_stepSize,  int msPerStep = env_msPerStep);
    void playerJoined(int id, string name);
    void joinToGame(int id);
    void quitFromGame(int id);
    void quitFromServer(int id);
    void shoot(int id, fireDirection direction);
    void speed(int id, verticalDirection direction);
    void turn(int id, turnDirection direction);

    void generateNewShipLocation(float &locX, float &locY, float &phi);
    int getX(int id);
    int getY(int id);
    int getPhi(int id);
    int getLife(int id);
    int getScore(int id);
    int getLevel(int id);
    int getDamage(int id);
    int getReloadTime(int id);
    int getRechargeStatus(int id);
    int getRechargeTime(int id);
    int getMaxLife(int id);
    float getSize(int id);
    float getRange(int id);
    long lastHitGot(int id);
    long lastFireLeft(int id);
    long lastFireRight(int id);
    long lastStartedSink(int id);

    //fireDirection isShooting(int id);
    fireDirection getFireCapability(int id);
    //bool isGettingHit(int id);
    bool isInGame(int id);
    //bool isJustSinked(int id);
    Environment getEnvironment();

    //void joinPlayer(string name); //TODO kommunikációs csatornával
    void leftPlayer(int id);
public slots:
    void simulationStep();
signals:
};

#endif // GAMECORE_H
