#include <string>
#include "enemyData.h"

EnemyData::EnemyData(std::string _color, int _life,
                     float _x, float _y, int _hasReachedBarrier,
                     float _scaleX, float _scaleY)
{
    color = _color;
    life = _life;
    x = _x;
    y = _y;
    hasReachedBarrier = _hasReachedBarrier;
    scaleX = _scaleX;
    scaleY = _scaleY;
}