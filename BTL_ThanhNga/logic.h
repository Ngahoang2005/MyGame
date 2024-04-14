#ifndef _LOGIC_H__
#define _LOGIC_H__
#include "game.h"
#include<cmath>

bool mantouchtreasure(SDL_Rect*treasure)
{

    float center2x=treasure->x+50;
    float center2y=treasure->y+50;
    float d=sqrt((650-center2x)*(650-center2x)+(300-center2y)*(300-center2y));
    if(d<=100) return true;
    else return false;
}


#endif // _LOGIC_H__

