#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include "SP_GESTION_JEU.h"
#include "MesTypes.h"


int main()
{
    /*initialisation des parametres par defaut*/
    ST_SNAKE serpent;
    ST_POMME pomme;
    int dir;
    ST_PARAM_JEU Param;
    Param.couleur_snake=BLUE;
    Param.couleur_stade=WHITE;
    Param.difficulte=1;
    Param.H_stade=30;
    Param.L_stade=120;
    SP_Titre();
    char choix[10];
    while (strcmp(choix,"quitter") || strcmp(choix,"quitter") == 1 )
    {
        SP_menuppl();
        scanf("%s",choix);
        if (strcmp(choix,"Options")==0 || strcmp(choix,"options")==0)
        {
            menu_options(&Param);
        }
        else if (strcmp (choix,"Jouer")==0 || strcmp(choix,"jouer")==0)
        {
            serpent.direction = DROITE;  /*au debut, le serpent ira a droite par default*/
            int infini = 1;
            Initialisation_jeu(Param,serpent); /* charge le serpent, le terrain, la pomme */
            while (infini==1)
            {
                dir = SP_Gestion_Clavier();
                if (dir==-1)
                {
                    avancer(serpent.direction);
                }
                affichage_pos(&serpent,&pomme);
                msleep(difficulte(Param));
            {

            }
        }
        else if (strcmp(choix,"scores")==0 || strcmp(choix,"Scores")==0)
        {
            scores();
        }
        else
        {
            printf("Erreur de saisie, veuillez reessayer\n");
        }
    }
    return 0;
}


