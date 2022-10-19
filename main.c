#include <stdio.h>
#include "myLib.h"
#include "SP_GESTION_JEU.h"
#include "SP_Configuration.h"
#include "MesTypes.h"

int main()
{
    /*initialisation des paramètres par défaut*/
    ST_PARAM_JEU ParamDefaut;
    ParamDefaut.couleur_snake=BLUE;
    ParamDefaut.couleur_stade=YELLOW;
    ParamDefaut.difficulte=1;
    ParamDefaut.H_stade=5;
    ParamDefaut.L_stade=5;
    /*mise en page : SP_Titre*/
    SP_Titre();
    /*choix action*/
    char choix[10];
    while (strcmp(choix,"quitter") || strcmp(choix,"quitter") == 1 )
    {
        /*menu principal : SP_menuppl*/
        SP_menuppl();
        /*choix joueur*/
        scanf("%s",choix);
        if (strcmp(choix,"Options") || strcmp(choix,"options"))
        {
            menu_options(ParamDefaut);
        }
        else if (strcmp (choix,"Jouer") || strcmp(choix,"jouer"))
        {

        }
        else if (strcmp(choix,"scores") || strcmp(choix,"Scores"))
        {

        }
        else
        {
            printf("Erreur de saisie, veuillez réessayer\n");
        }
    }

    return 0;
}

