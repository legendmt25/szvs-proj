// 
//    FILE: dht11.h
// VERSION: 0.4.1
// PURPOSE: DHT11 Temperature & Humidity Sensor library for S
// LICENSE: GPL v3 (http://www.gnu.org/licenses/gpl.html)
//
// DATASHEET: http://www.micro4you.com/files/sensor/DHT11.pdf
//
// HISTORY:
// George Hadjikyriacou - Original version
// see dht.cpp file
// 

#ifndef dht11_h
#define dht11_h

#include "stm32h7xx_hal_gpio.h"

#define DHT11LIB_VERSION "0.4.1"

#define DHTLIB_OK	0
#define DHTLIB_ERROR_CHECKSUM	-1
#define DHTLIB_ERROR_TIMEOUT	-2

typedef struct {
	uint8_t humidity;
	uint8_t temperature;
	uint8_t error;

} DHT11_HandleTypeDef;

DHT11_HandleTypeDef read_DHT11(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif
//
// END OF FILE
//
