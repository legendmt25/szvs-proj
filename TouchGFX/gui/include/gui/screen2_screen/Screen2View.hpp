#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void setTemperature(int value);
    virtual void setMaxTemperature(int value);
    virtual void setMinTemperature(int value);
    virtual void setTemperatureGraphData(short int* data, int minYRange, int maxYRange);
protected:
};

#endif // SCREEN2VIEW_HPP
