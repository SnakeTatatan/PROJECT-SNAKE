#ifndef SP_CONFIGURATION_H_INCLUDED
#define SP_CONFIGURATION_H_INCLUDED
#include "MesTypes.h"

void lecture_scores();

void Initialisation_jeu(ST_PARAM_JEU , ST_SNAKE *, ST_POMME *);

void menu_options(ST_PARAM_JEU *);

void SP_Titre();

void SP_menuppl();

int difficulte(ST_PARAM_JEU);

void avancer_tete(ST_SNAKE);

void param_joueur(ST_JOUEUR *);

void game_over(ST_JOUEUR*);

void ecriture_score(ST_JOUEUR*);

#endif // SP_CONFIGURATION_H_INCLUDED
