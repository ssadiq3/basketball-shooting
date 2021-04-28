#pragma once

#include "hoop.h"
#include "ball.h"
#include "direction_line.h"

namespace finalproject {

    class Field {
    public:
        Field();
        void Display();
        void AdvanceOneFrame();
        void ShootBall();
        void SetInitialVelocity(vec2 velocity);
        void SetShooting(bool shooting);
        void SetMovingLeft(bool left);
        void SetMovingRight(bool right);
        Ball &GetBall();
        void SetBallPosition(vec2 new_pos);
        //void Reset();

    private:
        float time_ = 0;
        vec2 initial_velocity_ = vec2(3, -3);
        Hoop hoop_ = Hoop(vec2(950, 400), vec2(850, 400));
        Ball ball_ = Ball(25, vec2(100, 500), initial_velocity_);
        DirectionLine direction_ = DirectionLine(ball_.GetPosition(), ball_.GetPosition() + vec2(initial_velocity_.x*10, initial_velocity_.y*10));
        float kGravity = (float) 0.02;
        bool shooting_ = false;
        bool moving_left_ = false;
        bool moving_right_ = false;
    };
}
