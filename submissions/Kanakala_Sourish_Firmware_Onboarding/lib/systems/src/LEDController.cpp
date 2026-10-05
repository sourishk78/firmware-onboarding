#include "LEDController.h"

void LEDController::update(float temp_c)
{
    // 20C -> 1000ms, 40C -> 100ms, clamped
    float t = constrain(temp_c, 20.0f, 40.0f);
    _interval_ms = (uint32_t)(1000.0f - (t - 20.0f) * 45.0f);
}