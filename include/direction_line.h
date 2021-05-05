#pragma once

#include <glm/vec2.hpp>

using glm::vec2;

namespace finalproject {

    class DirectionLine {

    public:
        /**
         * Default constructor
         */
        DirectionLine();
        /**
         * Constructor using a start and end point
         * @param start_point starting from ball
         * @param end_point dragged
         */
        DirectionLine(vec2 start_point, vec2 end_point);
        /**
         * Gets magnitude of line
         * @return magnitude
         */
        float GetMagnitude();
        /**
         * cosine of angle between ball and line
         * @return sine of angle between ball and line
         */
        float CosAngle();
        /**
         * sine of angle between ball and line
         * @return sine of angle between ball and line
         */
        float SinAngle();
        /**
         * Draw direction line
         */
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
