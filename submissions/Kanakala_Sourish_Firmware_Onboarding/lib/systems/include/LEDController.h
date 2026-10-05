#pragma once
#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController() = default;

    void update(float temp_c);
    uint32_t get_interval_ms() const { return _interval_ms; }

private:
    uint32_t _interval_ms = 1000;
};

using LEDControllerInstance = etl::singleton<LEDController>;