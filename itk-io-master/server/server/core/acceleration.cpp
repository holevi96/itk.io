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

void Acceleration::refreshVelocities(float &velForward, float &velPhi, float stepSize, float drag, verticalDirection speedWill, turnDirection turnWill){
    //TODO realisztikusabbá tenni
    if(speedWill!=verticalDirection::REST){
        int a;
        a = 7;
    }
    //velForward*=(1-drag)*stepSize;
    switch (speedWill) {
    case verticalDirection::FORWARD:
        velForward+=stepSize*shipSpeed;
        break;
    case verticalDirection::BACKWARD:
        velForward-=stepSize*shipSpeed;
        break;
    }
    switch (turnWill) {
    case turnDirection::LEFT:
        velPhi+=stepSize*turningSpeed;
        break;
    case turnDirection::RIGHT:
        velPhi-=stepSize*turningSpeed;
        break;
    }
    return;
}
