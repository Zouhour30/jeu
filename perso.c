#include "perso.h"



int nb_frames_p = 15,vitesse_max=10;
void init_tab_anim(SDL_Rect *clip)
{
    //vers droite
    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].w = 100;
    clip[0].h = 100;
    int i = 1;
    for (i = 1; i < nb_frames_p; i++)
    {
        clip[i].w = 100;
        clip[i].h = 100;
        clip[i].x = clip[i].w + clip[i - 1].x;
        clip[i].y = 0;
    }

    //vers gauche
    clip[15].x = 0;
    clip[15].y = 100;
    clip[15].w = 100;
    clip[15].h = 100;
    i = 16;
    for (i = 16; i < (2 * nb_frames_p); i++)
    {
        clip[i].w = 100;
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = 100;
        clip[i].h = 100;
    }
    //stable right
    clip[30].x = 0;
    clip[30].y = 200;
    clip[30].w = 100;
    clip[30].h = 100;
    i = 31;
    for (i = 31; i < (3 * nb_frames_p); i++)
    {
        clip[i].w = 100;
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = 200;
        clip[i].h = 100;
    }

    //stable right
    clip[45].x = 0;
    clip[45].y = 300;
    clip[45].w = 100;
    clip[45].h = 100;
    i = 46;
    for (i = 46; i < (4 * nb_frames_p); i++)
    {
        clip[i].w = 100;
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = 300;
        clip[i].h = 100;
    }
}

void initialiser(personnage *p, int x)
{
    p->perso = IMG_Load("graphic/run.png");
    p->perso_pos.x = 30;
    p->perso_pos.y = 460;
    p->perso_pos_relative.x = 30;
    p->perso_pos_relative.y = 460;
    p->perso_pos.w = 100;
    p->perso_pos.h = 100;
    p->perso_pos_relative.h = 100;
    p->perso_pos_relative.w = 100;
    init_tab_anim(p->animation);
    p->frame=0;
p->direction=0;
p->stable=1;
p->score=100;
p->vie=30;
p->nb_perso=x;
p->acceleration=0;
p->mvtx=3;
p->mvty=120;
p->acc=0;
}
void afficher_perso(personnage * p , SDL_Surface *screen)
{
   SDL_BlitSurface(p->perso,&p->animation[p->frame], screen, &p->perso_pos);


}
void anim_right(personnage *p)
{
p->frame++; //avancer vers case suivante
//le domaine est de la case 0 -> 14
    if (p->frame <0 || p->frame > 14) p->frame=0;
}

void anim_left(personnage *p)
{
   p->frame++;
//le domaine est de la case 15 -> 29
    if (p->frame <15 || p->frame > 29) p->frame=15;

}


void anim_stable(personnage *p)
{
    p->frame++;

//right
if (p->direction==0){
//le domaine est de la case 30 -> 44
    if (p->frame <30 || p->frame > 44) p->frame=30;
    }

//left
if (p->direction==1){
//le domaine est de la case 45 -> 59
    if (p->frame <45 || p->frame > 59) p->frame=45;
    }


}

void mvt_perso_droite(personnage *p){

  anim_right(p);
  if (p->perso_pos.x < 1000)
          p->perso_pos.x += p->mvtx;
          if (p->perso_pos_relative.x < 1250)
          p->perso_pos_relative.x +=p->mvtx;
p->direction=0;
  p->stable=0;
}

void mvt_perso_droite_souris(personnage *p, int xmouse){

  anim_right(p);
  if (p->perso_pos.x < 1000 )
        p->perso_pos.x+=2;
        if (p->perso_pos_relative.x < 1250)
        p->perso_pos_relative.x += 2;
p->direction=0;
  p->stable=0;
}

void mvt_perso_gauche_souris(personnage *p, int xmouse){

  anim_left(p);
        p->perso_pos.x-=2;
        p->perso_pos_relative.x-=2;
p->direction=1;
  p->stable=0;
}
void mvt_perso_gauche(personnage *p ){

anim_left(p);
  p->perso_pos.x -= p->mvtx;
    p->perso_pos_relative.x -= p->mvtx;
    p->direction=1;
  p->stable=0;
}

int gameover(personnage *p){
  if(p->vie<=0 || p->score<= 0)
  return 1; // lose
  return 0; // keep playing
}

void jump_perso(personnage *p){
  p->perso_pos_relative.y -=p->mvty;
    p->perso_pos.y -=p->mvty;
  if(p->perso_pos_relative.y < 0 || p->perso_pos.y<0){
    p->perso_pos_relative.y = 5;
      p->perso_pos.y = 5;
  }
}

void apply_acceleration(personnage *p, Uint32 dt){
  if (p->acceleration%2==0) {
p->acc=0;
    p->mvtx=3;
  }
if(p->acceleration%2==1)
{
  if(p->mvtx<vitesse_max)
{
p->acc+=0.000001;
  p->mvtx+=0.5*p->acc*dt*dt+p->mvtx*dt/1000;
}
}
}
