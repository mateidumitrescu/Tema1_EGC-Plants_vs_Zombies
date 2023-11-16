#ifndef RhombusData_H
#define RhombusData_H
#include <string>
#include "enemyData.h"
#include <queue>

#include "components/simple_scene.h"

class RhombusData : public gfxc::SimpleScene
{

public:
    RhombusData() = default;
    RhombusData(std::string _colorToCheck,
                std::string _color,
                int _cost, float _x, float _y,
                int _isPlaced, int _mustBeDestroyed,
                float _scaleX, float _scaleY,
                int _line,
                std::string _shootingStar);
    std::string colorToCheck;
    std::string color;
    int cost;
    float x;
    float y;
    int isPlaced;
    int mustBeDestroyed;
    float scaleX;
    float scaleY;
    int line;
    std::string shootingStar;

    // calculating cost based on color
    void calculateCost();

    // setting coordinates for Rhombus in square
    void setCoordinates(float _x, float _y);

    // setting star for rhombus
    void setStar();

    // shooting if there is an enemy on line with same color
    void shoot(std::deque<EnemyData> enemies);
};

#endif