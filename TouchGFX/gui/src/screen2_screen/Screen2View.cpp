#include <gui/screen2_screen/Screen2View.hpp>

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::setTemperature(int value) {
	Unicode::snprintf(temperatureTextAreaBuffer, TEMPERATURETEXTAREA_SIZE, "%d", value);
	temperatureTextArea.invalidate();
};

void Screen2View::setMaxTemperature(int value) {
	Unicode::snprintf(maxTemperatureTextAreaBuffer, MAXTEMPERATURETEXTAREA_SIZE, "%d", value);
	maxTemperatureTextArea.invalidate();
};

void Screen2View::setMinTemperature(int value) {
	Unicode::snprintf(minTemperatureTextAreaBuffer, MINTEMPERATURETEXTAREA_SIZE, "%d", value);
	minTemperatureTextArea.invalidate();
};

void Screen2View::setTemperatureGraphData(short int* data, int minYRange, int maxYRange) {
	if(!data) {
		return;
	}

	temperatureGraph.clear();
	temperatureGraph.setGraphRangeY(minYRange - 1, maxYRange + 1);

	const int size = 24;
	const int minAllowedTemperature = -100;
	for(int i = 0; data[i] != minAllowedTemperature && i < size; ++i) {
	  temperatureGraph.addDataPoint(data[i]);
	}
};
