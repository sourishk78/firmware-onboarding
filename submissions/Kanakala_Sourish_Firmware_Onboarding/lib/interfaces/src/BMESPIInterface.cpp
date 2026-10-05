#include "BMESPIInterface.h"

bool BMESPIInterface::begin()
{
    return _bme.begin();
}

void BMESPIInterface::update()
{
    _temp_c = _bme.readTemperature();
}

float BMESPIInterface::read_temperature() const
{
    return _temp_c;
}