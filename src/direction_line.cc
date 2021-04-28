#include <direction_line.h>

#include <cinder/gl/gl.h>

namespace finalproject {

    DirectionLine::DirectionLine() {}

    DirectionLine::DirectionLine(glm::vec2 start_point, glm::vec2 end_point) {
        start_point_ = start_point;
        end_point_ = end_point;
    }

    float DirectionLine::GetMagnitude() {
        return sqrt(pow(end_point_.x - start_point_.x, 2) + pow(end_point_.y - start_point_.y, 2));
    }

    void DirectionLine::DrawDirectionLine() {
        ci::gl::color(ci::Color("White"));
        ci::gl::drawLine(start_point_, end_point_);
    }
}

