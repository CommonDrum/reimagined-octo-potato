#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>

class Game{
  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;

  public:
    Game(int width, int height);
    ~Game();

    void Run();
    void ProcessInput();
    void Update();
};

#endif // !GAME_H

