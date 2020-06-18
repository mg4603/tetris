/**************************************************************************
 * Commands.h - Class that handles inputs (keyboard inputs)
/**************************************************************************/

#ifndef _COMMANDS_
#define _COMMANDS_

// ------- Includes --------

// #include "SDL2/include/SDL2/SDL.h"

#include <SDL2/SDL.h>


#include <stdlib.h>

// #pragma comment (lib, "SDL/lib/SDL.lib")

class Commands {
public:
    int pollkey    (SDL_Event *e);
    int isKeyDown  (int pKey);
};

#endif // _COMMANDS_
