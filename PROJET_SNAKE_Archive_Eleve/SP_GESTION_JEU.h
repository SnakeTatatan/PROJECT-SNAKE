#ifndef SP_JEU_H_INCLUDED
#define SP_JEU_H_INCLUDED
#include "MesTypes.h"
#include "SP_Configuration.h"
#include "SP_GESTION_JEU.h"

int SP_Gestion_Clavier();

void affiche_serpent(ST_SNAKE *, ST_POMME);

void SP_MangePomme(ST_SNAKE * , ST_POMME *, ST_PARAM_JEU);



#endif // SP_JEU_H_INCLUDED
