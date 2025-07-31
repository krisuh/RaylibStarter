#include "Game.h"

int main(int argc, char *argv[])
{
  int windowWidth = 1920;
  int windowHeight = 1080;
  Game game(windowWidth, windowHeight, APP_NAME);
  game.Run();
  return 0;
}
