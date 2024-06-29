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
#include <string.h>

// Return values:
// DHTLIB_OK
// DHTLIB_ERROR_CHECKSUM
// DHTLIB_ERROR_TIMEOUT
DHT11_HandleTypeDef read_DHT11(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	// BUFFER TO RECEIVE
	uint8_t bits[5];
	uint8_t i;

	DHT11_HandleTypeDef dht11;

	// EMPTY BUFFER
	for (int i=0; i<5; i++) bits[i] = 0;

	// REQUEST SAMPLE
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
    HAL_Delay(18);
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
    HAL_Delay(40);

    memset(bits, 0, sizeof(bits));

    for(i=0; i<40; i++)
    {
        // wait for low pulse
        while(!HAL_GPIO_ReadPin(GPIOx, GPIO_Pin));

        // wait for high pulse
        uint32_t t = 0;
        while(HAL_GPIO_ReadPin(GPIOx, GPIO_Pin))
        {
            t++;
            HAL_Delay(1);
        }

        // store bit value in bits array
        if(t > 30)
        	bits[i/8] |= (1 << (7 - (i % 8)));
    }

    // verify checksum
    if(bits[4] == (bits[0] + bits[1] + bits[2] + bits[3]))
    {
        // convert temperature and humidity values
        dht11.humidity = (bits[0] << 8 | bits[1]) / 10.0;
        dht11.temperature = ((bits[2] & 0x7F) << 8 | bits[3]) / 10.0;
        if (bits[2] & 0x80) dht11.temperature *= -1;
    } else {
    	dht11.error = DHTLIB_ERROR_CHECKSUM;
    }

	return dht11;
}
//
// END OF FILE
//
