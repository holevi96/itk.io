#include "acceleration.h"

Acceleration::Acceleration()
{
    accForward=0;
    accPhi=0;
}

void Acceleration::reset(){
    accForward=0;
    accPhi=0;
}

void Acceleration::refreshVelocities(float &velForward, float &velPhi, float stepSize, float drag, bool forwardWill, bool backwardWill, bool rightWill, bool leftWill){
    //TODO realisztikusabbá tenni

    velForward/=(1-drag)*stepSize;
    //TODO random konstansok eltüntetése:
    if(forwardWill)velForward+=1*stepSize;
    if(backwardWill)velForward-=1*stepSize;
    if(leftWill)velPhi+=1*stepSize;
    if(backwardWill)velPhi-=1*stepSize;

    return;
}
