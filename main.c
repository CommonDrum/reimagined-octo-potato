
#include <SDL3/SDL.h>
#include <stdlib.h>
#include "sdl_setup.h"

int main(int argc, char* argv[]) {
    bool done = false;
    
    SDLContext *context = (SDLContext*)malloc(sizeof(SDLContext));

    sdl_init(context);

    int windowWidth, windowHeight;
    SDL_GetWindowSize(context->window, &windowWidth, &windowHeight);


    SDL_FRect bar = {(float)windowWidth/2, 0.0f, 20.0f, 20.0f};

    while (!done) {
        SDL_Event event;

        SDL_SetRenderDrawColorFloat(context->renderer, 0.0f, 0.0f, 0.0f, 1.0f);
        SDL_RenderClear(context->renderer);
        SDL_SetRenderDrawColorFloat(context->renderer, 1.0f, 0.0f, 0.0f, 1.0f); // Red
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
            if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;


                if (event.button.button == SDL_BUTTON_LEFT) {
                    bar.x = mouseX;
                    bar.y = mouseY;

                } else if (event.button.button == SDL_BUTTON_RIGHT) {
                }
            }
        }

        SDL_RenderFillRect(context->renderer, &bar);

        SDL_RenderPresent(context->renderer);

    }

    sdl_cleanup(context);
    return 0;
}

