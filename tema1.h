#pragma once

#include "components/simple_scene.h"
#include "lab_m1/tema1/transform2D.h"


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
        
    
     // useful variables
     protected:
        float square_center_x, square_center_y;
        float rectangle_center_x, rectangle_center_y;
        float rhombus_center_x, rhombus_center_y;
        float heart_center_x, heart_center_y;
        float star_center_x, star_center_y;
        glm::mat3 modelMatrix;
        int life_number;

        
    };
}
