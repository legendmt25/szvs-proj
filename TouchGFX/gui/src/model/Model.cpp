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
		temperature(0),
		maxTemperature(0),
		minTemperature(0),
		temperatureGraphData(NULL),
		humidity(0)
{

}

void Model::tick()
{
#ifndef SIMULATOR
	modelListener->setHumidity(applicationContext.humidity);

	modelListener->setTemperature(applicationContext.temperature);
	modelListener->setMaxTemperature(applicationContext.maxTemperature);
	modelListener->setMinTemperature(applicationContext.minTemperature);

	modelListener->setTemperatureGraphData(&applicationContext.temperatureData[0], applicationContext.minTemperature, applicationContext.maxTemperature);

	#endif
}
