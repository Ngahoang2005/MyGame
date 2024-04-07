#include <iostream>
#include<cstdlib>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "graphics.h"
#include "defs.h"
#include "game.h"
#include<ctime>

using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

int main(int argc, char *argv[])
{
    srand(time(0));

//INTRO INTRO INTRO -------------------------------------------------------------------------------------------
    Graphics graphics;
    graphics.init();
    //ẢNH NỀN INTRO
    SDL_Texture *IntroBackground =graphics.loadTexture("img//intro.png");
    SDL_Rect dest={0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
    graphics.blitRect(IntroBackground,&dest,0,0);
    //nút play và ấn click
    SDL_Texture *PlayButton=graphics.loadTexture("img//playbutton.png");
    graphics.renderTexture(PlayButton,500,400);
    graphics.presentScene();

    SDL_Event event;
    bool click=false;
    while (!click) {

     SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                 exit(0);
                 break;
            case SDL_MOUSEBUTTONDOWN:
                    int x,y;
                    SDL_GetMouseState(&x,&y);
                    int playbuttonwidth, playbuttonheight;
                    SDL_QueryTexture(PlayButton,NULL,NULL,&playbuttonwidth,&playbuttonheight);
                 if(500<=x&&x<=500+playbuttonwidth&&400<=y&&y<=400+playbuttonheight){
                     click=true;}
        }
    }
   //hủy intro
   SDL_DestroyTexture(IntroBackground);
   SDL_DestroyTexture(PlayButton);
   IntroBackground=NULL;
   PlayButton=NULL;
//BEFORE PLAYING--------------------------------------------------------------------------------------------------
     SDL_Texture *blue=graphics.loadTexture("img//timeback.png");
    graphics.renderTexture(blue,0,0);
     TTF_Font* font = graphics.loadFont("assets/Purisa-BoldOblique.ttf", 20);
     SDL_Color color = {255, 255, 0, 0};

      SDL_Texture *time=graphics.renderText("WARNING: BOSS WILL APPEAR IN 5 MIN",font,color);
      SDL_Texture *time2=graphics.renderText("BE CAREFUL!!!!!!!!! PRESS TO CONTINUE",font,color);
      graphics.renderTexture(time,400,200);
      graphics.presentScene();
      SDL_Delay(1000);
      graphics.renderTexture(time2,300,400);
       graphics.presentScene();
       waitUntilKeyPressed();
       SDL_DestroyTexture(time);
       SDL_DestroyTexture(time2);
       blue=NULL;time=NULL;
//VÀO BÀN -----------------------------------------------------------------------------------------------------------
   //HIỆN MAP VÀ NHÂN VẬT--------------------------------
     SDL_Texture *Map=graphics.loadTexture("img//map.png");
     SDL_Texture *monster=graphics.loadTexture("img//monster1.png");
     SDL_Texture *thanhmau=graphics.loadTexture("img//bloodtab.png");
     SDL_Texture *treasurebag=graphics.loadTexture("img//treasurebag.png");
     SDL_Texture *move1=graphics.loadTexture("img//spite_man.png");

     int starttime=SDL_GetTicks();

   Sprite man; man.init(move1,MAN_FRAMES,MAN_CLIPS);
    //KHAI BÁO CÁC STRUCT TRONG GAME
   Mouse mouse;  mouse.x=663;mouse.y=450;
   Game game;
   Treasure treasure;

   SDL_Event e; bool click2=false;

    while (!click2) {
       SDL_PollEvent(&e);
        switch (e.type) {
            case SDL_QUIT:
                 exit(0); break;
            case SDL_KEYDOWN:
   //MAP DI CHUYỂN----------------------------------
          SDL_Rect moveneed={0,0,100,100};
          SDL_Rect mapb={0,0,SCREEN_WIDTH,SCREEN_HEIGHT}; SDL_Rect mapa={mouse.x,mouse.y,884,600};

        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if (currentKeyStates[SDL_SCANCODE_UP]){ if(mouse.y>0) mouse.turnNorth(); else mouse.staystill();}
        if (currentKeyStates[SDL_SCANCODE_DOWN]){if(mouse.y<900) mouse.turnSouth();else mouse.staystill();}
        if (currentKeyStates[SDL_SCANCODE_LEFT]){if(mouse.x>0) mouse.turnWest();else mouse.staystill();}
        if (currentKeyStates[SDL_SCANCODE_RIGHT]){if(mouse.x<1326) mouse.turnEast();else mouse.staystill();}
        mouse.dichuyen();
        //In lại map
        graphics.blitRect2(Map,&mapa,mapb);
       //tạo hiệu ứng nhân vật di chuyển
         man.tick();
        graphics.render(SCREEN_WIDTH/2-150,SCREEN_HEIGHT/2-150,man,3);
        //hiện thanh máu
        game.hienthanhmau(graphics,thanhmau);
        graphics.presentScene();
        int current=SDL_GetTicks()-starttime;
        if(current%2000==0)
       {
           treasure.createtreasure(graphics,treasurebag);
           starttime=current;
           current=SDL_GetTicks()-starttime;

       }

    }
    }
   waitUntilKeyPressed();
  graphics.quit();

    return 0;}

