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

    int level=1;

   void hienthanhmau(Graphics &graphics,SDL_Texture *texture)
    {
        SDL_Rect printplace={30,30,500,25};
        float i=static_cast<float>(myblood)/FULL_BLOOD*100;

        for(int j=1;j<=20;j++)
        {

            if(100-5*(j-1)>=i&&i>100-5*j)
            {
                SDL_Rect a={0,5*(j-1),100,5};


                graphics.blitRect2(texture,&a,printplace);
               graphics.presentScene();
            }
        }
    }
};
struct Mouse {
    int x,y;
    int dx = 0, dy = 0;
    int speed = 25;
    void dichuyen() {
        x += dx;
        y += dy;

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
    int x;
    int y;
    int time;
   void createtreasure(Graphics & graphics,SDL_Texture *texture)
    {

       // SDL_Rect trea={0,0,100,100};
       // SDL_Rect treb={258,386,1436,1010};
        x=rand()%1442-71;
       y=rand()%1011-205;
        graphics.renderTexture(texture,x,y);
        graphics.presentScene();
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


