
#ifndef LINUX
#endif
#include "Game.h"

Game::Game (View *pView, KeyBoardInputs *pKeyBoardInputs, int pScreenHeight )
{
    mScreenHeight = 430;

    view = pView;
    keyBoardInputs = pKeyBoardInputs;

    initGame();
}


int Game::getRand (int pA, int pB)
{
    return rand() % (pB - pA + 1) + pA;
}

void Game::createNewSprite()
{
    // New sprite
    sprite = nextSprite;
    board->updateCurrentSprite(sprite);

    posX          = (BOARD_WIDTH / 2) + sprite->getXInitialPosition();
    posY          = sprite->getYInitialPosition();

    nextSprite     = new Sprite(nextSpriteType, nextRotation);

    nextSpriteType = getRand(1, 7);
    nextRotation  = getRand(0, 3);
}

void Game::initGame()
{
    srand ((unsigned int) time (NULL));

    spriteType     = getRand (1, 7);
    rotation      = getRand (0, 3);
    nextSpriteType = getRand (1, 7);
    nextRotation  = getRand (0, 3);

    sprite     = new Sprite(spriteType, rotation);
    nextSprite = new Sprite(nextSpriteType, nextRotation);
    board     = new Board( sprite, mScreenHeight );

    posX      = (BOARD_WIDTH / 2) + sprite->getXInitialPosition();
    posY      = sprite->getYInitialPosition();

    nextPosX = -8;
    nextPosY = 4;
}


void Game::drawSprite(int pX, int pY, Sprite* pSprite)
{
    Sprite* spriteToDraw = pSprite;
    color mColor = static_cast<color>(spriteToDraw->spriteType);

    int xPosInPixels = board->getXPosInPixels(pX);
    int yPosInPixels = board->getYPosInPixels(pY);

    for(int i = 0; i < PIECE_BLOCKS; i++)
    {
        for(int j = 0; j < PIECE_BLOCKS; j++)
        {
            if(spriteToDraw->mSprite[i][j] != 0)
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
            mColor = static_cast<color>(board->storedSpriteType(i, j));
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
    drawSprite (posX, posY, sprite);				
    
    drawSprite (nextPosX, nextPosY, nextSprite); 

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
