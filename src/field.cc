#include <field.h>
#include "cinder/gl/gl.h"

namespace finalproject {

    Field::Field() {
        //Set an initial velocity before the drag, and initialize the ball, hoop, and direction line
        initial_velocity_ = vec2(1,-1);
        hoop_ = Hoop(vec2(950, 400), vec2(850, 400));
        ball_ = Ball(25, vec2(100, 500), initial_velocity_);
        direction_ = DirectionLine(ball_.GetPosition(), ball_.GetPosition() +
                    vec2(default_velocity_.x, default_velocity_.y));
    }

    void Field::Display() {
        //Draw each object and draw the score
        hoop_.DrawHoop();
        ball_.DrawBall();
        direction_.DrawDirectionLine();

        ci::gl::drawStringCentered(
                "Score: " + std::to_string(score_),
                vec2(800, 100),
                "white", ci::Font("Arial", 25));
        //Draw the end game message if the game is over
        EndGame();
    }

    void Field::AdvanceOneFrame() {
        //Set win or lose to true if the score is high or low enough
        if (score_ >= 15) {
            win_ = true;
        } else if (score_ <= -10) {
            lose_ = true;
        }

        //Once score reaches 8, start moving the hoop
        if (score_ >= 8) {
            if (hoop_iterations_ % 2 == 0) {
                hoop_.MoveHoopLeft();
            } else {
                hoop_.MoveHoopRight();
            }
            if (hoop_.GetLeftPosition().x <= 700 || hoop_.GetRightPosition().x >= 960) {
                hoop_iterations_++;
            }
        }

        //If ball is being shot, call shooting method, if moving right move ball right, if moving left move ball left
        if (shooting_) {
            ShootBall();
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

        //Check if ball is off screen, reset and decrement score
        if (ball_.GetPosition().x < 0 || ball_.GetPosition().x + ball_.GetRadius() > 1000 ||
            ball_.GetPosition().y < 0 || ball_.GetPosition().y + ball_.GetRadius() > 1000) {
            Reset();
            --score_;
        }
    }

    void Field::ShootBall() {
        //Set velocity using time and gravity constant
        ball_.SetVelocity(vec2(initial_velocity_.x, initial_velocity_.y + kGravity * time_));
        ball_.MoveBall();
        ++time_;

        //Check for contact with backboard
        if (ball_.GetPosition().x + ball_.GetRadius() >= hoop_.GetRightPosition().x &&
            (ball_.GetPosition().y + ball_.GetRadius() >= hoop_.GetRightPosition().y - 100 &&
             ball_.GetPosition().y + ball_.GetRadius() <= hoop_.GetRightPosition().y)) {
            initial_velocity_.x *= -1;
        } else if ((ball_.GetPosition().x >= hoop_.GetLeftPosition().x &&
                    ball_.GetPosition().x <= hoop_.GetRightPosition().x) &&
                   (ball_.GetPosition().y >= hoop_.GetLeftPosition().y &&
                    ball_.GetPosition().y <= hoop_.GetRightPosition().y + 10)) {
            //Check for good shot, increment score and reset
            score_ += 2;
            Reset();
        }
    }

    void Field::Reset() {
        //Reset all variables to original
        ball_.ResetPosition();
        direction_.ResetLinePosition();
        initial_velocity_ = default_velocity_;
        shooting_ = false;
        moving_right_ = false;
        moving_left_ = false;
        time_ = 0;
    }

    void Field::SetDirection(vec2 location) {
        //Using cosine and sine from direction line, adjust the velocity according to location from app
        //Use magnitude to adjust power of the shot
        if (location.x > ball_.GetPosition().x + ball_.GetRadius() && location.y < ball_.GetPosition().y + ball_.GetRadius()) {
            direction_.SetEndPoint(location);
            initial_velocity_.x = default_velocity_.x*direction_.CosAngle()*direction_.GetMagnitude()/45;
            initial_velocity_.y = default_velocity_.y*direction_.SinAngle()*direction_.GetMagnitude()/45;
        }
    }

    void Field::EndGame() {
        //Check win or loss, and display each message if appropriate
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

    void Field::SetScore(int score) {
        score_ = score;
    }

    Ball& Field::GetBall() {
        return ball_;
    }

    Hoop & Field::GetHoop() {
        return hoop_;
    }

    vec2 & Field::GetInitialVelocity() {
        return initial_velocity_;
    }

    int Field::GetScore() const {
        return score_;
    }

}

