#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
protected:
    ModelListener* modelListener;
    int temperature;
    int maxTemperature;
    int minTemperature;
    int humidity;
    int* temperatureGraphData;
};

#endif // MODEL_HPP
