#include "collision.h"

int collision;
int gravity=4;
int last_safe_x=30,last_safe_y=460;
SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y){
  SDL_Color color ;
  Uint32 col=0;
  char* pPosition = (char*) pSurface->pixels ;
  pPosition += (pSurface->pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);

  memcpy(&col , pPosition , pSurface->format->BytesPerPixel);
  SDL_GetRGB(col ,pSurface->format , &color.r , &color.g ,&color.b );


  return (color) ;
}

/*
pt de collision
en haut :  1 / 2 / 3     1 2 9
a droite : 3 / 4 / 5     8 3 4
en bas : 5 / 6 / 7       7 6 5
a gauche : 7 / 8 / 1
*/
void update_point_collision(personnage *hero){

hero->x1=hero->perso_pos_relative.x+20;
hero->y1=hero->perso_pos_relative.y;

hero->x2=hero->perso_pos_relative.x+hero->perso_pos_relative.w/2;
hero->y2=hero->perso_pos_relative.y;

hero->x3=hero->perso_pos_relative.x+hero->perso_pos_relative.w/2;
hero->y3=hero->perso_pos_relative.y+hero->perso_pos_relative.h/2;

hero->x4=hero->perso_pos_relative.x+hero->perso_pos_relative.w;
hero->y4=hero->perso_pos_relative.y+hero->perso_pos_relative.h/2;

hero->x5=hero->perso_pos_relative.x+hero->perso_pos_relative.w;
hero->y5=hero->perso_pos_relative.y+hero->perso_pos_relative.h/2;


hero->x6=hero->perso_pos_relative.x+hero->perso_pos_relative.w/2;
hero->y6=hero->perso_pos_relative.y+hero->perso_pos_relative.h;

hero->x7=hero->perso_pos_relative.x+20;
hero->y7=hero->perso_pos_relative.y+100;

hero->x8=hero->perso_pos_relative.x+20;
hero->y8=hero->perso_pos_relative.y+hero->perso_pos_relative.h/2;

hero->x9=hero->perso_pos_relative.x+hero->perso_pos_relative.w;
hero->y9=hero->perso_pos_relative.y;
}

int collision_droite(personnage *hero, background *bg){
  //return 0 si avec noir (ground) || return 1 si avec rouge (piege)
int collision=-1;

SDL_Color test2,test6,test3;
//test2=GetPixel(bg->mask,hero->x2,hero->y2);
//test6=GetPixel(bg->mask,hero->x6,hero->y6-10);
test3=GetPixel(bg->mask,hero->x3,hero->y3);

//avec noir
if (((test3.r==0) && (test3.g==0) && (test3.b==0) ) //test 5
//|| ( (test6.r==0) && (test6.g==0) && (test6.b==0) ) //test 4
//|| ( (test2.r==0) && (test2.g==0) && (test2.b==0) )
) //test 3
collision=0;

//avec rouge
if (( (test2.r==230) && (test2.g==12) && (test2.b==48) ) //test 5
//|| ( (test6.r==230) && (test6.g==12) && (test6.b==48) ) //test 4
|| ( (test3.r==230) && (test3.g==12) && (test3.b==48) )) //test 3
collision=1;

return collision;
}

int collision_gauche(personnage *hero, background *bg){
  //return 0 si avec noir (ground) || return 1 si avec rouge (piege)
int collision=-1;

SDL_Color test1,test7,test8;
test1=GetPixel(bg->mask,hero->x1,hero->y1);
test8=GetPixel(bg->mask,hero->x8,hero->y8);
test7=GetPixel(bg->mask,hero->x7,hero->y7);

//avec noir
if (( (test1.r==0) && (test1.g==0) && (test1.b==0) ) //test 1
|| ( (test8.r==0) && (test8.g==0) && (test8.b==0) ) //test 8
|| ( (test7.r==0) && (test7.g==0) && (test7.b==0) )) //test 7
collision=0;

//avec rouge
if (( (test1.r==230) && (test1.g==12) && (test1.b==48) ) //test 1
|| ( (test8.r==230) && (test8.g==12) && (test8.b==48) ) //test 8
|| ( (test7.r==230) && (test7.g==12) && (test7.b==48) )) //test 7
collision=1;

return collision;
}

int collision_haut(personnage *hero, background *bg){
  //return 0 si avec noir (ground) || return 1 si avec rouge (piege)
int collision=-1;

SDL_Color test1,test2,test3;
test1=GetPixel(bg->mask,hero->x1,hero->y1);
test2=GetPixel(bg->mask,hero->x2,hero->y2);
test3=GetPixel(bg->mask,hero->x3,hero->y3);

//avec noir
if (( (test1.r==0) && (test1.g==0) && (test1.b==0) ) //test 1
|| ( (test2.r==0) && (test2.g==0) && (test2.b==0) ) //test 2
|| ( (test3.r==0) && (test3.g==0) && (test3.b==0) )) //test 3
collision=0;

//avec rouge
if (( (test1.r==230) && (test1.g==12) && (test1.b==48) ) //test 1
|| ( (test2.r==230) && (test2.g==12) && (test2.b==48) ) //test 2
|| ( (test3.r==230) && (test3.g==12) && (test3.b==48) )) //test 3
collision=1;

return collision;
}

int collision_bas(personnage *hero, background *bg){
  //return 0 si avec noir (ground) || return 1 si avec rouge (piege)
collision=-1;

SDL_Color test5,test6,test7;
//test5=GetPixel(bg->mask,hero->x5,hero->y5);
test6=GetPixel(bg->mask,hero->x6,hero->y6);
test7=GetPixel(bg->mask,hero->x7,hero->y7);

//avec noir
if (
//  ( (test5.r==0) && (test5.g==0) && (test5.b==0) ) //test 5 ||
((test6.r==0) && (test6.g==0) && (test6.b==0) ) //test6
|| ( (test7.r==0) && (test7.g==0) && (test7.b==0) )
) //test 7
collision=0;

//avec rouge
if (
//  ( (test5.r==255) && (test5.g==0) && (test5.b==0) )||   //test 5
 ( (test6.r==255) && (test6.g==0) && (test6.b==0) ) //test6
|| ( (test7.r==255) && (test7.g==0) && (test7.b==0) )
) //test 7
collision=1;

return collision;

}


int detect_collision(personnage *p, entite* e){
  if (e->col==0){
if ((p->perso_pos_relative.x + p->perso_pos_relative.w/2< e->entite_pos. x) || (p->perso_pos_relative.x> e->entite_pos. x + e->entite_pos. w) ||
(p->perso_pos_relative.y + p->perso_pos_relative.h< e->entite_pos. y) || (p->perso_pos_relative.y> e->entite_pos. y + e->entite_pos. h ))
e->col= 0;
else
e->col=1;
}
return e->col;
}

void update_perfect_collision(personnage *p, background *bg){
//collision bas
  if (collision_bas(p,bg)==-1){ // collision avec rose (rien)
  p->perso_pos_relative.y+=gravity;
  p->perso_pos.y+=gravity;
}
if (collision_bas(p,bg)==0){ // collision avec noir (ground)
p->perso_pos_relative.y-=3;
p->perso_pos.y-=3;
}
    if (collision_bas(p,bg)==1) // collision avec rouge (piege)
          {
p->vie--;
bg->camera.x=0;
bg->camera.y=0;
          p->perso_pos_relative.y=460;
          p->perso_pos_relative.x=30;
          p->perso_pos.y=460;
          p->perso_pos.x=30;
          }
if (p->perso_pos_relative.y>450 && p->perso_pos_relative.x>300 ){
  if (collision_droite(p,bg)==0){ // collision avec noir (ground)
          p->perso_pos_relative.x-=10;
          p->perso_pos.x-=10;
          }
        }
}
