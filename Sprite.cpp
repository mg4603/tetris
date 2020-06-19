
#include "Sprite.h"

// I
int I [5][5] =      {
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                    };
// L
int L [5][5] =      {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                    };
// L mirrored
int Lm [5][5] =     {
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                    };
//N
int N [5][5]  =     {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 1, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                    };
//N mirrored
int Nm [5][5]  =    {
                        {0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0},
                        {0 ,1, 1, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                    };
//Square
int S [5][5]  =     {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0}
                    };
//T
int T [5][5]  =     {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 1, 1, 1, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 0}
                    };


Sprite::Sprite (int spriteType, int spriteRotation)
{
    this->spriteType = spriteType;
    getSprite(spriteType);
    rotateSprite (spriteRotation);
}


void Sprite::getSprite(int spriteType)
{
    switch (spriteType)
    {
        // I
        case _I:
            std::copy(&I[0][0], &I[0][0] + 25, &mSprite[0][0]); break;
        // L
        case _L:
            std::copy(&L[0][0], &L[0][0] + 25, &mSprite[0][0]); break;
        // L mirrored
        case _Lm:
            std::copy(&Lm[0][0], &Lm[0][0] + 25, &mSprite[0][0]); break;
        //N
        case _N:
            std::copy(&N[0][0], &N[0][0] + 25, &mSprite[0][0]); break;
        //N mirrored
        case _Nm:
            std::copy(&Nm[0][0], &Nm[0][0] + 25, &mSprite[0][0]); break;
        //Square
        case _S:
            std::copy(&S[0][0], &S[0][0] + 25, &mSprite[0][0]); break;
        //T
        case _T:
            std::copy(&T[0][0], &T[0][0] + 25, &mSprite[0][0]); break;
        }
}


void Sprite::rotateSprite(int spriteRotation)
{
    int count = 0;
    while(count < spriteRotation )
    {
        for (int i = 0; i < SIZE - 1; i++)
        {
            for (int j = i; j < SIZE - i - 1; j++)
            {
                int temp                           = mSprite[i][j];
                mSprite[i][j]                       = mSprite[SIZE - j - 1][i];
                mSprite[SIZE - j - 1][i]            = mSprite[SIZE - i - 1][SIZE - j - 1];
                mSprite[SIZE - i - 1][SIZE - j - 1] = mSprite[j][SIZE - i - 1];
                mSprite[j][SIZE - i - 1]            = temp;
            }
        }
        count++;
    }
}


int Sprite::getXInitialPosition ()
{
    return -2;
}
int Sprite::getYInitialPosition ()
{
    for ( int i = 0; i < SIZE; i++ )
    {
        if ( mSprite[3][i] == 1 ) return -3;
        if ( mSprite[4][i] == 1 ) return -4;
    }
    return -2;
}
