#pragma once
#include <string>

class Game
{
public:
  Game(int windowWidth, int windowHeight, std::string windowName);
  ~Game();
  void Run();
  void Update();
  void Draw();
private:
  int mWindowWidth;
  int mWindowHeight;
  std::string mWindowName;
};