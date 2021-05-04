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
        void SetDirection(vec2 location);
        void SetShooting(bool shooting);
        void SetMovingLeft(bool left);
        void SetMovingRight(bool right);
        Ball &GetBall();
        vec2 &GetInitialVelocity();
        void SetBallPosition(vec2 new_pos);
        void Reset();
        void EndGame();

    private:
        const vec2 default_velocity_= vec2(3, -3);
        vec2 initial_velocity_;
        float time_ = 0;
        Hoop hoop_;
        Ball ball_;
        DirectionLine direction_;
        int score_ = 0;
        int hoop_iterations_ = 0;
        float kGravity = (float) 0.02;
        bool shooting_ = false;
        bool moving_left_ = false;
        bool moving_right_ = false;
        bool win_ = false;
        bool lose_ = false;
    };
}
