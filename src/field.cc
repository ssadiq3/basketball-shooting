#include <field.h>

namespace finalproject {

    Field::Field() {
        //hoop_.DrawHoop();
    }

    void Field::Display() {
        hoop_.DrawHoop();
        ball_.DrawBall();
    }

    void Field::ShootBall() {
        float current_x_vel = ball_.GetVelocity().x;
        float current_y_vel = ball_.GetVelocity().y;
        ball_.SetVelocity(vec2(current_x_vel, current_y_vel + kGravity));
        ball_.MoveBall();
        if (ball_.GetPosition().x + ball_.GetRadius() >= hoop_.GetLeftPosition().x && ball_.GetPosition().y + ball_.GetRadius() >= hoop_.GetLeftPosition().y) {
            ball_.ResetPosition();
            ball_.ResetVelocity();
            shooting_ = false;
        }

    }

    bool Field::IsShooting() {
        return shooting_;
    }

    void Field::SetShooting(bool shooting) {
        shooting_ = shooting;
    }

    Ball& Field::GetBall() {
        return ball_;
    }

}

