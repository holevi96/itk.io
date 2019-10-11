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
    //TODO
    return;
}
