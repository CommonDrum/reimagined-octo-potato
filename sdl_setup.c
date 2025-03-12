#include "sdl_setup.h"

int sdl_init(SDLContext* ctx){
  
  SDL_Init(SDL_INIT_VIDEO);

  ctx->window = SDL_CreateWindow(
    "An SDL3 window",
    640,                               
    480,                                
    SDL_WINDOW_OPENGL                  
  );

  if (ctx->window == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
    return 1;
  }

  ctx->renderer = SDL_CreateRenderer(ctx->window, NULL);
  if (ctx->renderer == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create renderer: %s\n", SDL_GetError());
    SDL_DestroyWindow(ctx->window);
    SDL_Quit();
    return 1;
  }

  int windowWidth, windowHeight;
  SDL_GetWindowSize(ctx->window, &windowWidth, &windowHeight);

  return 0;
}



void sdl_cleanup(SDLContext* ctx){
  SDL_DestroyRenderer(ctx->renderer);
  SDL_DestroyWindow(ctx->window);
  SDL_Quit();
}
