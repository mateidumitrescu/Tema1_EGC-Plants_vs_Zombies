#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateSquare(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length, glm::vec3 color,
    bool fill = false);

    // Create rectangle with given bottom left corner, width, height, and color
    Mesh* CreateRectangle(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float width,
    float height,
    glm::vec3 color,
    bool fill);

    // Create rhombus (Plant)
    Mesh* CreateRhombus(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill);

    // Create heart
    Mesh* CreateHeart(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill);

    // Create star
    Mesh* CreateStar(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill);

    // Create hexagon (enemy)
    Mesh* CreateHexagon(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 colorBigHex,
    glm::vec3 colorSmallHex,
    bool fill);
}
