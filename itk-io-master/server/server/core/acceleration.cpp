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

void Acceleration::setLevelAndSize(int level, int size){
    this->level=level;
    this->size=size;
}

void Acceleration::refreshVelocities(float &velForward, float &velPhi, float stepSize, float drag, verticalDirection speedWill, turnDirection turnWill){
    //TODO realisztikusabbá tenni
    if(speedWill!=verticalDirection::REST){
        int a;
        a = 7;
    }

    float momentum = 3.0/(3+level);

    velForward*=(1-drag*momentum)*stepSize;
    velPhi*=(1-drag*momentum)*stepSize;
    switch (speedWill) {
    case verticalDirection::FORWARD:
        velForward+=stepSize*shipSpeed*momentum;
        break;
    case verticalDirection::BACKWARD:
        velForward-=stepSize*shipSpeed*momentum;
        break;
    }
    switch (turnWill) {
    case turnDirection::LEFT:
        velPhi+=stepSize*turningSpeed*pow(momentum,1.2);
        break;
    case turnDirection::RIGHT:
        velPhi-=stepSize*turningSpeed*pow(momentum,1.2);
        break;
    }

//    float maxVelForward = 20.0/(8+level);
//    if(velForward>maxVelForward)velForward=maxVelForward;
//    if(velForward<-maxVelForward)velForward=-maxVelForward;
    float maxVelForward = 20.0/(8);
    //float maxVelPhi = 20.0/(5);

    float maxVelPhi = 20.0/(5+(level*20));
    if(velPhi>maxVelPhi)velPhi=maxVelPhi;
    if(velPhi<-maxVelPhi)velPhi=-maxVelPhi;

    return;
}
