#include "environment.h"

Environment::Environment()
{
    xSize = defaultXSize;
    ySize = defaultYSize;
    msPerStep = defaultMsPerStep;
    stepSize = defaultStepSize;
    drag = defaultDrag;
}

Environment::Environment( int _sizeX, int _sizeY, float _drag, float _stepSize,  int _msPerStep){
    xSize=_sizeX;
    ySize=_sizeY;
    drag=_drag;
    stepSize=_stepSize;
    msPerStep=_msPerStep;
}

void Environment::generateNewShipLocation(float &locX, float &locY, float &phi) const{
    //TODO
    locX=0;
    locY=0;
    phi=0;
}
