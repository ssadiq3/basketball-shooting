#pragma once

#include <glm/vec2.hpp>

using glm::vec2;

namespace finalproject {

    class Hoop {
    public:

        Hoop(vec2 right_position, vec2 left_position);

        void DrawHoop();

        vec2 GetRightPosition();

        vec2 GetLeftPosition();



    private:
        vec2 right_pos_;
        vec2 left_pos_;
    };
}
