#pragma once

#include <glm/vec2.hpp>

using glm::vec2;

namespace finalproject {

    class Ball {
    public:
        Ball(float radius, vec2 position, vec2 velocity);

        void DrawBall();

        void MoveBall();

        void ResetPosition();

        void ResetVelocity();

        void SetVelocity(vec2 velocity);

        vec2 GetVelocity();

        vec2 GetPosition();

        float GetRadius();


    private:
        float radius_;
        vec2 position_;
        vec2 velocity_;
        vec2 initial_position_;
        vec2 initial_velocity_;
    };
}