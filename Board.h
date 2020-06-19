
#ifndef _BOARD_
#define _BOARD_

// ------ Includes -----

#include "Piece.h"

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

    Board                       (Piece *pPiece, int pScreenHeight);

    int getXPosInPixels         (int pPos);
    int getYPosInPixels         (int pPos);
    bool isFreeBlock            (int pX, int pY); 

    bool isPossibleMovement     (int pX, int pY); 
    void storePiece             (int pX, int pY); 
    void deletePossibleLines    ();
    bool isGameOver             ();
    void updateCurrentPiece     (Piece * piece); 
    void clearBoard             ();
    int storedPieceType         (int x, int y);  

private:

    enum { POS_FREE, POS_FILLED };          
    int mBoard [BOARD_WIDTH][BOARD_HEIGHT]; 
    Piece* piece;
    int mScreenHeight;

    void initBoard();
    void deleteLine (int pY);
};

#endif