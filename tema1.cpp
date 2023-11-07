#include <vector>
#include <iostream>

#include "lab_m1/tema1/tema1.h"
#include "lab_m1/tema1/object2D.h"
#include "lab_m1/tema1/transform2D.h"

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
    glm::ivec2 resolution = window->GetResolution(); // resolution
    auto camera = GetSceneCamera(); // camera properties
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    // corner of the image
    glm::vec3 corner = glm::vec3(0, 0, 0);

    // length of a square side where plants will be placed
    float squareSide = 200;
    // width and height of the barriero on the left
    float widthRectangle = 100;
    float heightRectangle = 740; // 3 x squareSide + 2 x extraSpaces

    // dimension of rhombus
    float rhombusLength = 150;

    // dimension of hearts
    float heartLength = 170;

    // dimension of user space star and "money star"
    float userStarDimension = 45;
    float userMoneyStarDimension = 55;

    // dimension of enemy (hexagon)
    float hexagonDimension = 200;
    
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
    Mesh* heart =
    object2D::CreateHeart(
    "heart",
    corner,
    heartLength,
    glm::vec3(1, 0, 0),
    true);

    AddMeshToList(heart);



    // color light green for squares: 0.5, 1, 0.5
    Mesh* square1 = object2D::CreateSquare("square1", corner, squareSide, glm::vec3(0.5f, 1, 0.5f), true);
    Mesh* square2 = object2D::CreateSquare("square2", corner, squareSide, glm::vec3(0.5f, 1, 0.5f), true);
    Mesh* square3 = object2D::CreateSquare("square3", corner, squareSide, glm::vec3(0.5f, 1, 0.5f), true);
    Mesh* square4 = object2D::CreateSquare("square4", corner, squareSide, glm::vec3(0.5f, 1, 0.5f), true);
    Mesh* square5 = object2D::CreateSquare("square5", corner, squareSide, glm::vec3(0.5f, 1, 0.5f), true);
    Mesh* square6 = object2D::CreateSquare("square6", corner, squareSide, glm::vec3(0.5f, 1, 0.5f), true);
    Mesh* square7 = object2D::CreateSquare("square7", corner, squareSide, glm::vec3(0.5f, 1, 0.5f), true);
    Mesh* square8 = object2D::CreateSquare("square8", corner, squareSide, glm::vec3(0.5f, 1, 0.5f), true);
    Mesh* square9 = object2D::CreateSquare("square9", corner, squareSide, glm::vec3(0.5f, 1, 0.5f), true);

    AddMeshToList(square1);
    AddMeshToList(square2);
    AddMeshToList(square3);
    AddMeshToList(square4);
    AddMeshToList(square5);
    AddMeshToList(square6);
    AddMeshToList(square7);
    AddMeshToList(square8);
    AddMeshToList(square9);

    // creating squares for user interface where plants will stay
    Mesh* squareRhombus = object2D::CreateSquare("squareRhombus", corner, squareSide, glm::vec3(5, 5, 5), false);
    AddMeshToList(squareRhombus);

    // barrier on the left where zombies have to go (color red: 1, 0, 0)
    Mesh* barrierRectangle =
    object2D::CreateRectangle(
        "rectangle",
        corner,
        widthRectangle,
        heightRectangle,
        glm::vec3(1, 0, 0),
        true);
    
    AddMeshToList(barrierRectangle);

    Mesh* orangeRhombus =
    object2D::CreateRhombus(
        "orangeRhombus",
        corner,
        rhombusLength,
        glm::vec3(1, 0.5f, 0),
        true);
    
    AddMeshToList(orangeRhombus);

    Mesh* blueRhombus =
    object2D::CreateRhombus(
        "blueRhombus",
        corner,
        rhombusLength,
        glm::vec3(0, 0, 1),
        true);
    
    AddMeshToList(blueRhombus);

    Mesh* yellowRhombus =
    object2D::CreateRhombus(
        "yellowRhombus",
        corner,
        rhombusLength,
        glm::vec3(1, 1, 0),
        true);
    
    AddMeshToList(yellowRhombus);

    Mesh* purpleRhombus =
    object2D::CreateRhombus(
        "purpleRhombus",
        corner,
        rhombusLength,
        glm::vec3(1, 0, 1),
        true);
    
    AddMeshToList(purpleRhombus);

    // creating mesh for user space stars
    Mesh* userSpaceStar =
    object2D::CreateStar(
        "userSpaceStar",
        corner,
        userStarDimension,
        glm::vec3(0.6f, 0.6f, 0.6f),
        true);
    
    AddMeshToList(userSpaceStar);

    // creating mesh for user "money" to buy plants
    Mesh* userMoneyStar =
    object2D::CreateStar(
        "userMoneyStar",
        corner,
        userMoneyStarDimension,
        glm::vec3(1, 0.7f, 0),
        true);
    
    AddMeshToList(userMoneyStar);

    moneyStars = 5;

    // creating mesh for enemy (hexagon)
    Mesh* blueHexagon =
    object2D::CreateHexagon(
        "blueHexagon",
        corner,
        hexagonDimension,
        glm::vec3(0, 0, 1),
        glm::vec3(0, 1, 0),
        true);
    
    AddMeshToList(blueHexagon);

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
    // rendering each square for plants
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(150, 50); // first x = 150, y = 50
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

    // incrementing x = 150 + 200 (square length) + 70 (extra spacing)
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(420, 50);
    RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix);

    // incrementing again + 200 + 70
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(690, 50);
    RenderMesh2D(meshes["square3"], shaders["VertexColor"], modelMatrix);

    // one line upper, incrementing y = 50 + 200 (square length) + 70 (extra space)
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(150, 320);
    RenderMesh2D(meshes["square4"], shaders["VertexColor"], modelMatrix);

    // incrementing on same line x
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(420, 320);
    RenderMesh2D(meshes["square5"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(690, 320);
    RenderMesh2D(meshes["square6"], shaders["VertexColor"], modelMatrix);

    // one line upper, incrementing y = 320 + 200 (square length) + 70 extra space
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(150, 590);
    RenderMesh2D(meshes["square7"], shaders["VertexColor"], modelMatrix);

    // same line, x = 150 + 200 + 70
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(420, 590);
    RenderMesh2D(meshes["square8"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(690, 590);
    RenderMesh2D(meshes["square9"], shaders["VertexColor"], modelMatrix);

    /* all squares are rendered,
    now rendering barrier where zombies have to get to */

    // x = 150 (first square) - 70 (extraSpace) - 
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(20, 50);
    RenderMesh2D(meshes["rectangle"], shaders["VertexColor"], modelMatrix);

    std::vector<std::string> colorsRhombus = {"orangeRhombus",
                                    "blueRhombus",
                                    "yellowRhombus",
                                    "purpleRhombus",};
    
    int step = 165;
    for (auto color : colorsRhombus) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(step, 1225);
        RenderMesh2D(meshes[color], shaders["VertexColor"], modelMatrix);
        step += 350;
    }
    

    // interface for player (squares where plants will stay to be picked)
    step = 0;
    for (int i = 1; i <= 4; i++) {
        int x = i * 100 + step;
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(x, 1200);
        RenderMesh2D(meshes["squareRhombus"], shaders["VertexColor"], modelMatrix);
        step += 250;
    }

    // rendering the number of lives
    step = 225; // 100 (heart length) + 40 (extra space)
    for (int i = 0; i < life_number; i++) {
        modelMatrix = glm::mat3(1);
        int x = 1600 + i * step;
        modelMatrix *= transform2D::Translate(x, 1225);
        RenderMesh2D(meshes["heart"], shaders["VertexColor"], modelMatrix);
    }

    // rendering stars for user space to see the cost of each plant
    step = 100;
    int level = 1; // level of plant
    for (int i = 0; i < 4; i++) {
        int x = step;
        for (int j = 0; j < level; j++) {
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
    for (int i = 0; i < moneyStars; i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(step, 1140);
        RenderMesh2D(meshes["userMoneyStar"], shaders["VertexColor"], modelMatrix);
        step += 80;
    }

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(1300 , 600);
    modelMatrix *= transform2D::Translate(hexagon_center_x , hexagon_center_y);
    modelMatrix *= transform2D::Rotate(0.3926991f);
    modelMatrix *= transform2D::Translate(-hexagon_center_x, -hexagon_center_y);
    RenderMesh2D(meshes["blueHexagon"], shaders["VertexColor"], modelMatrix);
    
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{

}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    if ()
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{

}
