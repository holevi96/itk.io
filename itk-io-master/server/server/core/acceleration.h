#ifndef ACCELERATION_H
#define ACCELERATION_H
#include <../shared/shared/globalconstants.h>

class Acceleration
{
private:
    float accForward, accPhi;
    int level, size;
public:
    Acceleration();
    void reset();
    void refreshVelocities(float &velForward, float &velPhi, float stepSize, float drag, verticalDirection speedWill, turnDirection turnWill);
    void setLevelAndSize(int level, int size);
};

#endif // ACCELERATION_H
