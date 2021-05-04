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
        REQUIRE(Approx(field.GetBall().GetPosition().x).epsilon(0.1) == 103);
    }

    SECTION("Test y moving") {
        field.SetShooting(true);
        field.AdvanceOneFrame();
        REQUIRE(Approx(field.GetBall().GetPosition().y).epsilon(0.1) == 497);
    }

    SECTION("Test velocity x") {
        field.SetShooting(true);
        field.AdvanceOneFrame();
        REQUIRE(Approx(field.GetBall().GetVelocity().x).epsilon(0.1) == 2.98);
    }

    SECTION("Test velocity y") {
        field.SetShooting(true);
        field.AdvanceOneFrame();
        REQUIRE(Approx(field.GetBall().GetVelocity().y).epsilon(0.1) == -2.98);
    }
}

TEST_CASE("Test ball adjustment") {
    finalproject::Field field;

    SECTION("Test move right position x") {
        field.SetMovingRight(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetPosition().x == 103);
    }
    SECTION("Test move right position y") {
        field.SetMovingRight(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetPosition().y == 500);
    }
    SECTION("Test move left position x") {
        field.SetMovingLeft(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetPosition().x == 97);
    }
    SECTION("Test move left position y") {
        field.SetMovingLeft(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetPosition().y == 500);
    }
    SECTION("Test velocity reset moving right x") {
        field.SetMovingRight(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetVelocity().x == 3);
    }
    SECTION("Test velocity reset moving right y") {
        field.SetMovingRight(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetVelocity().y == -3);
    }
    SECTION("Test velocity reset moving left x") {
        field.SetMovingLeft(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetVelocity().x == 3);
    }
    SECTION("Test velocity reset moving left y") {
        field.SetMovingLeft(true);
        field.AdvanceOneFrame();
        REQUIRE(field.GetBall().GetVelocity().y == -3);
    }
}

TEST_CASE("Test set direction") {
    finalproject::Field field;

    SECTION("Test new initial velocity") {
        field.SetDirection(vec2(150, 450));
        std::cout<<field.GetInitialVelocity().x<<std::endl;
        std::cout<<field.GetInitialVelocity().y<<std::endl;
    }
}

