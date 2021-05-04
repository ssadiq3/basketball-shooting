#pragma once

#include <glm/vec2.hpp>

using glm::vec2;

namespace finalproject {

    class DirectionLine {

    public:
        DirectionLine();
        DirectionLine(vec2 start_point, vec2 end_point);
        float GetMagnitude();
        float CosAngle();
        float SinAngle();
        void DrawDirectionLine();
        void SetEndPoint(vec2 end_point);
        void MoveLineRight();
        void MoveLineLeft();
        void ResetLinePosition();

    private:
        vec2 default_start_point_;
        vec2 default_end_point_;
        vec2 start_point_;
        vec2 end_point_;
    };
}
