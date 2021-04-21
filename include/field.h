#pragma once

#include "hoop.h"
#include "ball.h"

namespace finalproject {

    class Field {
    public:
        Field();
        void Display();
        void ShootBall();
        bool IsShooting();
        void SetShooting(bool shooting);
        Ball &GetBall();
        void SetBallPosition(vec2 new_pos);
        //void Reset();

    private:
        Hoop hoop_ = Hoop(vec2(950, 400), vec2(850, 400));
        Ball ball_ = Ball(25, vec2(100, 500), vec2(3, -3));
        float kGravity = (float) 0.02;
        bool shooting_ = false;
    };
}
