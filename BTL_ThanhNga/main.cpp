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
void waitUntilClick() {
    SDL_Event event;
    int isClicked = 0; // Biến để kiểm tra xem đã có click chuột chưa

    while (!isClicked) {
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT: // Thoát nếu nhấn nút đóng cửa sổ
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN: // Nếu click chuột
                isClicked = 1; // Đặt cờ báo hiệu đã click
                break;
            default:
                break;
        }
        SDL_Delay(10); // Ngủ một chút để giảm tải CPU
    }
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

//INTRO INTRO INTRO ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
//HƯỚNG DẪN------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SDL_Texture *ins1=graphics.loadTexture("img//ins1.png");
SDL_Texture *ins2=graphics.loadTexture("img//ins2.png");
SDL_Texture *backbut=graphics.loadTexture("img//back.png");
SDL_Texture *upbut=graphics.loadTexture("img//up.png");
SDL_Rect cutins={0,0,748,373};
SDL_Rect printins={0,0,1300,600};
SDL_Rect cutbutton={0,0,50,50};
SDL_Rect printsecondbutton1={1050,500,50,50};
SDL_Rect printsecondbutton2={1048,498,54,54};
SDL_Rect printbutton1={1100,500,50,50};
SDL_Rect printbutton2={1098,498,54,54};
bool backk=true;
bool upp=false;
bool isplaying=false;
while(isplaying==false)
{
        if (backk==true)
        {

            bool click=false;
            while(click==false)
            {
                cerr<<"T";
                SDL_Event t;
                SDL_PollEvent(&t);
                int x,y;
                SDL_GetMouseState(&x,&y);
                if(x>=1100&&x<=1150&&y>=500&&y<=550)
                {
                    graphics.blitRect2(ins1,&cutins,&printins);
                    graphics.blitRect2(upbut,&cutbutton,&printbutton2);
                   graphics.presentScene();
                }
                else{
            graphics.blitRect2(ins1,&cutins,&printins);
            graphics.blitRect2(upbut,&cutbutton,&printbutton1);
            graphics.presentScene();}
                if(t.type==SDL_MOUSEBUTTONDOWN&&x>=1100&&x<=1150&&y>=500&&y<=550)
                {
                   graphics.blitRect2(ins1,&cutins,&printins);
                    graphics.blitRect2(upbut,&cutbutton,&printbutton2);
                   graphics.presentScene();
                   backk=false;
                   upp=true;
                    click=true;
                }
            }
        }
        if(upp==true)
           {

            bool click=false;
            while(click==false)
            {
                SDL_Event t;
                SDL_PollEvent(&t);
                int x,y;
                SDL_GetMouseState(&x,&y);
                if(x>=1100&&x<=1150&&y>=500&&y<=550)
                {
                    graphics.blitRect2(ins2,&cutins,&printins);
                    graphics.blitRect2(backbut,&cutbutton,&printsecondbutton1);
                    graphics.blitRect2(upbut,&cutbutton,&printbutton2);
                   graphics.presentScene();
                }
                else if(x>=1050&&x<=1100&&y>=500&&y<=550)
                {
                    graphics.blitRect2(ins2,&cutins,&printins);
                    graphics.blitRect2(backbut,&cutbutton,&printsecondbutton2);
                    graphics.blitRect2(upbut,&cutbutton,&printbutton1);
                   graphics.presentScene();
                }
                else{
            graphics.blitRect2(ins2,&cutins,&printins);
            graphics.blitRect2(backbut,&cutbutton,&printsecondbutton1);
            graphics.blitRect2(upbut,&cutbutton,&printbutton1);
            graphics.presentScene();}
                if(t.type==SDL_MOUSEBUTTONDOWN&&x>=1050&&x<=1100&&y>=500&&y<=550)
                {
                    graphics.blitRect2(ins1,&cutins,&printins);
                    graphics.blitRect2(upbut,&cutbutton,&printbutton1);
                   graphics.presentScene();
                   backk=true;
                   upp=false;
                    click=true;
                }
                 if(t.type==SDL_MOUSEBUTTONDOWN&&x>=1100&&x<=1150&&y>=500&&y<=550)
                 {
                     click=true;
                     isplaying=true;
                 }
            }
        }
    }
cerr<<"i";
SDL_DestroyTexture(backbut);
SDL_DestroyTexture(upbut);
SDL_DestroyTexture(ins1);
SDL_DestroyTexture(ins2);
backbut=NULL;
upbut=NULL;
ins1=NULL;
ins1=NULL;





//BEFORE PLAYING-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
     SDL_Texture *blue=graphics.loadTexture("img//timeback.png");
    graphics.renderTexture(blue,0,0);
     TTF_Font* font = graphics.loadFont("assets/Purisa-BoldOblique.ttf", 20);
     TTF_Font *font2=graphics.loadFont("assets/Purisa-BoldOblique.ttf", 10);
     SDL_Color color = {255, 255, 0, 0};
     SDL_Color color2={0,255,255,255};

      SDL_Texture *time=graphics.renderText("WARNING: BOSS WILL APPEAR IN 3 MIN",font,color);
      SDL_Texture *time2=graphics.renderText("BE CAREFUL!!!!!!!!! PRESS TO CONTINUE",font,color);
      graphics.renderTexture(time,400,200);
      SDL_Delay(800);
      graphics.renderTexture(time2,300,400);
       graphics.presentScene();
      // waitUntilKeyPressed();
       SDL_DestroyTexture(time);
       SDL_DestroyTexture(time2);
       blue=NULL;time=NULL;
//VÀO BÀN ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   //HIỆN MAP VÀ NHÂN VẬT--------------------------------
     SDL_Texture *Map=graphics.loadTexture("img//map - Copy.png");
     SDL_Texture *thanhmau=graphics.loadTexture("img//bloodtab.png");
     SDL_Texture *treasurebag=graphics.loadTexture("img//treasurebag.png"); bool istreasurebagon=false;
     SDL_Texture *move1=graphics.loadTexture("img//spite_man.png");
     SDL_Texture *lv   = graphics.loadTexture("img//level up.png");
     SDL_Texture *bigmonster=graphics.loadTexture("img//bigmonster.png");

     SDL_Texture *mang[6][2];
mang[0][0]=graphics.loadTexture("img//runx2.png");
mang[0][1]=graphics.loadTexture("img//+20maxblood.png");
mang[1][0]=graphics.loadTexture("img//-25%blood+30%strength.png");
mang[1][1]=graphics.loadTexture("img//+20strength.png");
mang[2][0]=graphics.loadTexture("img//expx2.png");
mang[2][1]=graphics.loadTexture("img//+20maxblood.png");
mang[3][0]=graphics.loadTexture("img//+50maxblood.png");
mang[3][1]=graphics.loadTexture("img//-30%blood+40%strength.png");
mang[4][0]=graphics.loadTexture("img//+10%maxblood.png");
mang[4][1]=graphics.loadTexture("img//+10%strength.png");


     Uint32 starttime=SDL_GetTicks();
     Uint32 totalwaste=0;
   Sprite man; man.init(move1,MAN_FRAMES,MAN_CLIPS);
    //KHAI BÁO CÁC STRUCT TRONG GAME
        //chuột của map
   Mouse mouse;  mouse.x=663;mouse.y=450;
   //tạo chuột lưu giữ vị trí ban đầu
   Mouse origin;
origin.x=0.0;
origin.y=0.0;
   SDL_Rect mapb={0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
   SDL_Rect mapa={mouse.x,mouse.y,884,408};
   graphics.blitRect2(Map,&mapa,&mapb);
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


   //  SDL_Rect printtextoffullblood={}

//HIỆN CHỮ KHI ĂN TÚI BẢO VẬT
SDL_Texture* bloodintreasure=graphics.renderText("blood+10",font,color);
SDL_Rect bloodtreasure={-1000,-1000,70,35};
SDL_Texture *strengthintreasure=graphics.renderText("strength+10",font,color);
SDL_Rect strengthtreasure={-1000,-1000,70,35};
         //TẠO CHUỘT CỤC EXP
        vector<Mouse> a;
        vector<SDL_Rect>b;
        SDL_Rect exxp={0,0,10,10};
         SDL_Texture *exp=graphics.loadTexture("img//exp.png");
         for(int i=0;i<120;i++)
        {
            Mouse mouseofexp;
            mouseofexp.x=static_cast<float>(rand()%2097-404)+origin.x;
            mouseofexp.y=static_cast<float>(rand()%1463-404)+origin.y;
            SDL_Rect rectofexp={mouseofexp.x,mouse.y,10,10};
        graphics.blitRect2(exp, &exxp, &rectofexp);
        a.push_back(mouseofexp);
        b.push_back(rectofexp);
      }
      //hcn khi level up
       SDL_Rect skill1={300,300,200,200};
   SDL_Rect skill2={700,300,200,200};
     SDL_Rect throwaway={-1000,-1000,400,100};
SDL_Rect cutthelv={0,0,400,100};
SDL_Rect cuttheskill={0,0,200,200};
 SDL_Texture *beforefinal=graphics.loadTexture("img//beforefinal.png");
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
                 if(mouse.y>0) {
                        mouse.turnNorth();
                        origin.turnNorth();
                        mousetreasure.turnNorth();
                  for(int i=0;i<120;i++)
                    a[i].turnNorth();}
                 else{
                        mouse.staystill();
                        origin.staystill();
                        mousetreasure.staystill();
                        for(int i=0;i<120;i++)
                            a[i].staystill();
                       }
              }
             if (currentKeyStates[SDL_SCANCODE_DOWN])
              {
                 if(mouse.y<900){
                        mouse.turnSouth();
                        origin.turnSouth();
                        mousetreasure.turnSouth();
                        for(int i=0;i<120;i++)
                            a[i].turnSouth();}
                 else {
                        mouse.staystill();
                        origin.staystill();
                 mousetreasure.staystill();
                 for(int i=0;i<120;i++) a[i].staystill();
                      }
               }
              if (currentKeyStates[SDL_SCANCODE_LEFT])
                {
                 if(mouse.x>0){
                        mouse.turnWest();
                        origin.turnWest();
                 mousetreasure.turnWest();for(int i=0;i<120;i++) a[i].turnWest();}
                 else {
                        mouse.staystill();
                        origin.staystill();
                 mousetreasure.staystill();for(int i=0;i<120;i++) a[i].staystill();}
                }
              if (currentKeyStates[SDL_SCANCODE_RIGHT])
                {
                if(mouse.x<1300) {
                        mouse.turnEast();
                        origin.turnEast();
                        mousetreasure.turnEast();
                        for(int i=0;i<120;i++) a[i].turnEast();}
                else {
                        mouse.staystill();
                        origin.staystill();
                mousetreasure.staystill();
                for(int i=0;i<120;i++) a[i].staystill();}
                 }
//MAP DI CHUYỂN
mouse.dichuyen();
origin.tiengan();
mapa.x=mouse.x; mapa.y=mouse.y;
graphics.blitRect2(Map,&mapa,&mapb);
//
for(int i=0;i<120;i++)
{
    a[i].tiengan();
    b[i].x=a[i].x;
    b[i].y=a[i].y;
     graphics.blitRect2(exp, &exxp, &b[i]);
}
       //TUIVANGDICHUYEN
        mousetreasure.tiengan();
        treasurerect.x=mousetreasure.x;
        treasurerect.y=mousetreasure.y;
        treasure.createtreasure(graphics,treasurebag, treasurerect);
//tạo hiệu ứng nhân vật di chuyển
man.tick();
graphics.render(SCREEN_WIDTH/2-150,SCREEN_HEIGHT/2-150,man,3);
//kiểm tra va chạm với túi vàng
if(mantouchtreasure(&treasurerect))
        {
           int randoftreasure=rand()%2;
           if(randoftreasure==0) {graphics.renderTexture(bloodintreasure, mousetreasure.x-10,mousetreasure.y);SDL_Delay(100);game.myblood+=10;}
           else {graphics.renderTexture(strengthintreasure, mousetreasure.x-10,mousetreasure.y);SDL_Delay(100);game.mystrength+=10;}
            treasurerect.x=rand()%2060-404+origin.x;
            treasurerect.y=rand()%1400-404+origin.y;
             mousetreasure.x=treasurerect.x;
            mousetreasure.y=treasurerect.y;
          treasure.createtreasure(graphics,treasurebag, treasurerect);

        }
//kiểm tra va chạm với cục exp
for(int i=0;i<120;i++)
{
if(mantouchexp(&b[i]))
{
    game.exp+=game.deltaexp;
     a[i].x=static_cast<float>(rand()%2097-404)+origin.x;
    a[i].y=static_cast<float>(rand()%1463-404)+origin.y;
    b[i].x=a[i].x;
    b[i].y=a[i].y;
    graphics.blitRect2(exp, &exxp, &b[i]);

}
}
//IN CÁC THÔNG SỐ RA MÀN HÌNH
string sucmanh=to_string(game.mystrength);
string printsm="STRENGTH: "+sucmanh;
SDL_Texture *printsucmanh=graphics.renderText2(printsm,font,color2);
graphics.renderTexture(printsucmanh,850,30);
string fb=to_string(game.FULL_BLOOD);
string printfb= "FULL BLOOD: " +fb;
SDL_Texture *printfullblood=graphics.renderText2(printfb,font,color2);
graphics.renderTexture(printfullblood,600,30);
         //hiện thanh máu
          game.hienthanhmau(graphics,thanhmau);
          cerr<<game.exp<<endl;
//LEVEL UP --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
if(game.levelup())
{
    Uint32 t1=SDL_GetTicks();
    SDL_Rect printoflevelup={100,0,1200,300};
    graphics.blitRect2(lv,&cutthelv, &printoflevelup);
    SDL_Rect skilla=skill1;
    SDL_Rect skillb=skill2;

      graphics.blitRect2(mang[game.level-1][0],&cuttheskill,&skilla);
      graphics.blitRect2(mang[game.level-1][1],&cuttheskill,&skillb);
      graphics.presentScene();

           SDL_Event qwert;
           while(true){
        SDL_PollEvent(&qwert);

           if(qwert.type== SDL_MOUSEBUTTONDOWN)
            {
               if(choose()==1&&game.level==1)
                 {
               mouse.speed*=2;
               origin.speed*=2;
               mousetreasure.speed*=2;
               for(int i=0;i<120;i++) a[i].speed*=2;
                break;
                 }
               if(choose()==2&&game.level==1)
                 {
               game.FULL_BLOOD+=20;
               cerr<<game.myblood;
                break;
                 }
             if(choose()==1&&game.level==2)
                 {
                     game.myblood*=0.75;
                     game.mystrength*=1.3;
               break;
                 }
             if(choose()==2&&game.level==2)
                 {
                     game.mystrength+=20;
               break;
                 }
              if(choose()==1&&game.level==3)
                 {
                     game.deltaexp=2;
               break;
                 }
            if(choose()==2&&game.level==3)
                 {
                     game.FULL_BLOOD+=20;
               break;
                 }
             if(choose()==1&&game.level==4)
                 {
                     game.FULL_BLOOD+=50;
               break;
                 }
             if(choose()==2&&game.level==4)
                 {
                     game.myblood*=0.7;
                     game.mystrength*=1.4;
               break;
                 }
              if(choose()==1&&game.level==5)
                 {
                     game.FULL_BLOOD*=1,1;
               break;
                 }
                 if(choose()==2&&game.level==5)
                 {

                     game.mystrength*=1.1;
               break;
                 }
            }
        }
         Uint32 t2=SDL_GetTicks();
            Uint32 wastingtime=t2-t1;
            totalwaste+=wastingtime;

       graphics.blitRect2(Map,&mapa,&mapb);
            graphics.render(SCREEN_WIDTH/2-150,SCREEN_HEIGHT/2-150,man,3);
            treasure.createtreasure(graphics,treasurebag, treasurerect);
            for(int i=0;i<120;i++)
            {
            graphics.blitRect2(exp, &exxp, &b[i]);
            }
            game.hienthanhmau(graphics,thanhmau);
            graphics.renderTexture(printsucmanh,850,30);
             graphics.renderTexture(printfullblood,600,30);
             graphics.presentScene();
            game.level++; cerr<<game.level;

}
Uint32 current=SDL_GetTicks();
if(current+totalwaste-starttime>=180000) {cerr<<"tgian"<<current<<endl;click2=true;}

graphics.presentScene();
        //HẾT VÒNG LẶP ẤN NÚT Ở ĐÂY
}
}
//FINAL-----------------------------------------------------------------------------------

cerr<<"boss coming";
 graphics.presentScene();
SDL_Rect cutbeforefinal={0,0,390,180};
SDL_Rect printbeforefinal={0,0,1300,600};
graphics.blitRect2(beforefinal,&cutbeforefinal,&printbeforefinal);
graphics.presentScene();
//SDL_Delay(4000);
waitUntilKeyPressed();
Monster monster;
SDL_Rect cuttheman={0,0,300,300};
SDL_Rect cutthemon={0,0,840,632};
SDL_Rect finalman1={20,100,300,300};
SDL_Rect finalman2={10,140,320,320};
SDL_Rect monster1={700,100,430,316};
SDL_Rect monster2={690,900,450,450};
SDL_Texture *finalman=graphics.loadTexture("img//finalman.png");
SDL_Texture *finalmonster=graphics.loadTexture("img//bigmonster.png");
SDL_Texture *finalmap=graphics.loadTexture("img//finalmap.png");
SDL_Rect cutfinalmap={0,0,1900,1050};
SDL_Rect printfinalmap={0,0,1300,600};
do
{
     graphics.blitRect2(finalmap,&cutfinalmap,&printfinalmap);
    graphics.blitRect2(finalman,&cuttheman,&finalman1);
    graphics.blitRect2(finalmonster,&cutthemon,&monster1);
   game.hienthanhmau(graphics,thanhmau);
    monster.hienthanhmau(graphics,thanhmau);
    graphics.presentScene();
    monster.monblood-=game.mystrength;
    game.myblood-=monster.monstrength;
    graphics.blitRect2(finalmap,&cutfinalmap,&printfinalmap);
    graphics.blitRect2(finalman,&cuttheman,&finalman1);
    graphics.blitRect2(finalmonster,&cutthemon,&monster1);
     game.hienthanhmau(graphics,thanhmau);
    monster.hienthanhmau(graphics,thanhmau);
    graphics.presentScene();
    cerr<<game.myblood<<" "<<monster.monblood<<endl;
    SDL_Delay(1000);
}while(game.myblood>0&&monster.monblood>0);
if(game.myblood<monster.monblood) cerr<<"You lose";
else cerr<<"You win";

waitUntilKeyPressed();
 graphics.quit();

    return 0;
    }

