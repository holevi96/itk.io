#ifndef GAMECORE_H
#define GAMECORE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <server/core/globalconstants.h>

class GameCore
{
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


};

#endif // GAMECORE_H
