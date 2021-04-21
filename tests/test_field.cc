#include <catch2/catch.hpp>
#include <hoop.h>
#include <ball.h>
#include <field.h>

TEST_CASE("Test shot motion") {
    finalproject::Field field;

    SECTION("Test x moving") {
        field.ShootBall();
        REQUIRE(Approx(field.GetBall().GetPosition().x).epsilon(0.1) == 103);
    }

    SECTION("Test y moving") {
        field.ShootBall();
        REQUIRE(Approx(field.GetBall().GetPosition().y).epsilon(0.1) == 497);
    }

    SECTION("Test velocity x") {
        field.ShootBall();
        REQUIRE(Approx(field.GetBall().GetVelocity().x).epsilon(0.1) == 2.98);
    }

    SECTION("Test velocity y") {
        field.ShootBall();
        REQUIRE(Approx(field.GetBall().GetVelocity().y).epsilon(0.1) == -2.98);
    }
}

TEST_CASE("Test position and velocity reset") {
    finalproject::Field field;

    SECTION("")
}

