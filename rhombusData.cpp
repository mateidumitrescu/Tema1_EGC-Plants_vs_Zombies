// rhombusData.cpp
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "rhombusData.h"
#include <string>
#include <queue>
#include "enemyData.h"
#include <iostream>
#include "components/simple_scene.h"
#include "lab_m1/tema1/transform2D.h"
#include "shootingStarData.h"
#include "tema1.h"

RhombusData::RhombusData(std::string _colorToCheck,
                         std::string _color,
                         int _cost, float _x, float _y,
                         int _isPlaced, int _mustBeDestroyed,
                         float _scaleX, float _scaleY,
                         int _line,
                         std::string _shootingStarType,
                         std::string _colorEnemy,
                         float _shootingGenerationInterval, float _shootingTimer)
{
    colorToCheck = _colorToCheck;
    color = _color;
    cost = _cost;
    x = _x;
    y = _y;
    isPlaced = _isPlaced;
    mustBeDestroyed = _mustBeDestroyed;
    scaleX = _scaleX;
    scaleY = _scaleY;
    line = _line;
    shootingStarType = _shootingStarType;
    colorEnemy = _colorEnemy;
    shootingGenerationInterval = _shootingGenerationInterval;
    shootingTimer = _shootingTimer;
}

void RhombusData::calculateCost()
{
    if (color == "orangeRhombus")
    {
        colorToCheck = "orange";
        cost = 1;
    }
    else if (color == "blueRhombus")
    {
        colorToCheck = "blue";
        cost = 2;
    }
    else if (color == "yellowRhombus")
    {
        colorToCheck = "yellow";
        cost = 2;
    }
    else if (color == "purpleRhombus")
    {
        colorToCheck = "purple";
        cost = 3;
    }
}

void RhombusData::setCoordinates(float _x, float _y)
{
    x = _x;
    y = _y;
}

void RhombusData::setStar()
{
    if (color == "orangeRhombus")
    {
        colorEnemy = "orangeHexagon";
        shootingStarType = "shootingOrangeStar";
    }
    else if (color == "blueRhombus")
    {
        colorEnemy = "blueHexagon";
        shootingStarType = "shootingBlueStar";
    }
    else if (color == "yellowRhombus")
    {
        colorEnemy = "yellowHexagon";
        shootingStarType = "shootingYellowStar";
    }
    else if (color == "purpleRhombus")
    {
        colorEnemy = "purpleHexagon";
        shootingStarType = "shootingPurpleStar";
    }
}

void RhombusData::generateShoot(std::vector<EnemyData> enemies, float deltaTimeSeconds,
                                float rhombusLength, std::vector<ShootingStarData> &stars)
{

    glm::mat3 modelMatrix;
    for (int i = 0; i < enemies.size(); i++)
    {
        // check if there is an enemy on the same line with same color
        if (enemies[i].line == this->line && enemies[i].color.find(this->colorToCheck) == 0)
        {
            this->shootingTimer += deltaTimeSeconds; // incrementing timer for shooting
            if (this->shootingTimer >= this->shootingGenerationInterval)
            {
                // adding new star in stars vector
                stars.push_back(ShootingStarData(this->shootingStarType,
                                                 this->colorEnemy,                 // ex: "yellowShootingStar"
                                                 this->x + rhombusLength - 10,     // x coordinate
                                                 this->y + rhombusLength / 2 - 20, // y coordinate
                                                 this->line,                       // same line as rhombus
                                                 0,                                // mustBeDestroyed
                                                 1,                                // scaleX
                                                 1,                                // scaleY
                                                 0));                              // angularStep for rotating
                this->shootingTimer = 0.0f;
            }
        }
    }
}