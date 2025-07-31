#include "Game.h"
#include "raylib.h"

Game::Game(int windowWidth, int windowHeight, std::string windowName)
  : mWindowWidth(windowWidth), mWindowHeight(windowHeight), mWindowName(windowName)
{ }
Game::~Game()
{ }

void Game::Run()
{
  InitWindow(mWindowWidth, mWindowHeight, mWindowName.c_str());
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);
    Draw();
    EndDrawing();
    Update();
  }
}

void Game::Draw()
{
  DrawText("Hello there", mWindowWidth / 2, mWindowHeight / 2, 15, WHITE);
}

std::string Game::GetWindowName() const
{
  return mWindowName;
}

int Game::GetWindowHeight() const
{
  return mWindowHeight;
}

int Game::GetWindowWidth() const
{
  return mWindowWidth;
}

void Game::Update()
{
  float deltaTime = GetFrameTime();
}
