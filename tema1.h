#pragma once

#include "components/simple_scene.h"
#include "lab_m1/tema1/transform2D.h"
#include "bonusStar.h"
#include "rhombusData.h"
#include "lab_m1/tema1/enemyData.h"

#include <queue>

#define MAX_STARS 5

namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;

        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;

        // useful variables
    protected:
        float square_center_x, square_center_y;
        float rectangle_center_x, rectangle_center_y;
        float rhombus_center_x, rhombus_center_y;
        float heart_center_x, heart_center_y;
        float star_center_x, star_center_y;
        float hexagon_center_x, hexagon_center_y;
        float shootingStar_center_x, shootingStar_center_y;
        glm::mat3 modelMatrix;
        int life_number;
        int moneyStars;
        int squareSide;
        int step; // used in for's for rendering
        int i, j;
        float rhombusLength;

        int isButtonPressed;
        int hasSelectedRhombus;
        RhombusData selectedRhombus;
        float currentMouseX, currentMouseY;

        int screenWidth = 1280;
        int screenHeight = 720;

        float starTimer;
        float starGenerationInterval;

        float enemyTimer;
        float enemyGenerationInterval;

        float randomXStar;
        float randomYStar;

        float bonusStarDimension = 80;
        float shootingStarDimension;

        // array of rendered bonus stars to be picked
        BonusStar bonusStars[MAX_STARS];
        int numberOfGeneratedStars;
        int lastPickedStarIndex;
        RhombusData attackRhombus[3][3];
        std::vector<std::string> colorsRhombus = {
            "orangeRhombus",
            "blueRhombus",
            "yellowRhombus",
            "purpleRhombus",
        };

        std::vector<EnemyData> enemies;
        float enemyStartX;

        std::vector<float> possibleEnemyY = {50, 320, 590};
        std::vector<std::string> colorsEnemies = {
            "orangeHexagon",
            "blueHexagon",
            "yellowHexagon",
            "purpleHexagon",
        };

        std::vector<ShootingStarData> stars;


    };
}
