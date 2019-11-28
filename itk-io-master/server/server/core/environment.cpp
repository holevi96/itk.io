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
    const int sw = 999; //biztonsági falvastagság mérete
    upperWall = new QGraphicsRectItem(-sw,-sw,2*sw+xSize,sw);
    lowerWall = new QGraphicsRectItem(-sw,ySize,2*sw+xSize,sw);
    leftWall = new QGraphicsRectItem(-sw,-sw,sw,2*sw+ySize);
    rightWall = new QGraphicsRectItem(xSize,-sw,sw,2*sw+ySize);
}
