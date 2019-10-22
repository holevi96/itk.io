#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QObject>

class Environment
{
private:
    const float defaultDrag=0.0, defaultXSize = 1000, defaultYSize = 1000, defaultMsPerStep = 100, defaultStepSize = 1;
public:
    float msPerStep, stepSize, xSize, ySize, drag;
    Environment();
    Environment( int _sizeX, int _sizeY, float _drag, float _stepSize,  int _msPerStep);
    void generateNewShipLocation(float &locX, float &locY, float &phi) const;
};

#endif // ENVIRONMENT_H
