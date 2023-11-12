#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "lab_m1/tema1/tema1.h"
#include "lab_m1/tema1/object2D.h"
#include "lab_m1/tema1/transform2D.h"
#include "bonusStar.h"
#include "lab_m1/tema1/helpers.h"

using namespace std;
using namespace m1;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}

void Tema1::Init()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    glm::ivec2 resolution = window->GetResolution(); // resolution
    auto camera = GetSceneCamera();                  // camera properties
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    starTimer = 0.0f;
    starGenerationInterval = 6.0f;
    enemyGenerationInterval = 8.0f;
    numberOfGeneratedStars = 0;
    moneyStars = 0;
    lastPickedStarIndex = 0;
    isButtonPressed = 0;
    enemyStartX = 2750; // starting x where enemy will be spawned (outside screen)

    // initializing a matrix that stores where there are plants
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            attackRhombus[i][j].isPlaced = 0;
            attackRhombus[i][j].mustBeDestroyed = 0;
            attackRhombus[i][j].scaleX = 1.0f;
            attackRhombus[i][j].scaleY = 1.0f;
        }
    }

    // corner of the image
    glm::vec3 corner = glm::vec3(0, 0, 0);

    // length of a square side where plants will be placed
    squareSide = 200;
    // width and height of the barriero on the left
    float widthRectangle = 100;
    float heightRectangle = 740; // 3 x squareSide + 2 x extraSpaces

    // dimension of rhombus
    float rhombusLength = 150;

    // dimension of hearts
    float heartLength = 170;

    // dimension of user space star, "money star", bonus star
    float userStarDimension = 45;
    float userMoneyStarDimension = 55;

    // dimension of enemy (hexagon)
    float hexagonDimension = 170;

    // computing  center coordinates of square
    square_center_x = corner.x + squareSide / 2;
    square_center_y = corner.y + squareSide / 2;

    // computing center coordinates of rectangle (barrier on the left)
    rectangle_center_x = corner.x + widthRectangle / 2;
    rectangle_center_y = corner.y + heightRectangle / 2;

    // computing rhombus coordinates for center
    rhombus_center_x = corner.x + rhombusLength / 2;
    rhombus_center_y = corner.y + rhombusLength / 2;

    // computing heart coordinates of center
    heart_center_x = corner.x + heartLength / 2;
    heart_center_y = corner.y + heartLength / 2;

    // computing user space star coordinates of center
    star_center_x = corner.x + userStarDimension / 2;
    star_center_y = corner.y + userStarDimension / 2;

    // computing hexagon center coordinates
    hexagon_center_x = corner.x + hexagonDimension / 2;
    hexagon_center_y = corner.y + hexagonDimension / 2;

    // setting number of lifes
    life_number = 3;

    // creatind mesh for heart
    Mesh *heart =
        object2D::CreateHeart(
            "heart",
            corner,
            heartLength,
            glm::vec3(1, 0, 0),
            true);

    AddMeshToList(heart);

    // color light green for squares: 0.5, 1, 0.5
    Mesh *squareGreen = object2D::CreateSquare("squareGreen", corner, squareSide, glm::vec3(0.5f, 1, 0.5f), true);
    AddMeshToList(squareGreen);

    // creating squares for user interface where plants will stay
    Mesh *squareRhombus = object2D::CreateSquare("squareRhombus", corner, squareSide, glm::vec3(5, 5, 5), false);
    AddMeshToList(squareRhombus);

    // barrier on the left where zombies have to go (color red: 1, 0, 0)
    Mesh *barrierRectangle =
        object2D::CreateRectangle(
            "rectangle",
            corner,
            widthRectangle,
            heightRectangle,
            glm::vec3(1, 0, 0),
            true);

    AddMeshToList(barrierRectangle);

    Mesh *orangeRhombus =
        object2D::CreateRhombus(
            "orangeRhombus",
            corner,
            rhombusLength,
            glm::vec3(1, 0.5f, 0),
            true);

    AddMeshToList(orangeRhombus);

    Mesh *blueRhombus =
        object2D::CreateRhombus(
            "blueRhombus",
            corner,
            rhombusLength,
            glm::vec3(0, 0, 1),
            true);

    AddMeshToList(blueRhombus);

    Mesh *yellowRhombus =
        object2D::CreateRhombus(
            "yellowRhombus",
            corner,
            rhombusLength,
            glm::vec3(1, 1, 0),
            true);

    AddMeshToList(yellowRhombus);

    Mesh *purpleRhombus =
        object2D::CreateRhombus(
            "purpleRhombus",
            corner,
            rhombusLength,
            glm::vec3(1, 0, 1),
            true);

    AddMeshToList(purpleRhombus);

    // creating mesh for user space stars
    Mesh *userSpaceStar =
        object2D::CreateStar(
            "userSpaceStar",
            corner,
            userStarDimension,
            glm::vec3(0.6f, 0.6f, 0.6f),
            true);

    AddMeshToList(userSpaceStar);

    // randomly rendered star
    Mesh *bonusStar =
        object2D::CreateStar(
            "bonusStar",
            corner,
            bonusStarDimension,
            glm::vec3(0.4f, 0.8f, 0.9f),
            true);

    AddMeshToList(bonusStar);

    // creating mesh for user "money" to buy plants
    Mesh *userMoneyStar =
        object2D::CreateStar(
            "userMoneyStar",
            corner,
            userMoneyStarDimension,
            glm::vec3(1, 0.7f, 0),
            true);

    AddMeshToList(userMoneyStar);

    // creating mesh for enemy (hexagon)
    Mesh *blueHexagon =
        object2D::CreateHexagon(
            "blueHexagon",
            corner,
            hexagonDimension,
            glm::vec3(0, 0, 1),
            glm::vec3(0, 1, 0),
            true);

    AddMeshToList(blueHexagon);

    Mesh *purpleHexagon =
        object2D::CreateHexagon(
            "purpleHexagon",
            corner,
            hexagonDimension,
            glm::vec3(1, 0, 1),
            glm::vec3(0, 1, 0),
            true);

    AddMeshToList(purpleHexagon);

    Mesh *orangeHexagon =
        object2D::CreateHexagon(
            "orangeHexagon",
            corner,
            hexagonDimension,
            glm::vec3(1, 0.5f, 0),
            glm::vec3(0, 1, 0),
            true);

    AddMeshToList(orangeHexagon);

    Mesh *yellowHexagon =
        object2D::CreateHexagon(
            "yellowHexagon",
            corner,
            hexagonDimension,
            glm::vec3(1, 1, 0),
            glm::vec3(0, 1, 0),
            true);

    AddMeshToList(yellowHexagon);
}

void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::Update(float deltaTimeSeconds)
{
    // counting to render another mesh based on timer
    starTimer += deltaTimeSeconds;
    enemyTimer += deltaTimeSeconds;

    // rendering squares for plants
    int step = 270;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (attackRhombus[i][j].isPlaced)
            {
                modelMatrix = glm::mat3(1);
                modelMatrix *=
                    transform2D::Translate(
                        attackRhombus[i][j].x,
                        attackRhombus[i][j].y);
                if (attackRhombus[i][j].mustBeDestroyed) // check if it must be destroyed
                {

                    attackRhombus[i][j].scaleX -= deltaTimeSeconds;
                    attackRhombus[i][j].scaleY -= deltaTimeSeconds;

                    modelMatrix *= transform2D::Translate(rhombus_center_x, rhombus_center_y);
                    modelMatrix *= transform2D::Scale(attackRhombus[i][j].scaleX, attackRhombus[i][j].scaleY);
                    modelMatrix *= transform2D::Translate(-rhombus_center_x, -rhombus_center_y);

                    RenderMesh2D(
                        meshes[attackRhombus[i][j].color],
                        shaders["VertexColor"], modelMatrix);

                    if (attackRhombus[i][j].scaleX <= 0.006f) // it got destroyed
                    { // checking if it finished scaling down
                        attackRhombus[i][j].isPlaced = 0;
                        attackRhombus[i][j].mustBeDestroyed = 0;
                        attackRhombus[i][j].scaleX = 1.0f;
                        attackRhombus[i][j].scaleY = 1.0f;
                    }
                }
                else
                {
                    RenderMesh2D(
                        meshes[attackRhombus[i][j].color],
                        shaders["VertexColor"], modelMatrix);
                }
            }
            float x = i * step + 150;
            float y = j * step + 50;
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(x, y); // first x = 150, y = 50
            RenderMesh2D(meshes["squareGreen"], shaders["VertexColor"], modelMatrix);
        }
    }

    /* all squares are rendered,
   now rendering barrier where zombies have to get to */

    // x = 150 (first square) - 70 (extraSpace) -
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(20, 50);
    RenderMesh2D(meshes["rectangle"], shaders["VertexColor"], modelMatrix);

    step = 165;
    for (auto color : colorsRhombus)
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(step, 1225);
        RenderMesh2D(meshes[color], shaders["VertexColor"], modelMatrix);
        step += 350;
    }

    // interface for player (squares where plants will stay to be picked)
    step = 0;
    for (int i = 1; i <= 4; i++)
    {
        int x = i * 100 + step;
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(x, 1200);
        RenderMesh2D(meshes["squareRhombus"], shaders["VertexColor"], modelMatrix);
        step += 250;
    }

    // rendering the number of lives
    step = 225; // 100 (heart length) + 40 (extra space)
    for (int i = 0; i < life_number; i++)
    {
        modelMatrix = glm::mat3(1);
        int x = 1600 + i * step;
        modelMatrix *= transform2D::Translate(x, 1225);
        RenderMesh2D(meshes["heart"], shaders["VertexColor"], modelMatrix);
    }

    // rendering stars for user space to see the cost of each plant
    step = 100;
    int cost = 1;
    int level = 1; // level of Rhombus
    for (int i = 0; i < 4; i++)
    {
        if (level == 2 || level == 3)
        {
            cost = 2;
        }
        else
        {
            cost = level;
        }
        int x = step;
        for (int j = 0; j < cost; j++)
        {
            modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(x, 1140);
            RenderMesh2D(meshes["userSpaceStar"], shaders["VertexColor"], modelMatrix);
            x += 51;
        }
        level++;
        step += 350;
    }

    step = 1510;
    // rendering "money stars"
    for (int i = 0; i < moneyStars; i++)
    {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(step, 1140);
        RenderMesh2D(meshes["userMoneyStar"], shaders["VertexColor"], modelMatrix);
        step += 80;
    }

    // adding a new enemy in queue
    if (enemyTimer >= enemyGenerationInterval)
    {
        // random Color from enemies
        int enemyColorIndex = std::rand() % colorsEnemies.size();
        // random Y from available data
        float enemyStartY = std::rand() % possibleEnemyY.size();
        EnemyData newEnemy = EnemyData(colorsEnemies[enemyColorIndex],
                                       3, // life
                                       enemyStartX,
                                       possibleEnemyY[enemyStartY],
                                       0, 1, 1); // hasReachedBarrier and scale args
        enemies.push_back(newEnemy);             // adding enemy
        enemyTimer = 0.0f;
    }

    if (enemies.size() > 0)
    {
        // rendering enemies
        for (auto enemy = enemies.begin(); enemy != enemies.end(); enemy++)
        {
            modelMatrix = glm::mat3(1);
            if (!enemy->hasReachedBarrier) // checking if enemy got to barrier
            {
                enemy->x -= deltaTimeSeconds * 50;
                modelMatrix *= transform2D::Translate(enemy->x, enemy->y);
                modelMatrix *= transform2D::Translate(hexagon_center_x, hexagon_center_y);
                modelMatrix *= transform2D::Rotate(0.3926991f); // rotating the hexagon
                modelMatrix *= transform2D::Translate(-hexagon_center_x, -hexagon_center_y);
                RenderMesh2D(meshes[enemy->color], shaders["VertexColor"], modelMatrix);
            }
        }
    }

    // rendering another rhombus based on click to drag it on field
    modelMatrix = glm::mat3(1);
    if (isButtonPressed && hasSelectedRhombus)
    {
        modelMatrix *= transform2D::Translate(currentMouseX - 50, currentMouseY - 50);
        RenderMesh2D(meshes[selectedRhombus.color], shaders["VertexColor"], modelMatrix);
    }

    // Create a random number generator (as previously shown)

    if (numberOfGeneratedStars < MAX_STARS) // maximum 5 stars on screen
    {
        if (starTimer >= starGenerationInterval)
        {
            // calculating new coordinates only for last star in the array
            float x = rand() % screenWidth;
            float y = rand() % screenHeight;

            bonusStars[numberOfGeneratedStars].x = x;
            bonusStars[numberOfGeneratedStars].y = y;
            bonusStars[numberOfGeneratedStars].hasBeenPicked = 0;

            numberOfGeneratedStars++;
            starTimer = 0.0f;
        }
    }

    for (int i = 0; i < numberOfGeneratedStars; i++)
    {
        if (!bonusStars[i].hasBeenPicked) // checking to render it
        {
            glm::mat3 modelMatrix(1); // Initialize the model matrix
            modelMatrix *= transform2D::Translate(
                bonusStars[i].x,
                bonusStars[i].y);

            // Render the star with the updated model matrix
            RenderMesh2D(meshes["bonusStar"], shaders["VertexColor"], modelMatrix);
        }
    }
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Mac problems :(
    currentMouseY = 2 * (720 - mouseY);
    currentMouseX = 2 * mouseX;
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Mac problems :(
    mouseY = 2 * (720 - mouseY);
    mouseX *= 2;

    // check button pressed
    if (button == 1)
    {
        isButtonPressed = 1;
        // checking if a star was picked
        checkIfPickedStar(mouseX, mouseY,
                          bonusStars, numberOfGeneratedStars,
                          bonusStarDimension, moneyStars);

        // check if a rhombus was picked to drag it
        selectedRhombus.color = selectedColor(mouseX, mouseY, squareSide, moneyStars);
        if (selectedRhombus.color != "")
        {
            selectedRhombus.calculateCost(); // calculating cost to see if user has enough money based on color
            currentMouseX = mouseX;
            currentMouseY = mouseY;
            hasSelectedRhombus = 1;
        }
    }
    else if (button == 2)
    {
        checkIfDestroyRhombus(mouseX, mouseY, squareSide, attackRhombus);
    }
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Mac problems :(
    mouseY = 2 * (720 - mouseY);
    mouseX *= 2;

    // checking if user holds a Rhombus to place it in a square
    if (isButtonPressed && hasSelectedRhombus)
    {
        placeRhombus(mouseX, mouseY, squareSide,
                     moneyStars, selectedRhombus,
                     attackRhombus);
    }
    isButtonPressed = 0;
    hasSelectedRhombus = 0;
}
