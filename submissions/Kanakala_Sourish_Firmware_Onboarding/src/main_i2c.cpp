#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

static uint32_t last_read_ms = 0;
static uint32_t last_blink_ms = 0;
static bool led_on = false;

void setup()
{
    Serial.begin(BMEConstants::SERIAL_BAUD);
    pinMode(BMEConstants::LED_PIN, OUTPUT);

    BMEI2CInterfaceInstance::create();
    LEDControllerInstance::create();

    if (!BMEI2CInterfaceInstance::instance().begin())
    {
        Serial.println("BME280 not found (check wiring)");
    }
}

void loop()
{
    uint32_t now = millis();

    if (now - last_read_ms >= 500)
    {
        last_read_ms = now;
        BMEI2CInterfaceInstance::instance().update();
        float temp_c = BMEI2CInterfaceInstance::instance().read_temperature();
        LEDControllerInstance::instance().update(temp_c);
        Serial.println(temp_c);
    }

    if (now - last_blink_ms >= LEDControllerInstance::instance().get_interval_ms())
    {
        last_blink_ms = now;
        led_on = !led_on;
        digitalWrite(BMEConstants::LED_PIN, led_on);
    }
}