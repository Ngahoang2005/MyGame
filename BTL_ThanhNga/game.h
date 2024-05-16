#ifndef _GAME__H
#define _GAME__H
#include "graphics.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>

int timepassed=SDL_GetTicks();
struct Game{
    int FULL_BLOOD=1000;
    int myblood=1000;
    int mystrength=STRENGTH;
    int hoanh=SCREEN_WIDTH/2;
    int tung=SCREEN_HEIGHT/2;
    int deltaexp=1;
    int exp=0;
    int level=1;

    bool levelup ()
    {
        if(exp>=20*(level*level))
            return true;
        else return false;
    }
   void hienthanhmau(Graphics &graphics,SDL_Texture *texture)
    {
        SDL_Rect printplace={30,30,500,25};
        float i=static_cast<float>(myblood)/FULL_BLOOD*100;
          if(i>=100) {SDL_Rect full={0,0,100,5};
            graphics.blitRect2(texture,&full,&printplace);}
          if(i<=0) {
                SDL_Rect none={0,95,100,5};
                 graphics.blitRect2(texture,&none,&printplace);
            }
        for(int j=1;j<=20;j++)
        {

            if(100-5*(j-1)>=i&&i>100-5*j)

            {
                SDL_Rect a={0,5*(j-1),100,5};
                graphics.blitRect2(texture,&a,&printplace);
                break;
            }
        }
    }
};
struct Mouse {
    float x,y;
    float dx = 0, dy = 0;
    float speed = 12.5;
    void dichuyen() {
        x += dx*17/25;
        y += dy*17/25;
    }
    void tiengan() {
        x-=dx;
        y-=dy;
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
   }
};

struct Monster
{
    int monblood=12000;
    int monstrength=500;
    void hienthanhmau(Graphics &graphics,SDL_Texture *texture)
    {
        SDL_Rect printplace={780,30,500,25};
        float i=static_cast<float>(monblood)/120;
          if(i>=100) {SDL_Rect full={0,0,100,5};
            graphics.blitRect2(texture,&full,&printplace);}
             if(i>=100) {SDL_Rect full={0,0,100,5};
            graphics.blitRect2(texture,&full,&printplace);}
          if(i<=0) {
                SDL_Rect none={0,95,100,5};
                 graphics.blitRect2(texture,&none,&printplace);
            }
        for(int j=1;j<=20;j++)
        {

            if(100-5*(j-1)>=i&&i>100-5*j)

            {
                SDL_Rect a={0,5*(j-1),100,5};
                graphics.blitRect2(texture,&a,&printplace);
                break;
            }
        }
    }
    void createxoay(int x,int y,Graphics&graphics, SDL_Texture *xoay)
    {
        SDL_Rect printxoay;
           printxoay.w=100;
          printxoay.h=70;

         printxoay.x=x;
         printxoay.y=y;

SDL_Rect cutxoay={0,0,2468,2229};
       graphics.blitRect2(xoay,&cutxoay,&printxoay);

    }
      void createthunder(int x,int y,Graphics&graphics, SDL_Texture *thunder)
    {
SDL_Rect cutthunder={20,0,872,3000};
SDL_Rect printthunder;
printthunder.w=100;
printthunder.h=500;
 printthunder.x=x;
printthunder.y=y;

       graphics.blitRect2(thunder,&cutthunder,&printthunder);
    }
};


#endif


