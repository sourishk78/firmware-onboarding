#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface() : _bme(BMEConstants::SPI_CS_PIN) {}

    bool begin();
    void update();
    float read_temperature() const;

private:
    Adafruit_BME280 _bme;
    float _temp_c = 0.0f;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;