#ifndef LINUX
//#include <windows.h>
#include <stdlib.h>
//#include <tchar.h>
#endif
#include "GameManager.h"

const int SCREEN_WIDTH = 100;
const int SCREEN_HEIGHT = 480;


int main (int argc, char* args[])
{
    View view;
    KeyBoardInputs keyBoardInputs;
    int screenHeight = view.getScreenHeight();
    GameManager gameManager(&view, &keyBoardInputs, screenHeight);

    bool quit = false;
    SDL_Event e;

    unsigned long time1 = SDL_GetTicks();

    //  gameManager loop
    while (!quit)
    {
        gameManager.drawScene();

        int key = keyBoardInputs.pollkey(&e);
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
                if (gameManager.board->isPossibleMovement (gameManager.posX + 1, gameManager.posY))
                    gameManager.posX++;
                break;
            }
            case (SDLK_LEFT):
            {
                if (gameManager.board->isPossibleMovement (gameManager.posX - 1, gameManager.posY))
                    gameManager.posX--;
                break;
            }
            case (SDLK_DOWN):
            {
                if (gameManager.board->isPossibleMovement (gameManager.posX, gameManager.posY + 1))
                    gameManager.posY++;
                break;
            }
            case (SDLK_SPACE):
            {
               while (gameManager.board->isPossibleMovement(gameManager.posX, gameManager.posY))
                { gameManager.posY++; }

                gameManager.board->storeSprite (gameManager.posX, gameManager.posY - 1);
                gameManager.board->deletePossibleLines ();

                if (gameManager.board->isGameOver())
                {
                    if(!gameManager.restart()) goto exit_loop;
                }

                gameManager.createNewSprite();
                break;
            }
            case (SDLK_UP):
            {
                gameManager.sprite->rotateSprite();
                if (!gameManager.board->isPossibleMovement (gameManager.posX, gameManager.posY)){
                    int i = 3;
                    gameManager.sprite->rotateSprite(3);  //
                }
                break;
            }
        }

        unsigned long time2 = SDL_GetTicks();
        if ((time2 - time1) > WAIT_TIME)
        {
            if (gameManager.board->isPossibleMovement(gameManager.posX, gameManager.posY + 1)) {
                gameManager.posY++;
            } else {
                gameManager.board->storeSprite (gameManager.posX, gameManager.posY);
                gameManager.board->deletePossibleLines ();

                if(gameManager.board->isGameOver())
                {

                    if(!gameManager.restart()) break;
                }
                gameManager.createNewSprite();
            }

            time1 = SDL_GetTicks();
        }
    }
    exit_loop: ;

    view.cleanUp();
    return 0;
}
