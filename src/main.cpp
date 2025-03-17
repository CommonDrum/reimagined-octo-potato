
#include <SDL3/SDL.h>
#include "Game.h"
#include <iostream>


int main(int argc, char* argv[]) {
    
    Game game(640,480);
    game.Run();
    return 0;
}

