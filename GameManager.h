

#ifndef _GAMEMANAGER_
#define _GAMEMANAGER_

// ------ Includes -----

#include "Board.h"
#include "View.h"
#include "KeyBoardInputs.h"
#include <time.h>

// ------ Defines -----

#define WAIT_TIME 700           


class GameManager {
public:
    GameManager    (  View *pView,
               KeyBoardInputs *pKeyBoardInputs,
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
    KeyBoardInputs *keyBoardInputs;

    int getRand     (int pA, int pB); //
    void initGame   (); //
    void drawSprite  (int pX, int pY/*, color pColor*/, Sprite* sprite); //
    void drawBoard  (); //
};

#endif // _GAME_
