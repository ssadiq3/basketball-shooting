#pragma once

#include "hoop.h"
#include "ball.h"
#include "direction_line.h"

namespace finalproject {

    class Field {
    public:
        /**
         * Initializes all objects on the field and velocity variables
         */
        Field();
        /**
         * Called by app to display all objects on the field
         */
        void Display();
        /**
         * Called by update in the app to move all objects accordingly
         */
        void AdvanceOneFrame();
        /**
         * Helper that moves ball in projectile motion
         */
        void ShootBall();
        /**
         * Sets the velocity to the appropriate value from direction taken from app
         * @param location location of mouse in app
         */
        void SetDirection(vec2 location);
        void SetShooting(bool shooting);
        void SetMovingLeft(bool left);
        void SetMovingRight(bool right);
        Ball &GetBall();
        Hoop &GetHoop();
        vec2 &GetInitialVelocity();
        void SetBallPosition(vec2 new_pos);
        void Reset();
        void EndGame();
        void SetScore(int score);
        int GetScore() const;



    private:
        const vec2 default_velocity_= vec2(3, -3);
        vec2 initial_velocity_;
        float time_ = 0;
        Hoop hoop_;
        Ball ball_;
        DirectionLine direction_;
        int score_ = 0;

    private:
        int hoop_iterations_ = 0;
        float kGravity = (float) 0.02;
        bool shooting_ = false;
        bool moving_left_ = false;
        bool moving_right_ = false;
        bool win_ = false;
        bool lose_ = false;
    };
}
