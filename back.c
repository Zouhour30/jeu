#include "back.h"

int width_bg=1244;

void initialiserr (background *b)
{
b->back=IMG_Load("graphic/bg.png");
b->mask=IMG_Load("graphic/mask_bg.png");//chniya load
b->back_pos.x = 0;
b->back_pos.y = 0;
b->back_pos_relative.x = 0;
b->back_pos_relative.y = 0;
b->camera.x=0;// scrooling
b->camera.y=0;
b->camera.w=1100;
b->camera.h=700;

}
int scrol_right(background *b, SDL_Surface *screen, personnage *p)
{
if (b->camera.x < width_bg - b->camera.w && p->perso_pos.x>150){
  b->back_pos_relative.x+=p->mvtx;
b->camera.x+=p->mvtx;
p->perso_pos_relative.x+=p->mvtx;
}
else return 1;

}

int scrol_left(background *b, SDL_Surface *screen, personnage *p)
{
if (b->camera.x > 0 ){
  b->back_pos_relative.x-=p->mvtx;
b->camera.x-=p->mvtx;
p->perso_pos_relative.x-=p->mvtx;
}
else return 1;

}

void affiche_back(background *b, SDL_Surface *screen)
{
   SDL_BlitSurface(b->back, &b->camera, screen, NULL);
//SDL_BlitSurface(b->mask, &b->camera, screen,&b->back_pos);

}
