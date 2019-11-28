#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QObject>
#include <QGraphicsRectItem>

class Environment
{
private:
    const float defaultDrag=0.0, defaultXSize = 1000, defaultYSize = 1000, defaultMsPerStep = 100, defaultStepSize = 1;
public:
    QGraphicsRectItem *upperWall, *lowerWall, *leftWall, *rightWall;
    float msPerStep, stepSize, xSize, ySize, drag;
    Environment();
    Environment( int _sizeX, int _sizeY, float _drag, float _stepSize,  int _msPerStep);
};

#endif // ENVIRONMENT_H
