#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:
    BMEI2CInterface() = default;

    bool begin();
    void update();
    float read_temperature() const;

private:
    Adafruit_BME280 _bme;
    float _temp_c = 0.0f;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;