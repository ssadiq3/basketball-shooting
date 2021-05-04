#include <catch2/catch.hpp>
#include <direction_line.h>

TEST_CASE("Test direction line methods") {
    finalproject::DirectionLine line = finalproject::DirectionLine(vec2(0,0), vec2(3,-4));

    SECTION("Test magnitude") {
        REQUIRE(line.GetMagnitude() == 5);
    }

    SECTION("Test cosine") {
        //adjacent over hypotenuse, = 3/5
        REQUIRE(line.CosAngle() == 0.6f);
    }

    SECTION("Test sine") {
        //opposite over hypotenuse
        REQUIRE(line.SinAngle() == 0.8f);
    }
}