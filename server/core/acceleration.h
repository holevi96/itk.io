#ifndef ACCELERATION_H
#define ACCELERATION_H


class Acceleration
{
private:
    float accForward, accPhi;
public:
    Acceleration();
    void reset();
    void refreshVelocities(float &velForward, float &velPhi, float stepSize, float drag, bool forwardWill, bool backwardWill, bool rightWill, bool leftWill);
};

#endif // ACCELERATION_H
