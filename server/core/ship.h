#ifndef SHIP_H
#define SHIP_H

#include <map>
#include <set>
#include "acceleration.h"
#include "environment.h"
#include <chrono>
#include "gamecore.h"
using namespace std;
class GameCore;
class Ship
{
private:
    string name;
    int id;
    int life, score, level, damage, reloadTime, maxLife;
    float size, range;
    float locX, locY, phi, velForward, velPhi;
    Acceleration acceleration;
    bool leftCannonsWill, rightCannonsWill, forwardWill, backwardWill, turningRightWill, turningLeftWill, wannaJoin;
    bool leftCannonsReady, rightCannonsReady;
    bool inGame, justSinked;
    bool shootingLeft, shootingRight, gettingHit;
    std::chrono::time_point<std::chrono::steady_clock> lastLeftShoot, lastRightShoot;

public:
    void init(const Environment &environment);
    void refreshLevel();
    void move(float stepSize, float drag);
    void mayShoot(map<int,Ship> &ships, set<int> &inGameIDs, GameCore &gameCore);
    bool checkIfStillInGame();
    bool checkIfWannaJoin(const Environment &environment);
    int hitted(int damage);
    Ship(int _id, string _name);
    Ship();
};

#endif // SHIP_H
