#include <string>
#include "shootingStarData.h"

ShootingStarData::ShootingStarData(std::string _color,
                     float _x, float _y,
                     int _line,
                     int _mustBeDestroyed,
                     float _scaleX, float _scaleY,
                     int _shouldStartShoot)
{
    color = _color;
    x = _x;
    y = _y;
    line = _line;
    mustBeDestroyed = _mustBeDestroyed;
    scaleX = _scaleX;
    scaleY = _scaleY;
    shouldStartShoot = _shouldStartShoot;
}