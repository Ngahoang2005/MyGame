#ifndef _LOGIC_H_
#define _LOGIC_H__
#include<cmath>

bool mantouchtreasure(SDL_Rect*treasure)
{

    float center2x=treasure->x+50;
    float center2y=treasure->y+50;
    float d=sqrt((650-center2x)*(650-center2x)+(300-center2y)*(300-center2y));
    if(d<=100) return true;
    else return false;
}
bool mantouchexp(SDL_Rect* exp)
{
    float center2x=exp->x+5;
    float center2y=exp->y+5;
    float d=sqrt((650-center2x)*(650-center2x)+(300-center2y)*(300-center2y));
    if(d<=100) return true;
    else return false;
}
int choose ()
{
    int x,y;
    SDL_GetMouseState(&x,&y);
    if(300<=x&&x<=500&&300<=y&&y<=500) return 1;
    if(700<=x&&x<=900&&300<=y&&y<=500) return 2;
}
bool swordtouchmonster(int x,int y)
{
    if(x>880&&x<1100&&y>250&&y<550) return true;
    else return false;
}
bool swordtouchground(int x,int y)
{
    if(y>=550) return true;
    else return false;
}
bool swordtouchwall(int x,int y)
{
    if(x>=1200) return true;
    else return false;
}

#endif // _LOGIC_H__


