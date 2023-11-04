#include <vector>
#include <iostream>

#include "lab_m1/Tema1/Tema1.h"
#include "lab_m1/Tema1/object2D.h"
#include "lab_m1/Tema1/transform2D.h"

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
    float squareSide = 100;

    // computing  center coordinates
    square_center_x = corner.x + squareSide / 2;
    square_center_y = corner.y + squareSide / 2;

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

}
