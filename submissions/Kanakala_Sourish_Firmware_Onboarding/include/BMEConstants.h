#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    constexpr uint8_t  I2C_ADDRESS = 0x76;   
    constexpr uint8_t  SPI_CS_PIN  = 10;
    constexpr uint8_t  LED_PIN     = 13;
    constexpr uint32_t SERIAL_BAUD = 115200;
}