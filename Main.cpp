#ifndef LINUX
//#include <windows.h>
#include <stdlib.h>
//#include <tchar.h>
#endif
#include "Game.h"

const int SCREEN_WIDTH = 100;
const int SCREEN_HEIGHT = 480;


int main (int argc, char* args[])
{
    View view;
    Commands cmds;
    int screenHeight = view.getScreenHeight();
    Game game(&view, &cmds, screenHeight);

    bool quit = false;
    SDL_Event e;

    unsigned long time1 = SDL_GetTicks();

    //  game loop
    while (!quit)
    {
        game.drawScene();

        int key = cmds.pollkey(&e);
        while(SDL_PollEvent( &e ) != 0){
            if(e.type == SDL_QUIT)
                quit = true;
        }

       switch (key)
        {
            case (10):
            {
                quit = true;
            }
            case (SDLK_RIGHT):
            {
                if (game.board->isPossibleMovement (game.posX + 1, game.posY))
                    game.posX++;
                break;
            }
            case (SDLK_LEFT):
            {
                if (game.board->isPossibleMovement (game.posX - 1, game.posY))
                    game.posX--;
                break;
            }
            case (SDLK_DOWN):
            {
                if (game.board->isPossibleMovement (game.posX, game.posY + 1))
                    game.posY++;
                break;
            }
            case (SDLK_SPACE):
            {
               while (game.board->isPossibleMovement(game.posX, game.posY))
                { game.posY++; }

                game.board->storeSprite (game.posX, game.posY - 1);
                game.board->deletePossibleLines ();

                if (game.board->isGameOver())
                {
                    if(!game.restart()) goto exit_loop;
                }

                game.createNewSprite();
                break;
            }
            case (SDLK_UP):
            {
                game.sprite->rotateSprite();
                if (!game.board->isPossibleMovement (game.posX, game.posY)){
                    int i = 3;
                    game.sprite->rotateSprite(3);  //
                }
                break;
            }
        }

        unsigned long time2 = SDL_GetTicks();
        if ((time2 - time1) > WAIT_TIME)
        {
            if (game.board->isPossibleMovement(game.posX, game.posY + 1)) {
                game.posY++;
            } else {
                game.board->storeSprite (game.posX, game.posY);
                game.board->deletePossibleLines ();

                if(game.board->isGameOver())
                {

                    if(!game.restart()) break;
                }
                game.createNewSprite();
            }

            time1 = SDL_GetTicks();
        }
    }
    exit_loop: ;

    view.cleanUp();
    return 0;
}
