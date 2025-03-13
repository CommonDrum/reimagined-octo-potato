
#include <SDL3/SDL.h>
#include <stdlib.h>
#include "sdl_setup.h"

#define MAX_RECTANGLES 100
SDL_FRect rectangles[MAX_RECTANGLES];
int current_index = 0;

void add_rect(float x, float y){
    if(current_index >= MAX_RECTANGLES){
        return;
    }
    rectangles[current_index++] = (SDL_FRect){x,y, 20.0f, 20.0f}; 
}

void queue_rectangles(SDL_Renderer *renderer){
    for (int i = 0; i < current_index; i++){
        SDL_RenderFillRect(renderer, &rectangles[i]);
    }
}



void apply_physics(){
    for (int i = 0; i < current_index; i++){
        bool clear = true;

        for (int j = 0; j < current_index; j++){
            if (i != j && 
                rectangles[i].y >= rectangles[j].y - 20.f && 
                rectangles[i].x + 20.f >= rectangles[j].x && 
                rectangles[i].x <= rectangles[j].x + 20.f){

                clear = false;
            }
        }
        if (rectangles[i].y < 460.0f && clear){
            rectangles[i].y += 0.001f;
        }
    }
}

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
        SDL_SetRenderDrawColorFloat(context->renderer, 1.0f, 0.0f, 0.0f, 1.0f); // Red
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
            if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
                int mouseX = event.button.x;
                int mouseY = event.button.y;


                if (event.button.button == SDL_BUTTON_LEFT) {
                    add_rect(mouseX, mouseY);

                } else if (event.button.button == SDL_BUTTON_RIGHT) {
                }
            }
        }
        apply_physics();
        queue_rectangles(context->renderer);

        SDL_RenderPresent(context->renderer);

    }

    sdl_cleanup(context);
    return 0;
}

