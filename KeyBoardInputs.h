
#ifndef _COMMANDS_
#define _COMMANDS_

// ------- Includes --------

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <stdlib.h>


class KeyBoardInputs {
public:
    int pollkey    (SDL_Event *e);
    int isKeyDown  (int pKey);
};

#endif 