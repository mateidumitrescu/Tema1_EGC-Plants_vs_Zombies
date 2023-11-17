#include <string>
#include "enemyData.h"

EnemyData::EnemyData(std::string _color, int _life,
                     float _x, float _y,
                     int _line,
                     int _hasReachedBarrier,
                     int _mustBeDestroyed,
                     float _scaleX, float _scaleY)
{
    color = _color;
    life = _life;
    x = _x;
    y = _y;
    line = _line;
    hasReachedBarrier = _hasReachedBarrier;
    mustBeDestroyed = _mustBeDestroyed;
    scaleX = _scaleX;
    scaleY = _scaleY;
}