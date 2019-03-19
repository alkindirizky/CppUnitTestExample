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

    /* Mockups Behaviour */
    When(Method(pwm, maxValue)).AlwaysReturn(pwmMaxValue);
    Fake(Method(pwm, setValue));
    Fake(Method(gpio, set));
    Fake(Method(gpio, clear));

    SECTION("Forward")
    {
        motor.rotate(10, true);
        Verify(Method(gpio, set));
    }

    SECTION("Backward")
    {
        motor.rotate(10, false);
        Verify(Method(gpio, clear));
    }
}

TEST_CASE("Motor Speed")
{
    const uint32_t pwmTolerance = 5;
    MotorDriver motor;
    Mock<IGpio> gpio;
    Mock<IPwm> pwm;
    uint32_t pwmMaxValue = 65535;
    float maxRadps = 100;

    /* Initialize Motor Driver */
    motor.initialize(&(pwm.get()), &(gpio.get()), maxRadps);

    /* Mockups Behaviour */
    When(Method(pwm, maxValue)).AlwaysReturn(pwmMaxValue);
    Fake(Method(pwm, setValue));
    Fake(Method(gpio, set));
    Fake(Method(gpio, clear));

    SECTION("Zero Speed & Stop")
    {
        motor.rotate(0, true);
        Verify(Method(pwm, setValue).Using(0));

        motor.stop();
        Verify(Method(pwm, setValue).Using(0));
    }

    SECTION("Normal Speed")
    {
        float radps = 50;
        auto correctPwmLambda = [radps, maxRadps, pwmMaxValue, pwmTolerance] (uint32_t pwmVal)
        {
            return pwmVal > ((radps / maxRadps * pwmMaxValue) - pwmTolerance);
        };

        motor.rotate(radps, true);
        Verify(Method(pwm, setValue).Matching(correctPwmLambda)).Exactly(Once);
    }

    SECTION("Exceed Max Speed")
    {
        motor.rotate(1000, true);
        Verify(Method(pwm, setValue).Using(pwmMaxValue));
    }
}
