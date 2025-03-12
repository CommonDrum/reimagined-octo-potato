
#include <SDL3/SDL.h>
#include <stdlib.h>
#include "sdl_setup.h"

int main(int argc, char* argv[]) {
    bool done = false;
    
    SDLContext *context = (SDLContext*)malloc(sizeof(SDLContext));

    sdl_init(context);

    int windowWidth, windowHeight;
    SDL_GetWindowSize(context->window, &windowWidth, &windowHeight);

    while (!done) {
        SDL_Event event;

        SDL_SetRenderDrawColorFloat(context->renderer, 0.0f, 0.0f, 0.0f, 1.0f);
        SDL_RenderClear(context->renderer);

        const int barWidth = 20;  
        for (int x = 0; x < windowWidth; x += barWidth * 2) {
            SDL_FRect bar = {(float)x, 0.0f, (float)barWidth, (float)windowHeight};

            SDL_SetRenderDrawColorFloat(context->renderer, 1.0f, 0.0f, 0.0f, 1.0f); // Red
            
            SDL_RenderFillRect(context->renderer, &bar);
        }

        SDL_RenderPresent(context->renderer);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
        }
    }

    sdl_cleanup(context);
    return 0;
}

