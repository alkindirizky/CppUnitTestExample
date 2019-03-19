#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <PeripheralInterface.hpp>

/* Motor driver class, for simplicity sake, 1 radps is equal to 1 percent pwm, gpio HIGH is forward */
class MotorDriver
{
public:
    MotorDriver();

    /* initialize motor */
    void initialize(IPwm *pMotorPwm, IGpio *pDirGpio, float maxSpeed);
    /* rotate the motor with speed and direction, set dir true for forward movement */
    void rotate(float radps, bool forwardDir);
    /* stop the motor */
    void stop();

private:
    IPwm *m_pPwm;
    IGpio *m_pGpio;
    float m_maxSpeed;
};

#endif
