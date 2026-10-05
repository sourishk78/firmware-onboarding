#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin()
{
    return _bme.begin(BMEConstants::I2C_ADDRESS);
}

void BMEI2CInterface::update()
{
    _temp_c = _bme.readTemperature();
}

float BMEI2CInterface::read_temperature() const
{
    return _temp_c;
}