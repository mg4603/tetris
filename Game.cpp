
#ifndef LINUX
#endif
#include "Game.h"

Game::Game (View *pView, Commands *pCommands, int pScreenHeight )
{
    mScreenHeight = 430;

    view = pView;
    commands = pCommands;

    initGame();
}


int Game::getRand (int pA, int pB)
{
    return rand() % (pB - pA + 1) + pA;
}

void Game::createNewPiece()
{
    // New piece
    piece = nextPiece;
    board->updateCurrentPiece(piece);

    posX          = (BOARD_WIDTH / 2) + piece->getXInitialPosition();
    posY          = piece->getYInitialPosition();

    nextPiece     = new Piece(nextPieceType, nextRotation);

    nextPieceType = getRand(1, 7);
    nextRotation  = getRand(0, 3);
}

void Game::initGame()
{
    srand ((unsigned int) time (NULL));

    pieceType     = getRand (1, 7);
    rotation      = getRand (0, 3);
    nextPieceType = getRand (1, 7);
    nextRotation  = getRand (0, 3);

    piece     = new Piece(pieceType, rotation);
    nextPiece = new Piece(nextPieceType, nextRotation);
    board     = new Board( piece, mScreenHeight );

    posX      = (BOARD_WIDTH / 2) + piece->getXInitialPosition();
    posY      = piece->getYInitialPosition();

    nextPosX = -8;
    nextPosY = 4;
}


void Game::drawPiece(int pX, int pY, Piece* pPiece)
{
    Piece* pieceToDraw = pPiece;
    color mColor = static_cast<color>(pieceToDraw->pieceType);

    int xPosInPixels = board->getXPosInPixels(pX);
    int yPosInPixels = board->getYPosInPixels(pY);

    for(int i = 0; i < PIECE_BLOCKS; i++)
    {
        for(int j = 0; j < PIECE_BLOCKS; j++)
        {
            if(pieceToDraw->mPiece[i][j] != 0)
                view->drawBlock (xPosInPixels + i * BLOCK_SIZE,
                                     yPosInPixels + j * BLOCK_SIZE,
                                    BLOCK_SIZE - 1, BLOCK_SIZE -1,
                                     mColor);
        }
    }

}


void Game::drawBoard()
{
    int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
    int mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
    // int mY = mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT);
    int mY = 30;
    // Rectangles that delimits the board
	view->drawBlock (mX1 - BOARD_LINE_WIDTH, mY, BOARD_LINE_WIDTH, mScreenHeight - 20, BLUE);       // line on the left
    view->drawBlock (mX2, mY, BOARD_LINE_WIDTH, mScreenHeight - 20, BLUE);                          // line on the right
    view->drawBlock (mX1, mScreenHeight , BLOCK_SIZE * BOARD_WIDTH + 1, BOARD_LINE_WIDTH, BLUE );   // line on the botton

    mX1++;

    color mColor;

    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {
            mColor = static_cast<color>(board->storedPieceType(i, j));
            if(!board->isFreeBlock(i,j)){
                view->drawBlock( mX1 + i * BLOCK_SIZE,
				 mY + j * BLOCK_SIZE,
			 	 BLOCK_SIZE - 1, BLOCK_SIZE - 1,
				 mColor);
            }
        }
    }
}


void Game::drawScene ()
{
    view->clearScreen();                        
    view->loadBackGround();                     
    drawBoard ();				                
    drawPiece (posX, posY, piece);				
    
    drawPiece (nextPosX, nextPosY, nextPiece); 

    view->updateScreen();
}


bool Game::restart()
{
    int response = view->messageBox();
    if(response) {
        board->clearBoard();
        return true;
    }
    else return false;
}
