// rhombusData.cpp
#include "rhombusData.h"
#include <string>

RhombusData::RhombusData(std::string _color, int _cost, float _x, float _y,
                         int _isPlaced, int _mustBeDestroyed, float _scaleX, float _scaleY)
{
    color = _color;
    cost = _cost;
    x = _x;
    y = _y;
    isPlaced = _isPlaced;
    mustBeDestroyed = _mustBeDestroyed;
    scaleX = _scaleX;
    scaleY = _scaleY;
}

void RhombusData::calculateCost()
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
        cost = 2;
    }
    else if (color == "purpleRhombus")
    {
        cost = 4;
    }
}

void RhombusData::setCoordinates(float _x, float _y)
{
    x = _x;
    y = _y;
}