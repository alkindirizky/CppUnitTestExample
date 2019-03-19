#include <MotorDriver.hpp>
#include <PeripheralInterface.hpp>
#include <catch.hpp>
#include <fakeit.hpp>

using namespace fakeit;

TEST_CASE("Motor Direction")
{
    MotorDriver motor;
    Mock<IGpio> gpio;
    Mock<IPwm> pwm;
    uint32_t pwmMaxValue = 65535;

    /* Initialize Motor Driver */
    motor.initialize(&(pwm.get()), &(gpio.get()), 100);

    /* Mockups Called Funcions (pwm->maxValue, pwm->setValue, pwm->set, pwm->clear)*/
    When(Method(pwm, maxValue)).AlwaysReturn(pwmMaxValue);
    Fake(Method(pwm, setValue)); //same with When(Method(pwm, maxValue)).AlwaysReturn()

    SECTION("Forward")
    {
        motor.rotate(10, true);
        Verify(Method(gpio, set));
    }
}
