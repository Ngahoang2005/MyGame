#include <iostream>
#include<cstdlib>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "graphics.h"
#include "defs.h"
#include "game.h"
#include "logic.h"
#include<ctime>
#include <chrono>
#include <thread>
using namespace std;
int time(int t) {
    auto start = chrono::steady_clock::now();
    this_thread::sleep_for(chrono::seconds(t));
    auto end =chrono::steady_clock::now();
    auto elapsed_seconds = chrono::duration_cast<chrono::seconds>(end - start);
    return elapsed_seconds.count();
}


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
     TTF_Font *font2=graphics.loadFont("assets/Purisa-BoldOblique.ttf", 10);
     SDL_Color color = {255, 255, 0, 0};

      SDL_Texture *time=graphics.renderText("WARNING: BOSS WILL APPEAR IN 5 MIN",font,color);
      SDL_Texture *time2=graphics.renderText("BE CAREFUL!!!!!!!!! PRESS TO CONTINUE",font,color);
      graphics.renderTexture(time,400,200);
      graphics.renderTexture(time2,300,400);
       graphics.presentScene();
      // waitUntilKeyPressed();
       SDL_DestroyTexture(time);
       SDL_DestroyTexture(time2);
       blue=NULL;time=NULL;
//VÀO BÀN -----------------------------------------------------------------------------------------------------------
   //HIỆN MAP VÀ NHÂN VẬT--------------------------------
   cerr<<"t";
     SDL_Texture *Map=graphics.loadTexture("img//map.png");
     SDL_Texture *thanhmau=graphics.loadTexture("img//bloodtab.png");
     SDL_Texture *treasurebag=graphics.loadTexture("img//treasurebag.png"); bool istreasurebagon=false;
     SDL_Texture *move1=graphics.loadTexture("img//spite_man.png");

     Uint32 starttime=SDL_GetTicks();

   Sprite man; man.init(move1,MAN_FRAMES,MAN_CLIPS);
    //KHAI BÁO CÁC STRUCT TRONG GAME
        //chuột của map
    SDL_Rect manHCN={600,550,100,100};
   Mouse mouse;  mouse.x=663;mouse.y=450;
   SDL_Rect mapb={0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
   SDL_Rect mapa={mouse.x,mouse.y,884,408};
   graphics.blitRect2(Map,&mapa,mapb);
   Mouse mousetreasure;
        //chuột của túi báu vật
   mousetreasure.x=200; mousetreasure.y=200;
   Treasure treasure;
   SDL_Rect treasurerect;
   treasurerect.x=mousetreasure.x;
   treasurerect.y=mousetreasure.y;
   treasurerect.w=100;
   treasurerect.h=100;
    treasure.createtreasure(graphics,treasurebag, treasurerect);
   Game game;

//HIỆN CHỮ KHI ĂN TÚI BẢO VẬT
SDL_Texture* bloodintreasure=graphics.renderText("blood+5",font,color);
SDL_Rect bloodtreasure={-1000,-1000,70,35};
SDL_Texture *strengthintreasure=graphics.renderText("strength+5",font,color);
SDL_Rect strengthtreasure={-1000,-1000,70,35};
         //TẠO CHUỘT CỤC EXP
        vector<Mouse> a;
        vector<SDL_Rect>b;
        SDL_Rect exxp={0,0,10,10};
         SDL_Texture *exp=graphics.loadTexture("img//exp.png");
         for(int i=0;i<100;i++)
        {
            Mouse mouseofexp;
            mouseofexp.x=static_cast<float>(rand()%2102-404);
            mouseofexp.y=static_cast<float>(rand()%1486-220);
            SDL_Rect rectofexp={mouseofexp.x,mouse.y,10,10};
        graphics.blitRect2(exp, &exxp, rectofexp);
        a.push_back(mouseofexp);
        b.push_back(rectofexp);
      }

//TẠO VÒNG LẶP

   SDL_Event e; bool click2=false;

    while (!click2) {

       SDL_PollEvent(&e);
        switch (e.type) {
            case SDL_QUIT:
                 exit(0); break;
            case SDL_KEYDOWN:

             const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
             if (currentKeyStates[SDL_SCANCODE_UP])
              {
                 if(mouse.y>100) {
                        mouse.turnNorth();
                        mousetreasure.turnNorth();
                  for(int i=0;i<100;i++)
                    a[i].turnNorth();}
                 else{
                        mouse.staystill();
                        mousetreasure.staystill();
                        for(int i=0;i<100;i++)
                            a[i].staystill();
                       }
             if (currentKeyStates[SDL_SCANCODE_DOWN])
              {
                 if(mouse.y<1000){
                        mouse.turnSouth();
                        mousetreasure.turnSouth();
                        for(int i=0;i<100;i++)
                            a[i].turnSouth();}
                 else {
                        mouse.staystill();
                 mousetreasure.staystill();
                 for(int i=0;i<100;i++) a[i].staystill();
                      }
               }
              if (currentKeyStates[SDL_SCANCODE_LEFT])
                {
                 if(mouse.x>0){
                        mouse.turnWest();
                 mousetreasure.turnWest();for(int i=0;i<100;i++) a[i].turnWest();}
                 else {
                        mouse.staystill();
                 mousetreasure.staystill();for(int i=0;i<100;i++) a[i].staystill();}
                }
              if (currentKeyStates[SDL_SCANCODE_RIGHT])
                {
                if(mouse.x<1300) {
                        mouse.turnEast();
                        mousetreasure.turnEast();
                        for(int i=0;i<100;i++) a[i].turnEast();}
                else {
                        mouse.staystill();
                mousetreasure.staystill();
                for(int i=0;i<100;i++) a[i].staystill();}
                 }
//MAP DI CHUYỂN
mouse.dichuyen();
mapa.x=mouse.x; mapa.y=mouse.y;
graphics.blitRect2(Map,&mapa,mapb);
//
for(int i=0;i<100;i++)
{
    a[i].dichuyen();
    b[i].x=a[i].x;
    b[i].y=a[i].y;
     graphics.blitRect2(exp, &exxp, b[i]);
}
       //TUIVANGDICHUYEN
        mousetreasure.tiengan();
        treasurerect.x=mousetreasure.x;
        treasurerect.y=mousetreasure.y;
        treasure.createtreasure(graphics,treasurebag, treasurerect);
//tạo hiệu ứng nhân vật di chuyển
man.tick();
graphics.render(SCREEN_WIDTH/2-150,SCREEN_HEIGHT/2-150,man,3);

if(mantouchtreasure(&treasurerect))
        {
           int randoftreasure=rand()%2;
           if(randoftreasure==0) {graphics.renderTexture(bloodintreasure, mousetreasure.x-10,mousetreasure.y);SDL_Delay(100);game.myblood+=5;}
           else {graphics.renderTexture(strengthintreasure, mousetreasure.x-10,mousetreasure.y);SDL_Delay(100);game.mystrength+=5;}
            treasurerect.x=rand()%2102-404;
            treasurerect.y=rand()%1486-220;
             mousetreasure.x=treasurerect.x;
            mousetreasure.y=treasurerect.y;
          treasure.createtreasure(graphics,treasurebag, treasurerect);

        }
        //hiện thanh máu
        game.hienthanhmau(graphics,thanhmau);
        graphics.presentScene();

        //HẾT VÒNG LẶP ẤN NÚT Ở ĐÂY
    }
    }
    }
   waitUntilKeyPressed();
  graphics.quit();

    return 0;
    }

