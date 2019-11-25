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

void Acceleration::refreshVelocities(float &velForward, float &velPhi, float stepSize, float drag, verticalDirection speedWill, bool rightWill, bool leftWill){
    //TODO realisztikusabbá tenni
    if(speedWill!=verticalDirection::REST){
        int a;
        a = 7;
    }
    //velForward*=(1-drag)*stepSize;
    //TODO random konstansok eltüntetése:
    switch (speedWill) {
    case verticalDirection::FORWARD:
        velForward+=1*stepSize*shipSpeed;
        break;
    case verticalDirection::BACKWARD:
        velForward-=1*stepSize*shipSpeed;
    }
    if(leftWill)velPhi+=1*stepSize;
    if(rightWill)velPhi-=1*stepSize;

    return;
}
