#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::setTemperature(int value) {
	Unicode::snprintf(temperatureTextAreaBuffer, TEMPERATURETEXTAREA_SIZE, "%d", value);
	temperatureTextArea.invalidate();
};

void Screen1View::setHumidity(int value) {
	Unicode::snprintf(humidityTextAreaBuffer, HUMIDITYTEXTAREA_SIZE, "%d", value);
	humidityTextArea.invalidate();
};
