#include <MotorDriver.hpp>

MotorDriver::MotorDriver()
{
    m_pPwm = nullptr;
    m_pGpio = nullptr;
    m_maxSpeed = 100;
}

void MotorDriver::initialize(IPwm *pMotorPwm, IGpio *pDirGpio, float maxSpeed)
{
    m_pPwm = pMotorPwm;
    m_pGpio = pDirGpio;
    m_maxSpeed = maxSpeed;

    if(m_maxSpeed >= 100.0)
    {
        m_maxSpeed = 100.0;
    }
    else if(m_maxSpeed <= 0.0)
    {
        m_maxSpeed = 0.0;
    }
}

void MotorDriver::rotate(float radps, bool forwardDir)
{
    if(radps >= m_maxSpeed)
    {
        radps = m_maxSpeed;
    }

    if(forwardDir)
    {
        m_pGpio->set();
    }
    else
    {
        m_pGpio->clear();
    }

    m_pPwm->setValue(radps / 100.0 * m_pPwm->maxValue());
}

void MotorDriver::stop()
{
    m_pPwm->setValue(0);
}
