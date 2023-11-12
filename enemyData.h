#ifndef EnemyData_H
#define EnemyData_H
#include <string>

class EnemyData
{

public:
    EnemyData() = default;
    EnemyData(std::string _color, int _life, float _x, float _y,
              int _hasReachedBarrier, float _scaleX, float _scaleY);
    std::string color;
    int life;
    float x;
    float y;
    int hasReachedBarrier;
    float scaleX;
    float scaleY;
};

#endif