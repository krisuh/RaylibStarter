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
  std::string GetWindowName() const;
  int GetWindowHeight() const;
  int GetWindowWidth() const;
private:
  int mWindowWidth;
  int mWindowHeight;
  std::string mWindowName;
};