#include <field.h>
#include "cinder/gl/gl.h"

namespace finalproject {

    Field::Field() {
        initial_velocity_ = vec2(0,0);
        hoop_ = Hoop(vec2(950, 400), vec2(850, 400));
        ball_ = Ball(25, vec2(100, 500), initial_velocity_);
        direction_ = DirectionLine(ball_.GetPosition(), ball_.GetPosition() +
                    vec2(default_velocity_.x, default_velocity_.y));
    }

    void Field::Display() {
        hoop_.DrawHoop();
        ball_.DrawBall();
        direction_.DrawDirectionLine();

        ci::gl::drawStringCentered(
                "Score: " + std::to_string(score_),
                vec2(800, 100),
                "white", ci::Font("Arial", 25));
        EndGame();
    }

    void Field::AdvanceOneFrame() {
        if (score_ >= 15) {
            win_ = true;
        } else if (score_ <= -10) {
            lose_ = true;
        }
        int hoop_move_multiplier = 1;
        if (score_ >= 3) {
            if (score_ >= 5) {
                hoop_move_multiplier = 1;
            }
            if (hoop_iterations_ % 2 == 0) {
                hoop_.MoveHoopLeft(hoop_move_multiplier);
            } else {
                hoop_.MoveHoopRight(hoop_move_multiplier);
            }
            if (hoop_.GetLeftPosition().x <= 700 || hoop_.GetRightPosition().x >= 960) {
                hoop_iterations_++;
            }
        }
        if (shooting_) {
            ball_.SetVelocity(vec2(initial_velocity_.x, initial_velocity_.y + kGravity*time_));
            ball_.MoveBall();
            ++time_;
            if (ball_.GetPosition().x + ball_.GetRadius() >= hoop_.GetRightPosition().x && (ball_.GetPosition().y + ball_.GetRadius() >= hoop_.GetRightPosition().y-100 && ball_.GetPosition().y + ball_.GetRadius() <= hoop_.GetRightPosition().y)) {
                initial_velocity_.x *= -1;
            } else if ((ball_.GetPosition().x >= hoop_.GetLeftPosition().x && ball_.GetPosition().x <= hoop_.GetRightPosition().x) &&
                        (ball_.GetPosition().y  >= hoop_.GetLeftPosition().y && ball_.GetPosition().y <= hoop_.GetRightPosition().y+10)) {
                score_ += 2;
                Reset();
            }
        } else if (moving_right_) {
            ball_.SetVelocity(vec2(10, 0));
            ball_.MoveBall();
            direction_.MoveLineRight();
            moving_right_ = false;
            ball_.SetVelocity(initial_velocity_);
        } else if (moving_left_) {
            ball_.SetVelocity(vec2(-5, 0));
            ball_.MoveBall();
            direction_.MoveLineLeft();
            moving_left_ = false;
            ball_.SetVelocity(initial_velocity_);
        }
         if (ball_.GetPosition().x < 0 || ball_.GetPosition().x + ball_.GetRadius() > 1000 ||
            ball_.GetPosition().y < 0 || ball_.GetPosition().y + ball_.GetRadius() > 1000) {
            Reset();
            --score_;
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

    void Field::Reset() {
        ball_.ResetPosition();
        direction_.ResetLinePosition();
        initial_velocity_ = default_velocity_;
        shooting_ = false;
        moving_right_ = false;
        moving_left_ = false;
        time_ = 0;
    }

    void Field::SetDirection(vec2 location) {
        if (location.x > ball_.GetPosition().x + ball_.GetRadius() && location.y < ball_.GetPosition().y + ball_.GetRadius()) {
            direction_.SetEndPoint(location);
            initial_velocity_.x = default_velocity_.x*direction_.CosAngle()*direction_.GetMagnitude()/45;
            initial_velocity_.y = default_velocity_.y*direction_.SinAngle()*direction_.GetMagnitude()/45;
        }
    }

    void Field::EndGame() {
        if (win_) {
            Reset();
            score_ = 0;
            ci::gl::drawStringCentered(
                    "Congratulations! You've won! You're a knock-down shooter!",
                    vec2(500, 500),
                    "white", ci::Font("Roboto", 50));
        }
        if (lose_) {
            Reset();
            score_ = 0;
            ci::gl::drawStringCentered(
                    "Darn, sometimes it's not your day. Feel free to try again!",
                    vec2(500, 500),
                    "white", ci::Font("Roboto", 50));
        }
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

    vec2 & Field::GetInitialVelocity() {
        return initial_velocity_;
    }

}

