
#ifndef _SPRITE_
#define _SPRITE_
#define SIZE 5
#include <iostream>


class Sprite
{
public:
	Sprite 					(int spriteType, int spriteRotation); 

	void rotateSprite        (int spriteRotation = 1); 
	int getXInitialPosition ();
	int getYInitialPosition ();

	int mSprite [5][5];    
	int spriteType;        

private:
	void getSprite		(int spriteType);  
	enum {ZERO, _I, _L, _Lm, _N, _Nm, _S, _T};
};

#endif // _sprite_
