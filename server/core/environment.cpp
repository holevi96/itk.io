#include "environment.h"

Environment::Environment()
{
    xSize = defaultXSize;
    ySize = defaultYSize;
    msPerStep = defaultMsPerStep;
    stepSize = defaultStepSize;
    drag = defaultDrag;
}

void Environment::generateNewShipLocation(float &locX, float &locY, float &phi) const{
    //TODO
    locX=0;
    locY=0;
    phi=0;
}
