#ifndef _GAME__H
#define _GAME__H
#include "graphics.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>

int timepassed=SDL_GetTicks();
struct Game{
    int myblood=FULL_BLOOD;
    int mystrength=STRENGTH;
    int hoanh=SCREEN_WIDTH/2;
    int tung=SCREEN_HEIGHT/2;
    int exp =level*100;
    int level=1;

   void hienthanhmau(Graphics &graphics,SDL_Texture *texture)
    {
        SDL_Rect printplace={30,30,500,25};
        float i=static_cast<float>(myblood)/FULL_BLOOD*100;
          if(i>=100) {SDL_Rect full={0,0,100,5};
            graphics.blitRect2(texture,&full,printplace);}

        for(int j=1;j<=20;j++)
        {

            if(100-5*(j-1)>=i&&i>100-5*j)
            {
                SDL_Rect a={0,5*(j-1),100,5};


                graphics.blitRect2(texture,&a,printplace);
                break;
            }
        }
    }
};
struct Mouse {
    float x,y;
    float dx = 0, dy = 0;
    float speed = 17;
    void dichuyen() {
        x += dx;
        y += dy;
    }
    void tiengan() {
        x-=dx*25/17;
        y-=dy*25/17;
    }
    void turnNorth() {
        dy = -speed;
        dx = 0;
    }
    void turnSouth() {
        dy = speed;
        dx = 0;
    }
    void turnWest() {
        dy = 0;
        dx = -speed;
    }
    void turnEast() {
        dy = 0;
        dx = speed;
    }
    void staystill(){
        dy=0;
        dx=0;
    }
};


struct Treasure{
    int addblood=5;
   void createtreasure(Graphics & graphics,SDL_Texture *texture,SDL_Rect &dest)
    {
        SDL_RenderCopy(graphics.renderer, texture, NULL, &dest);
      //  graphics.presentScene();
   }
};

struct Exp
{
  int exp=10;
  void createexp(Graphics& graphics, SDL_Texture * texture)
  {


  }
};

struct Monster
{
    int yourblood=100;
    int yourstrength=strength;
    int speed=100;

    void createmonster(Graphics &graphics)
    {
        SDL_Texture *monster=graphics.loadTexture("img//monster1.png");
            int x=rand()%SCREEN_WIDTH;
            int y=rand()%SCREEN_HEIGHT;
            float d=sqrt((x-SCREEN_WIDTH/2)*(x-SCREEN_WIDTH/2)+(y-SCREEN_HEIGHT/2)*(y-SCREEN_HEIGHT/2));
            SDL_Rect mona={0,0,100,100};
            SDL_Rect monb={x,y,100,100};
            graphics.blitRect2(monster,&mona,monb);
            graphics.presentScene();
    }

};


#endif


