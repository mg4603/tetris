
#include "View.h"

static SDL_Window  *win;
static SDL_Renderer *ren;
static SDL_Surface  *surface;
static SDL_Surface  *imgSurface;
static SDL_Texture *background_tx;						   
static Uint32 mColors [COLOR_MAX][4] = {  {0   , 0   , 0   , 0   },
                                          {0xc0, 0xc0, 0xc0, 0xff},					
                                          {0xff, 0x00, 0x00, 0xff},
                                          {0x00, 0xff, 0x00, 0xff},
                                          {0xad, 0xd8, 0xe6, 0xff},
                                          {0x00, 0xff, 0xff, 0xff},
                                          {0xff, 0x00, 0xff, 0xff},
                                          {0xff, 0xff, 0x00, 0xff},
                                          {0xff, 0xff, 0xff, 0xff} };

int View::messageBox ()
{
    const SDL_MessageBoxButtonData buttons[] = {
          {         0, 0, "NO" },
          { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "YES" },
      };
    const SDL_MessageBoxColorScheme colorScheme = {
          { 
              {   0,   0,   0 },
              {   0, 255,   0 },
              { 255, 255,   0 },
              { 205, 205, 205 },
              { 255,   0, 255 }
          }
      };
    const SDL_MessageBoxData messageboxdata = {
            SDL_MESSAGEBOX_INFORMATION, 
            NULL, 
            "GAME OVER!", 
            "Would you like to play again?", 
            SDL_arraysize(buttons), 
            buttons, 
            &colorScheme
        };

     int buttonid;
     if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
        SDL_Log("error displaying message box");
        return 1;
     }
     if (buttonid == -1) {
         SDL_Log("no selection");
     } else {
         return buttonid;
     }
     return 0;
}

View::View()
{
    initGraph();
}

int View::initGraph ()
{
    
    Uint32 videoflags;
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "SDL_Init Error: %s", SDL_GetError());
        return 1;
    }

    // win = SDL_CreateWindow("Tetris", 100, 100, 1024, 550, SDL_WINDOW_SHOWN);
    win = SDL_CreateWindow("Tetris",
                          SDL_WINDOWPOS_CENTERED,
                          SDL_WINDOWPOS_CENTERED,
                          700, 500,
                          SDL_WINDOW_OPENGL);

    if (win == NULL){
        fprintf(stderr, "SDL_CreateWindow Error: %s", SDL_GetError()) ;
        SDL_Quit();
        return 1;
    }

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL){
        SDL_DestroyWindow(win);
        fprintf(stderr, "SDL_CreateRenderer Error: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    surface = SDL_GetWindowSurface(win);
    background_tx = SDL_CreateTextureFromSurface (ren, surface);
    SDL_FreeSurface( surface );
    SDL_RenderCopy(ren, background_tx, NULL, NULL);

    updateScreen();

    return 1;
}






void View::drawBlock  (int pX1, int pY1, int pX2, int pY2, enum color pC)
{
    SDL_Rect r = {pX1, pY1, pX2, pY2};
    SDL_SetRenderDrawColor(ren, mColors[pC][0], mColors[pC][1], mColors[pC][2], mColors[pC][3]);
    SDL_RenderFillRect(ren, &r);

}


void View::clearScreen ()
{
    color pC = BLACK;
    SDL_SetRenderDrawColor(ren, mColors[pC][0], mColors[pC][1], mColors[pC][2], mColors[pC][3]);
    SDL_RenderClear(ren);
}

int View::getScreenHeight ()
{
    return SDL_GetWindowSurface(win)->h;
}

void View::updateScreen ()
{
    SDL_RenderPresent(ren);
}

void View::loadBackGround()
{
    SDL_RenderCopy(ren, background_tx, NULL, NULL);
}

void View::cleanUp()
{
    SDL_DestroyTexture(background_tx);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
