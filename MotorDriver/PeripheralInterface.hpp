#ifndef PERIPH_INTERFACE_H
#define PERIPH_INTERFACE_H

#include <stdint.h>

class IPwm
{
public:
    /* set Pwm value (0 - maxValue) */
    virtual void setValue(uint32_t value) = 0;
    /* get PWM value (0 - maxValue) */
    virtual uint32_t getValue() = 0;
    /* get PWM max value */
    virtual uint32_t maxValue() = 0;
};

class IGpio
{
public:
    /* set gpio to HIGH */
    virtual void set() = 0;
    /* set gpio to LOW */
    virtual void clear() = 0;
    /* get gpio status */
    virtual bool get() = 0;
};

#endif
