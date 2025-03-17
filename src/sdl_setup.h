// sdl_setup.h
#ifndef SDL_SETUP_H
#define SDL_SETUP_H

#include <SDL3/SDL.h>

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} SDLContext;

int sdl_init(SDLContext* ctx);
void sdl_cleanup(SDLContext* ctx);

#endif 
