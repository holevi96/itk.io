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
