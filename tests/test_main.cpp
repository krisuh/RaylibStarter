#include <catch2/catch_test_macros.hpp>
#include "Game.h"

// Example test case
TEST_CASE("Example test") {
  Game game(1920, 1080, "Test game");
  REQUIRE(game.GetWindowName() == "Test game");
  REQUIRE(game.GetWindowWidth() == 1920);
  REQUIRE(game.GetWindowHeight() == 1080);
}