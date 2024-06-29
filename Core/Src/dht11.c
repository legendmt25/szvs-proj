//
//    FILE: dht11.cpp
// VERSION: 0.4.1
// PURPOSE: DHT11 Temperature & Humidity Sensor library for STM32
// LICENSE: GPL v3 (http://www.gnu.org/licenses/gpl.html)
//
// DATASHEET: http://www.micro4you.com/files/sensor/DHT11.pdf
//
// HISTORY:
// George Hadjikyriacou - Original version (??)
// Mod by SimKard - Version 0.2 (24/11/2010)
// Mod by Rob Tillaart - Version 0.3 (28/03/2011)
// + added comments
// + removed all non DHT11 specific code
// + added references
// Mod by Rob Tillaart - Version 0.4 (17/03/2012)
// + added 1.0 support
// Mod by Rob Tillaart - Version 0.4.1 (19/05/2012)
// + added error codes
//

#include "dht11.h"

// Return values:
// DHTLIB_OK
// DHTLIB_ERROR_CHECKSUM
// DHTLIB_ERROR_TIMEOUT
DHT11_HandleTypeDef read_DHT11(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	// BUFFER TO RECEIVE
	uint8_t bits[5];
	uint8_t cnt = 7;
	uint8_t idx = 0;

	DHT11_HandleTypeDef dht11;

	// EMPTY BUFFER
	for (int i=0; i<5; i++) bits[i] = 0;

	// REQUEST SAMPLE
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
    HAL_Delay(18);
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
    HAL_Delay(40);

    memset(data, 0, sizeof(data));

	// ACKNOWLEDGE or TIMEOUT
	unsigned int loopCnt = 10000;
	while(HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == GPIO_PIN_RESET)
		if (loopCnt-- == 0) {
			dht11.error = DHTLIB_ERROR_TIMEOUT;
			return dht11;
		}

	loopCnt = 10000;
	while(HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == GPIO_PIN_SET)
		if (loopCnt-- == 0) {
			dht11.error = DHTLIB_ERROR_TIMEOUT;
			return dht11;
		}

	// READ OUTPUT - 40 BITS => 5 BYTES or TIMEOUT
	for (int i=0; i<40; i++)
	{
		loopCnt = 10000;
		while(HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == GPIO_PIN_RESET)
			if (loopCnt-- == 0) {
				dht11.error = DHTLIB_ERROR_TIMEOUT;
				return dht11;
			}

		unsigned long t = HAL_GetTick();

		loopCnt = 10000;
		while(HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == GPIO_PIN_SET)
			if (loopCnt-- == 0) {
				dht11.error = DHTLIB_ERROR_TIMEOUT;
				return dht11;
			}

		if ((HAL_GetTick() - t) > 40) bits[idx] |= (1 << cnt);
		if (cnt == 0)   // next byte?
		{
			cnt = 7;    // restart at MSB
			idx++;      // next byte!
		}
		else cnt--;
	}

	// WRITE TO RIGHT VARS
        // as bits[1] and bits[3] are allways zero they are omitted in formulas.
	dht11.humidity    = bits[0];
	dht11.temperature = bits[2];

	uint8_t sum = bits[0] + bits[2];  

	if (bits[4] != sum) {
		dht11.error = DHTLIB_ERROR_CHECKSUM;
	}

	return dht11;
}
//
// END OF FILE
//
