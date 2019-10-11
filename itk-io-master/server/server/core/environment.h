#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QObject>

class Environment
{
private:
    const float defaultDrag=0.0, defaultXSize = 10, defaultYSize = 10, defaultMsPerStep = 100, defaultStepSize = 1;
public:
    float msPerStep, stepSize, xSize, ySize, drag;
    Environment();
    void generateNewShipLocation(float &locX, float &locY, float &phi) const;
};

#endif // ENVIRONMENT_H
