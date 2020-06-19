

#ifndef _GAME_
#define _GAME_

// ------ Includes -----

#include "Board.h"
#include "View.h"
#include "Commands.h"
#include <time.h>

// ------ Defines -----

#define WAIT_TIME 700           


class Game {
public:
    Game    (  View *pView,
               Commands *pCommands,
               int pScreenHeight );

    void drawScene      ();
    void createNewSprite ();
    bool restart        ();

    int posX, posY;
    int spriteType, rotation;

    Board *board;
    Sprite *sprite;
private:
    int mScreenHeight;
    int nextPosX, nextPosY;
    int nextSpriteType, nextRotation;

    Sprite *nextSprite;
    View *view;
    Commands *commands;

    int getRand     (int pA, int pB); //
    void initGame   (); //
    void drawSprite  (int pX, int pY/*, color pColor*/, Sprite* sprite); //
    void drawBoard  (); //
};

#endif // _GAME_
