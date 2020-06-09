#ifndef collision_H_INCLUDED
#define collision_H_INCLUDED

#include "perso.h"
#include "back.h"
#include"entite.h"

SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y);
void update_point_collision(personnage *hero);
int collision_droite(personnage *hero, background *bg);
int collision_gauche(personnage *hero, background *bg);
int collision_haut(personnage *hero, background *bg);
int collision_bas(personnage *hero, background *bg);
int detect_collision(personnage *p, entite* e);

void update_perfect_collision(personnage *p, background *bg);

#endif
