#include "Game.h"
#include "raylib.h"

Game::Game(int windowWidth, int windowHeight, std::string windowName)
  : mWindowWidth(windowWidth), mWindowHeight(windowHeight), mWindowName(windowName)
{ }
Game::~Game()
{ }

void Game::Run()
{
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
  InitWindow(mWindowWidth, mWindowHeight, mWindowName.c_str());
  Texture2D face = LoadTexture("resources/face.png");
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);
    Draw();
    DrawTexture(face, mWindowWidth / 2, mWindowHeight / 2 + 20, WHITE);
    EndDrawing();
    Update();
  }
  UnloadTexture(face);
  CloseWindow();
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
