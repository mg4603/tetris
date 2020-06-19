
#ifndef _PIECE_
#define _PIECE_
#define SIZE 5
#include <iostream>


class Piece
{
public:
	Piece 					(int pieceType, int pieceRotation); 

	void rotatePiece        (int pieceRotation = 1); 
	int getXInitialPosition ();
	int getYInitialPosition ();

	int mPiece [5][5];    
	int pieceType;        

private:
	void getPiece		(int pieceType);  
	enum {ZERO, _I, _L, _Lm, _N, _Nm, _S, _T};
};

#endif // _piece_
