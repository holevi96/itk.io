#ifndef ACCELERATION_H
#define ACCELERATION_H
#include <../shared/shared/globalconstants.h>

class Acceleration
{
private:
    float accForward, accPhi;
public:
    Acceleration();
    void reset();
    void refreshVelocities(float &velForward, float &velPhi, float stepSize, float drag, verticalDirection speedWill, turnDirection turnWill);
};

#endif // ACCELERATION_H
