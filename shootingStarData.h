#ifndef ShootingStarData_H
#define ShootingStarData_H
#include <string>

class ShootingStarData
{

public:
    ShootingStarData() = default;
    ShootingStarData(std::string _color, std::string _colorEnemy,
                     float _x, float _y,
                     int _line,
                     int _mustBeDestroyed,
                     float _scaleX, float _scaleY,
                     float _angularStep);
    std::string color;
    std::string colorEnemy;
    float x;
    float y;
    int line;
    int mustBeDestroyed;
    float scaleX;
    float scaleY;
    float angularStep;
};

#endif