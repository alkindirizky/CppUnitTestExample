#include <SerialProcessor.hpp>

float byteFloat(uint8_t* pData)
{
    uint32_t floatVal = pData[0];
    floatVal = (floatVal << 8) | pData[1];
    floatVal = (floatVal << 8) | pData[2];
    floatVal = (floatVal << 8) | pData[3];

    return *((float *) &floatVal);
}

uint32_t byteUint32(uint8_t* pData)
{
    uint32_t uintval = pData[3];
    uintval = (uintval <<8) | pData[2];
    uintval = (uintval <<8) | pData[1];
    uintval = (uintval <<8) | pData[0];

    return  uintval;
}
