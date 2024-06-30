#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include "main.h"

extern "C"
{
	extern ApplicationContext_TypeDef applicationContext;
}
#endif
Model::Model() : modelListener(0),
		temperature(0), maxTemperature(0), minTemperature(0), temperatureGraphData(NULL), humidity(0)
{

}

void Model::tick()
{
#ifndef SIMULATOR
//	HAL_ADC_Start(&hadc1);
//	HAL_ADC_PollForConversion(&hadc1, 10);
//	uint16_t value = HAL_ADC_GetValue(&hadc1);
//	HAL_ADC_Stop (&hadc1);

//	ADC_VAL = map(0, 0, 65535, 0, 100);

	modelListener->setHumidity(applicationContext.humidity);

	modelListener->setTemperature(applicationContext.temperature);
	modelListener->setMaxTemperature(applicationContext.maxTemperature);
	modelListener->setMinTemperature(applicationContext.minTemperature);

	modelListener->setTemperatureGraphData((int*) &applicationContext.temperatureData);

	#endif
}
