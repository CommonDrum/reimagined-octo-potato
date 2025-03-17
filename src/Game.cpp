#include "Game.h"
#include <iostream>

Game::Game(int width, int height) {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "Game Engine",
        width,                    
        height,                    
        SDL_WINDOW_OPENGL         
    );

    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    isRunning = true;
}

Game::~Game(){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Game::Run(){
   while (isRunning) {
    ProcessInput();
    Update();
   }
}

void Game::ProcessInput(){
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_EVENT_QUIT) {
      isRunning = false;
    }
  }
}

void Game::Update(){

}
