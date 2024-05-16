#ifndef _DEFS__H
#define _DEFS__H
#include "graphics.h";
#include <SDL.h>
#include <SDL_image.h>
const int SCREEN_WIDTH= 1300;
const int SCREEN_HEIGHT = 600;
//extern const char* WINDOW_TITLE = "Hello World!";
//const int FULL_BLOOD=1000;
const int STRENGTH=500;
const int strength=25;
const int TIME=300000;
const int INITIAL_SPEED=3;

const int MAN_CLIPS[][4] = {
    {  0, 0, 100, 100},
    { 100, 0 ,100, 100},
};
const int MAN_FRAMES = sizeof(MAN_CLIPS)/sizeof(int)/4;

const int SWORD_CLIPS[][4] = {
    {  0, 0, 100, 100},
    { 100, 0 ,100, 100},
    {  200, 0, 100, 100},
    { 300, 0 ,100, 100},
    {  400, 0, 100, 100},
    { 500, 0 ,100, 100},
    {  600, 0, 100, 100},

};
const int SWORD_FRAMES = sizeof(SWORD_CLIPS)/sizeof(int)/4;

#endif

