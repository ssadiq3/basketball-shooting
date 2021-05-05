#include <catch2/catch.hpp>
#include <hoop.h>
#include <ball.h>
#include <field.h>
#include <iostream>

TEST_CASE("Test shot motion") {
    finalproject::Field field;

    SECTION("Test x moving") {
        field.SetShooting(true);
        field.AdvanceOneFrame();
        REQUIRE(Approx(field.GetBall().GetPosition().x).epsilon(0.1) == 101.5);
    }

    SECTION("Test y moving") {
        field.SetShooting(true);
        field.AdvanceOneFrame();
        REQUIRE(Approx(field.GetBall().GetPosition().y).epsilon(0.1) == 498.5);
    }

    SECTION("Test velocity x") {
        field.SetShooting(true);
        field.AdvanceOneFrame();
        REQUIRE(Approx(field.GetBall().GetVelocity().x).epsilon(0.1) == 1);
    }

    SECTION("Test velocity y") {
        field.SetShooting(true);
        field.AdvanceOneFrame();
        REQUIRE(Approx(field.GetBall().GetVelocity().y).epsilon(0.1) == -0.98);
    }
}

TEST_CASE("Test ball adjustment") {
    finalproject::Field field;

    SECTION("Test move right position x") {
        field.SetMovingRight(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetPosition().x == 110);
    }
    SECTION("Test move right position y") {
        field.SetMovingRight(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetPosition().y == 500);
    }
    SECTION("Test move left position x") {
        field.SetMovingLeft(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetPosition().x == 95);
    }
    SECTION("Test move left position y") {
        field.SetMovingLeft(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetPosition().y == 500);
    }
    SECTION("Test velocity reset moving right x") {
        field.SetMovingRight(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetVelocity().x == 0.0);
    }
    SECTION("Test velocity reset moving right y") {
        field.SetMovingRight(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetVelocity().y == 0.0);
    }
    SECTION("Test velocity reset moving left x") {
        field.SetMovingLeft(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetVelocity().x == 0.0);
    }
    SECTION("Test velocity reset moving left y") {
        field.SetMovingLeft(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetVelocity().y == 0.0);
    }
}

TEST_CASE("Test set direction") {
    finalproject::Field field;

    SECTION("Test new initial velocity") {
        field.SetDirection(vec2(150, 450));
        REQUIRE(Approx(field.GetInitialVelocity().x).epsilon(.01) == 3.33);
        REQUIRE(Approx(field.GetInitialVelocity().y).epsilon(.01) == -3.33);
    }
}

TEST_CASE("Test score") {
    finalproject::Field field;

    SECTION("Test lose game") {
        field.SetScore(15);
        field.AdvanceOneFrame();
        REQUIRE(field.GetScore() == 0);
    }

    SECTION("Test win game") {
        field.SetScore(-10);
        field.AdvanceOneFrame();
        REQUIRE(field.GetScore() == 0);
    }
}

TEST_CASE("Test hoop moving") {
    finalproject::Field field;
    SECTION("Test hoop moves when score is 8") {
        field.SetScore(8);
        field.AdvanceOneFrame();
        REQUIRE(field.GetHoop().GetRightPosition().x == 949);
    }
    SECTION("Test hoop moves when score is 8") {
        field.SetScore(8);
        field.AdvanceOneFrame();
        REQUIRE(field.GetHoop().GetLeftPosition().x == 849);
    }
}

