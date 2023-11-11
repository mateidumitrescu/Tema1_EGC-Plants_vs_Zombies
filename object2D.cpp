#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateSquare(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateRectangle(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float width,
    float height,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(width, 0, 0), color),
        VertexFormat(corner + glm::vec3(width, height, 0), color),
        VertexFormat(corner + glm::vec3(0, height, 0), color)
    };

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        rectangle->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    rectangle->InitFromData(vertices, indices);
    return rectangle;
}

Mesh* object2D::CreateRhombus(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(length / 4, 0, 0), color),
        VertexFormat(corner + glm::vec3(length / 2, length / 2, 0), color),
        VertexFormat(corner + glm::vec3(length / 4, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length / 2, 0), color),
        VertexFormat(corner + glm::vec3(length / 4, length / 10 * 3.5, 0), color),
        VertexFormat(corner + glm::vec3(length / 10 * 9, length / 10 * 3.5, 0), color),
        VertexFormat(corner + glm::vec3(length / 10 * 9, length / 10 * 6.5, 0), color),
        VertexFormat(corner + glm::vec3(length / 4, length / 10 * 6.5, 0), color),

    };

    Mesh* rhombus = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3, 0, 4, 5, 6, 7};

    if (!fill) {
        rhombus->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Drawing triangles between indices
        rhombus->SetDrawMode(GL_TRIANGLES);

        // Defining the triangles
        indices = { 0, 1, 2, 0, 2, 3, 4, 5, 7, 5, 6, 7};
    }

    rhombus->InitFromData(vertices, indices);
    return rhombus;
}

Mesh* object2D::CreateHeart(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length / 2, length / 10 * 5, 0), color),
        VertexFormat(corner + glm::vec3(length / 2, length / 10 * 8, 0), color),
        VertexFormat(corner + glm::vec3(length / 4, length, 0), color),
        VertexFormat(corner + glm::vec3(-length / 4, length, 0), color),
        VertexFormat(corner + glm::vec3(-length / 2, length / 10 * 8, 0), color),
        VertexFormat(corner + glm::vec3(-length / 2, length / 10 * 5, 0), color),

    };

    Mesh* heart = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3, 4, 5, 6};

    if (!fill) {
        heart->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Drawing triangles between indices
        heart->SetDrawMode(GL_TRIANGLES);

        // Defining the triangles
        indices = { 0, 1, 2, 0, 2, 3, 0, 3, 4, 0, 4, 5, 0, 5, 6};
    }

    heart->InitFromData(vertices, indices);
    return heart;
}

Mesh* object2D::CreateStar(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(length / 10, 0, 3), color),
        VertexFormat(corner + glm::vec3(length / 4, length / 10 * 4, 3), color),
        VertexFormat(corner + glm::vec3(0, length / 10 * 6.5 , 3), color),
        VertexFormat(corner + glm::vec3(length / 10 * 3.5, length / 10 * 6.5, 3), color),
        VertexFormat(corner + glm::vec3(length / 2, length, 3), color),
        VertexFormat(corner + glm::vec3(length / 10 * 6.5, length / 10 * 6.5, 3), color),
        VertexFormat(corner + glm::vec3(length, length / 10 * 6.5, 3), color),
        VertexFormat(corner + glm::vec3(length / 4 * 3, length / 10 * 4, 3), color),
        VertexFormat(corner + glm::vec3(length / 10 * 9, 0, 3), color),
        VertexFormat(corner + glm::vec3(length / 2, length / 4, 3), color),
    };

    Mesh* star = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    if (!fill) {
        star->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Drawing triangles between indices
        star->SetDrawMode(GL_TRIANGLES);

        // Defining the triangles
        indices = {1, 2, 3, 3, 4, 5, 5, 6, 7, 7, 8 , 9, 9, 0, 1, 1, 7, 9, 1, 5, 7, 1, 3, 5};
    }

    star->InitFromData(vertices, indices);
    return star;
}

Mesh* object2D::CreateHexagon(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 colorBigHex,
    glm::vec3 colorSmallHex,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(length / 3.5, length / 10 * 0.5, 1), colorBigHex),
        VertexFormat(corner + glm::vec3(length / 10 * 0.5, length / 2, 1), colorBigHex),
        VertexFormat(corner + glm::vec3(length / 3.5, length / 10 * 9.5, 1), colorBigHex),
        VertexFormat(corner + glm::vec3(length / 3.5 * 2.5, length / 10 * 9.5, 1), colorBigHex),
        VertexFormat(corner + glm::vec3(length / 10 * 9.5, length / 2, 1), colorBigHex),
        VertexFormat(corner + glm::vec3(length / 3.5 * 2.5, length / 10 * 0.5, 1), colorBigHex),
        
        VertexFormat(corner + glm::vec3(length / 10 * 6.2, length / 10 * 2, 2), colorSmallHex),
        VertexFormat(corner + glm::vec3(length / 10 * 3.7, length / 10 * 2, 2), colorSmallHex),
        VertexFormat(corner + glm::vec3(length / 10 * 2, length / 2, 2), colorSmallHex),
        VertexFormat(corner + glm::vec3(length / 10 * 3.7, length / 10 * 8, 2), colorSmallHex),
        VertexFormat(corner + glm::vec3(length / 10 * 6.2, length / 10 * 8, 2), colorSmallHex),
        VertexFormat(corner + glm::vec3(length / 10 * 8, length / 2, 2), colorSmallHex),        
    };

    Mesh* hexagon = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10, 11};

    if (!fill) {
        hexagon->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Drawing triangles between indices
        hexagon->SetDrawMode(GL_TRIANGLES);

        // Defining the triangles
        indices = {5, 0, 1, 5, 1, 2, 5, 2, 3, 5, 3, 4, 6, 7, 8, 6, 8, 9, 6, 9, 10, 6, 10, 11};
    }

    hexagon->InitFromData(vertices, indices);
    return hexagon;
}


