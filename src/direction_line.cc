#include <direction_line.h>

#include <cinder/gl/gl.h>

namespace finalproject {

    DirectionLine::DirectionLine() {}

    DirectionLine::DirectionLine(glm::vec2 start_point, glm::vec2 end_point) {
        default_start_point_ = start_point;
        default_end_point_ = end_point;
        start_point_ = start_point;
        end_point_ = end_point;
    }

    float DirectionLine::GetMagnitude() {
        return sqrt(pow((end_point_.x - start_point_.x), 2) + pow((end_point_.y - start_point_.y), 2));
    }

    float DirectionLine::CosAngle() {
        return (end_point_.x - start_point_.x)/GetMagnitude();
    }

    float DirectionLine::SinAngle() {
        return (start_point_.y - end_point_.y)/GetMagnitude();
    }

    void DirectionLine::DrawDirectionLine() {
        ci::gl::color(ci::Color("White"));
        ci::gl::drawLine(start_point_, end_point_);
    }

    void DirectionLine::SetEndPoint(vec2 end_point) {
        end_point_ = end_point;
    }

    void DirectionLine::MoveLineRight() {
        start_point_.x += 10;
        end_point_.x += 10;
    }

    void DirectionLine::MoveLineLeft() {
        start_point_.x -= 5;
        end_point_.x -=5;
    }

    void DirectionLine::ResetLinePosition() {
        start_point_ = default_start_point_;
        end_point_ = default_end_point_;
    }
}

