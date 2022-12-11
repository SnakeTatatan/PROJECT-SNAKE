#ifndef SP_CONFIGURATION_H_INCLUDED
#define SP_CONFIGURATION_H_INCLUDED

void lecture_scores (FILE *);

void Initialisation_jeu (ST_PARAM_JEU , ST_SNAKE *, ST_POMME *);

void menu_options(ST_PARAM_JEU *);

void SP_Titre();

void SP_menuppl();

int difficulte (ST_PARAM_JEU);

void avancer_tete(ST_SNAKE);

void param_joueur(ST_JOUEUR);

void game_over(int);

void ecriture_score(FILE *,ST_JOUEUR,int);
#endif // SP_CONFIGURATION_H_INCLUDED
