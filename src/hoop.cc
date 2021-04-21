#include <hoop.h>
#include "cinder/gl/gl.h"

using glm::vec2;

namespace finalproject {

    Hoop::Hoop(vec2 right_position, vec2 left_position) {
        right_pos_ = right_position;
        left_pos_ = left_position;
    }

    void Hoop::DrawHoop() {
        ci::gl::color(ci::Color("Red"));
        ci::gl::drawLine(right_pos_, left_pos_);
    }

    vec2 Hoop::GetRightPosition() {
        return right_pos_;
    }

    vec2 Hoop::GetLeftPosition() {
        return left_pos_;
    }
}

