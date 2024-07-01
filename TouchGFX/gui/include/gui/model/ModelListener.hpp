#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }
    virtual void setTemperature(int temperature) {};
    virtual void setHumidity(int humidity) {};
    virtual void setMaxTemperature(int temperature) {};
    virtual void setMinTemperature(int temperature) {};
    virtual void setTemperatureGraphData(short int* data) {};
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
