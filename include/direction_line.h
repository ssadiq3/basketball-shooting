#pragma once

#include <glm/vec2.hpp>

using glm::vec2;

namespace finalproject {

    class DirectionLine {

    public:
        DirectionLine();
        DirectionLine(vec2 start_point, vec2 end_point);
        float GetMagnitude();
        void DrawDirectionLine();

    private:
        vec2 start_point_;
        vec2 end_point_;
    };
}
