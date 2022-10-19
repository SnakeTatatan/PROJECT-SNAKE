#include <stdio.h>
#include <time.h>
#include "myLib.h"
#include "SP_GESTION_JEU.h"
#include "SP_Configuration.h"
#include "mesTypes.h"

/*Sous programme menu options*/

void menu_options(ST_PARAM_JEU ParamDef)
{
    ST_PARAM_JEU Param=ParamDef;
    int choix1;
    int choix2;
    printf("Couleur Stade : %d\n Couleur Snake", Param.couleur_stade, Param.couleur_snake);
    printf("Difficulte: %d\n Dimiensions stade: %dx%d\n\n", Param.difficulte, Param.H_stade, Param.L_stade);
    printf("voulez vous modifiez les options de jeu?\n 1.Oui\n 2.Non\n");
    scanf("%d",choix1);
    if(choix1==1)
    {
        printf("1.Couleur Snake\n 2.Couleur Stade\n 3.Difficulte\n 4.Hauteur stade\n 5.Longueur Stade\n 6.Quitter");
        scanf("%d",choix2);
        switch (choix2)
        {
            case 1:
                printf("modifiez l'option");
                scanf("%d", Param.couleur_snake);
                break;
            case 2:
                printf("modifiez l'option");
                scanf("%d", Param.couleur_stade);
                break;
            case 3:
                printf("modifiez l'option");
                scanf("%d", Param.difficulte);
                break;
            case 4 :
                printf("modifiez l'option");
                scanf("%d", Param.H_stade);
                break;
            case 5 :
                printf("modifiez l'option");
                scanf("%d", Param.L_stade);
                break;
            default :
                printf("quitter");
                break;
        }
        printf("Couleur Stade : %d\n Couleur Snake", Param.couleur_stade, Param.couleur_snake);
        printf("Difficulte: %d\n Dimiensions stade: %dx%d\n\n", Param.difficulte, Param.H_stade, Param.L_stade);
    }
    else
    {
        printf("pas de modif des options");
    }

}
