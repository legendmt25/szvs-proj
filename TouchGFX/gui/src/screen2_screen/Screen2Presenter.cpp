#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

Screen2Presenter::Screen2Presenter(Screen2View& v)
    : view(v)
{

}

void Screen2Presenter::activate()
{

}

void Screen2Presenter::deactivate()
{

}

void Screen2Presenter::setTemperature(int value) {
	view.setTemperature(value);
};

void Screen2Presenter::setMaxTemperature(int value) {
	view.setMaxTemperature(value);
};

void Screen2Presenter::setMinTemperature(int value) {
	view.setMinTemperature(value);
};

void Screen2Presenter::setTemperatureGraphData(short int* data, int minYRange, int maxYRange) {
	view.setTemperatureGraphData(data, minYRange, maxYRange);
};

