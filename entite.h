#ifndef entite_H_INCLUDED
#define entite_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct {
SDL_Surface *entite ;
SDL_Rect entite_pos;
SDL_Rect animation_entite[60];
int frame_entite;
int type;
int col;
int maxup,maxdown;
}entite ;

void init_tab_anim_entite(SDL_Rect* clip); //t3abi tab animation
void initialiser_entite (entite *e) ;
void afficher_entite(entite * e , SDL_Surface *screen);
void anim(entite *e);
void mvt_entite(entite *e, int xperso);
void mise_a_jour_entite(entite *e, int xperso);
void follow_perso(entite *e, int xperso);
#endif
