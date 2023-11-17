#include <string>
#include "shootingStarData.h"

ShootingStarData::ShootingStarData(std::string _color,
                                   std::string _colorEnemy,
                                   float _x, float _y,
                                   int _line,
                                   int _mustBeDestroyed,
                                   float _scaleX, float _scaleY,
                                   float _angularStep)
{
    color = _color;
    colorEnemy = _colorEnemy;
    x = _x;
    y = _y;
    line = _line;
    mustBeDestroyed = _mustBeDestroyed;
    scaleX = _scaleX;
    scaleY = _scaleY;
    angularStep = _angularStep;
}