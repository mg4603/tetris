
#ifndef _BOARD_
#define _BOARD_

// ------ Includes -----

#include "Sprite.h"

// ------ Defines -----

#define BOARD_LINE_WIDTH 10        
#define BLOCK_SIZE 20              
#define BOARD_POSITION 300         
#define BOARD_WIDTH 10            
#define BOARD_HEIGHT 20           
#define MIN_VERTICAL_MARGIN 60    
#define MIN_HORIZONTAL_MARGIN 10  
#define PIECE_BLOCKS 5             


class Board {
public:

    Board                       (Sprite *pSprite, int pScreenHeight);

    int getXPosInPixels         (int pPos);
    int getYPosInPixels         (int pPos);
    bool isFreeBlock            (int pX, int pY); 

    bool isPossibleMovement     (int pX, int pY); 
    void storeSprite             (int pX, int pY); 
    void deletePossibleLines    ();
    bool isGameOver             ();
    void updateCurrentSprite     (Sprite * sprite); 
    void clearBoard             ();
    int storedSpriteType         (int x, int y);  

private:

    enum { POS_FREE, POS_FILLED };          
    int mBoard [BOARD_WIDTH][BOARD_HEIGHT]; 
    Sprite* sprite;
    int mScreenHeight;

    void initBoard();
    void deleteLine (int pY);
};

#endif