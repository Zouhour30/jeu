#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct {
SDL_Surface *perso ; // nsob feha taswiret perso
SDL_Rect perso_pos,perso_pos_relative; // pos du perso dans fenetre
SDL_Rect animation[60];
int frame; // pour parcourir tab animation : taswira 1 / 2 / 3 ....
int direction; //right = 0 ; left =1
int stable; // vrai = 1 ; faux=0
int vie;
int score;
int x1,x2,x3,x4,x5,x6,x7,x8,x9; //pt collision avec mask
int y1,y2,y3,y4,y5,y6,y7,y8,y9; //pt collision avec mask
float mvtx,mvty;
int nb_perso;
int acceleration; // activer /desactiver acceleration
float acc; //variable acceleration

}personnage ;

void init_tab_anim(SDL_Rect* clip); //t3abi tab animation
void initialiser (personnage *p, int x) ;
void afficher_perso(personnage * p , SDL_Surface *screen);
void anim_right(personnage *p);
void anim_left(personnage *p);
void anim_stable(personnage *p);
void mvt_perso_droite(personnage *p);
void mvt_perso_droite_souris(personnage *p, int xmouse);
void mvt_perso_gauche_souris(personnage *p, int xmouse);
void mvt_perso_gauche(personnage *p);
int gameover(personnage *p);
void jump_perso(personnage *p);
void apply_acceleration(personnage *p,Uint32 dt);
#endif
