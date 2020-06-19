
// ------includes-------

#include "Board.h"


Board::Board (Piece *pPiece, int pScreenHeight)
{
	mScreenHeight = 430;

	piece = pPiece;

	initBoard();
}


int Board::getXPosInPixels (int pPos)
{
	return ( (BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) ) + (pPos * BLOCK_SIZE) );
}


int Board::getYPosInPixels (int pPos)
{
	return ( mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT) + (pPos * BLOCK_SIZE) );
}


bool Board::isFreeBlock (int pX, int pY)
{
	return (mBoard[pX][pY] == POS_FREE);
}


bool Board::isPossibleMovement (int pX, int pY)
{
	int boardX, boardY;
	for( int i = 0; i < PIECE_BLOCKS; i++)
	{
		boardX = pX + i;
		for ( int j = 0; j < PIECE_BLOCKS; j++)
		{
			boardY = pY + j;
		    if ( boardX < 0 || boardX > BOARD_WIDTH - 1 || boardY > BOARD_HEIGHT - 1 )
			{
				if( piece->mPiece[i][j] != 0)
					return 0;
			}
					if ( boardY >= 0)
			{
				if ( piece->mPiece[i][j] != 0 && !isFreeBlock(boardX, boardY))
					return false;
			}
		}
	}
//---------------------------------------------------------------------------------------------
	return true;
}


void Board::storePiece (int pX, int pY)
{
	int boardX, boardY;
	for (int i = 0; i < PIECE_BLOCKS; i++)
    {
		boardX = pX + i;
        for (int j = 0; j < PIECE_BLOCKS; j++)
        {
			boardY = pY + j;
    	       if ( piece->mPiece[i][j] != 0)
                mBoard[boardX][boardY] = piece->pieceType;
        }
    }
}


void Board::deletePossibleLines ()
{
	for (int i = 0; i < BOARD_HEIGHT; i++)
	{
		int col = 0;
		while ( col < BOARD_WIDTH )
		{
			if ( mBoard[col][i] == POS_FREE) break;
			col++;
		}
		if (col == BOARD_WIDTH) deleteLine(i);
	}
}


bool Board::isGameOver ()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
    {
        if (mBoard[i][0] != POS_FREE) return true;
    }

    return false;
}

void Board::deleteLine (int pY)
{
    for (int j = pY; j > 0; j--)
    {
        for (int i = 0; i < BOARD_WIDTH; i++)
        {
            mBoard[i][j] = mBoard[i][j-1];
        }
    }
}

void Board::initBoard()
{
    for (int i = 0; i < BOARD_WIDTH; i++)
        for (int j = 0; j < BOARD_HEIGHT; j++){
			mBoard[i][j] = 0;
	}
}


void Board::updateCurrentPiece(Piece *piece)
{
	this->piece = piece;
}

void Board::clearBoard()
{
	initBoard();
}

int Board::storedPieceType(int x, int y)
{
	return mBoard[x][y];
}
