#ifndef SHIP_H
#define SHIP_H

#include <map>
#include <set>
#include "acceleration.h"
#include "environment.h"
#include <chrono>
#include "gamecore.h"
#include "shipgraphicitem.h"

using namespace std;
class GameCore;
class Ship
{
public:
    string name;
    int id;
    int life, score, level, damage, reloadTime, maxLife;
    float size, range;
    float locX, locY, phi, velForward, velPhi; //phi fokban értendő
    Acceleration acceleration;
    bool leftCannonsWill, rightCannonsWill, wannaJoin;
    bool leftCannonsReady, rightCannonsReady;
    bool inGame, justSinked;
    bool shootingLeft, shootingRight, gettingHit;
    std::chrono::time_point<std::chrono::steady_clock> lastLeftShoot, lastRightShoot, lastAcceptedHit, lastSinked;
    ShipGraphicItem* shape;
    verticalDirection speedWill;
    turnDirection turnWill;

    void init( GameCore &gameCore);
    void refreshLevel();
    void move(float stepSize, float drag);
    void mayShoot(map<int,Ship> &ships, set<int> &inGameIDs);
    bool checkIfStillInGame();
    bool checkIfWannaJoin(GameCore &GameCore);
    int hitted(int damage);
    ShipGraphicItem* getShape();
    Ship(int _id, string _name);
    Ship();
    bool operator < (Ship const &s2);
    bool operator > (Ship const &s2);
    bool operator == (Ship const &s2);
    bool operator <= (Ship const &s2);
    bool operator >= (Ship const &s2);
    void _startsSink();
};

#endif // SHIP_H
