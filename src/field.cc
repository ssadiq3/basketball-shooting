#include <field.h>

namespace finalproject {

    Field::Field() {
        //hoop_.DrawHoop();
    }

    void Field::Display() {
        hoop_.DrawHoop();
        ball_.DrawBall();
    }

    void Field::AdvanceOneFrame() {
        float current_x_vel = ball_.GetVelocity().x;
        float current_y_vel = ball_.GetVelocity().y;
        if (shooting_) {
            ball_.SetVelocity(vec2(current_x_vel, current_y_vel + kGravity));
            ball_.MoveBall();
            if (ball_.GetPosition().x + ball_.GetRadius() >= hoop_.GetLeftPosition().x && ball_.GetPosition().y + ball_.GetRadius() >= hoop_.GetLeftPosition().y) {
                ball_.ResetPosition();
                ball_.ResetVelocity();
                shooting_ = false;
            }
        } else if (moving_right_) {
            ball_.SetVelocity(vec2(10, 0));
            ball_.MoveBall();
            moving_right_ = false;
            ball_.ResetVelocity();
        } else if (moving_left_) {
            ball_.SetVelocity(vec2(-5, 0));
            ball_.MoveBall();
            moving_left_ = false;
            ball_.ResetVelocity();
        }
        if (ball_.GetPosition().x < 0 || ball_.GetPosition().x > 1000 ||
            ball_.GetPosition().y < 0 || ball_.GetPosition().y > 1000) {
            ball_.ResetPosition();
            ball_.ResetVelocity();
        }
    }

    /*void Field::ShootBall() {
        float current_x_vel = ball_.GetVelocity().x;
        float current_y_vel = ball_.GetVelocity().y;
        ball_.SetVelocity(vec2(current_x_vel, current_y_vel + kGravity));
        ball_.MoveBall();
        if (ball_.GetPosition().x + ball_.GetRadius() >= hoop_.GetLeftPosition().x && ball_.GetPosition().y + ball_.GetRadius() >= hoop_.GetLeftPosition().y) {
            ball_.ResetPosition();
            ball_.ResetVelocity();
            shooting_ = false;
        }

    }*/

    bool Field::IsShooting() {
        return shooting_;
    }

    void Field::SetShooting(bool shooting) {
        shooting_ = shooting;
    }

    void Field::SetMovingLeft(bool left) {
        moving_left_ = left;
    }

    void Field::SetMovingRight(bool right) {
        moving_right_ = right;
    }

    Ball& Field::GetBall() {
        return ball_;
    }

}

