#ifndef RhombusData_H
#define RhombusData_H
#include <string>


class RhombusData
{

public:
    RhombusData() = default;
    RhombusData(std::string _color, int _cost, float _x, float _y,
                int _isPlaced, int _mustBeDestroyed,
                float _scaleX, float _scaleY,
                std::string _shootingStar);
    std::string color;
    int cost;
    float x;
    float y;
    int isPlaced;
    int mustBeDestroyed;
    float scaleX;
    float scaleY;
    std::string shootingStar;

    // calculating cost based on color
    void calculateCost();

    // setting coordinates for Rhombus in square
    void setCoordinates(float _x, float _y);

    // setting star for rhombus
    void setStar();
};

#endif