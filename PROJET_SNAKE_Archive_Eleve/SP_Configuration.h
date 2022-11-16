#ifndef SP_CONFIGURATION_H_INCLUDED
#define SP_CONFIGURATION_H_INCLUDED

void scores ();

void Initialisation_jeu (ST_PARAM_JEU , ST_SNAKE *, ST_POMME *);

void menu_options(ST_PARAM_JEU *);

void SP_Titre();

void SP_menuppl();

int difficulte (ST_PARAM_JEU);

void avancer_tete(ST_SNAKE);

void affichage_pos(ST_SNAKE serpent);
#endif // SP_CONFIGURATION_H_INCLUDED
