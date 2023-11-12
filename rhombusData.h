#ifndef RhombusData_H
#define RhombusData_H
#include <string>

class RhombusData
{

public:
    RhombusData() = default;
    RhombusData(std::string _color, int _cost);
    std::string color;
    int cost;

    void calculateCost()
    {
        if (color == "orangeRhombus")
        {
            cost = 1;
        }
        else if (color == "blueRhombus")
        {
            cost = 2;
        }
        else if (color == "yellowRhombus")
        {
            cost = 3;
        }
        else if (color == "purpleRhombus")
        {
            cost = 4;
        }
    }
};

#endif