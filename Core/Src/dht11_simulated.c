//
//    FILE: dht11.cpp
// VERSION: 0.4.1
// PURPOSE: DHT11 Temperature & Humidity Sensor library for STM32
// LICENSE: GPL v3 (http://www.gnu.org/licenses/gpl.html)
//
// DATASHEET: http://www.micro4you.com/files/sensor/DHT11.pdf

#include "dht11.h"
#include "stm32h7xx_hal.h"


DHT11_HandleTypeDef read_DHT11(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	DHT11_HandleTypeDef dht11;

	uint32_t ticks = HAL_GetTick();

	uint32_t n = ticks / 5000;

	int8_t x = n % 10 + 1;
	int8_t y = n % 5 + 1;

    dht11.humidity = 34 + x;
    dht11.temperature = 24 + x;

    if(x > 5) {
    	dht11.humidity -= 2*y;
		dht11.temperature -= 2*y;
    }

	return dht11;
}
//
// END OF FILE
//
