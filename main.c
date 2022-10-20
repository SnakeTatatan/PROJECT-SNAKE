#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include "SP_GESTION_JEU.h"
#include "MesTypes.h"


int main()
{
    /*initialisation des param�tres par d�faut*/
    ST_PARAM_JEU ParamDefaut;
    ParamDefaut.couleur_snake=BLUE;
    ParamDefaut.couleur_stade=YELLOW;
    ParamDefaut.difficulte=1;
    ParamDefaut.H_stade=5;
    ParamDefaut.L_stade=5;
    setColor(RED);
    gotoxy(20,5);
    printf("*************************************************************************************\n");
    gotoxy(50,6);
    printf("BIENVENUE DANS SNAKE\n");
    gotoxy(20,7);
    printf("*************************************************************************************\n");
    char choix[10];
    hidecursor();
    while (strcmp(choix,"quitter") || strcmp(choix,"quitter") == 1 )
    {
        gotoxy(55,10);
        setColor(GREEN);
        printf("%c Jouer\n",254);
        setColor(YELLOW);
        gotoxy(55,12);
        printf("%c Options",254);
        setColor(BLUE);
        gotoxy(55,14);
        printf("%c Scores",254);
        gotoxy(55,16);
        setColor(RED);
        printf("%c Quitter\n\n",254);
        setColor(WHITE);
        scanf("%s",choix);
        if (strcmp(choix,"Options")==0 || strcmp(choix,"options")==0)
        {

        }
        else if (strcmp (choix,"Jouer")==0 || strcmp(choix,"jouer")==0)
        {
            int infini = 1;
            Initialisation_jeu(); /* charge le serpent, le terrain, la pomme */
            while (infini==1)
            {

            }
        }
        else if (strcmp(choix,"scores")==0 || strcmp(choix,"Scores")==0)
        {
            scores();
        }
        else
        {
            printf("Erreur de saisie, veuillez r�essayer\n");
        }
    }

    return 0;
}


