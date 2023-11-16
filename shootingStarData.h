#ifndef ShootingStarData_H
#define ShootingStarData_H
#include <string>

class ShootingStarData
{

public:
    ShootingStarData() = default;
    ShootingStarData(std::string _color, float _x, float _y,
              int _line,
              int _mustBeDestroyed,
              float _scaleX, float _scaleY,
              int _shouldStartShoot);
    std::string color;
    float x;
    float y;
    int line;
    int mustBeDestroyed;
    float scaleX;
    float scaleY;
    int shouldStartShoot;
};

#endif