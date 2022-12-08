#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"
#include "SP_GESTION_JEU.h"
#include "MesTypes.h"
#include "SP_Configuration.h"


int main()
{
    /*initialisation des param�tres par defaut*/
    ST_JOUEUR joueur;
    ST_PARAM_JEU ParamDefaut;
    ST_POMME pomme;         /* initialisation des coord de la pomme*/
    ST_SNAKE serpent;
    ParamDefaut.couleur_snake=BLUE;
    ParamDefaut.couleur_stade=YELLOW;
    ParamDefaut.difficulte=1;
    ParamDefaut.H_stade=25;
    ParamDefaut.L_stade=100;
    char choix[10];

    while (strcmp(choix,"quitter") /*|| strcmp(choix,"quitter") == 1*/ )
    {
        setBackgroundColor(BLACK);
        cls();
        param_joueur (joueur);
        SP_Titre();
        SP_menuppl();
        scanf("%s",choix);

        if (strcmp(choix,"Options")==0 || strcmp(choix,"options")==0)
        {
             menu_options(&ParamDefaut);
        }

        else if (strcmp (choix,"Jouer")==0 || strcmp(choix,"jouer")==0)
        {
            int infini = 1;
            Initialisation_jeu(ParamDefaut,&serpent,&pomme); /* charge le serpent, le terrain, la pomme */
            int anc_dir;

            while (infini==1)
            {
                if (serpent.direction==DROITE || serpent.direction==GAUCHE || serpent.direction==BAS || serpent.direction==HAUT)
                {
                        anc_dir=serpent.direction;      /* permet d'enregistrer la derniere direction du serpent*/
                }
                serpent.direction=SP_Gestion_Clavier();
                serpent.old_tail=serpent.tete;
                switch(serpent.direction)
                {
                    case -1 :

                        switch (anc_dir)
                        {
                            case DROITE :
                                serpent.tete.x++;
                                break;
                            case GAUCHE :
                                serpent.tete.x--;
                                break;
                            case BAS :
                                serpent.tete.y++;
                                break;
                            case HAUT :
                                serpent.tete.y--;
                                break;
                        }
                        break;

                    case HAUT :
                        if (serpent.pos[0].y==serpent.tete.y - 1)
                        {
                            serpent.direction=-1;
                            anc_dir=BAS;
                            serpent.tete.y++;
                            break;
                        }
                        serpent.tete.y--;
                        break;
                    case BAS :
                         if (serpent.pos[0].y==serpent.tete.y +1)
                        {
                            serpent.direction=-1;
                            anc_dir=HAUT;
                            serpent.tete.y--;
                            break;
                        }
                        serpent.tete.y++;
                        break;
                    case DROITE :
                        if (serpent.pos[0].x==serpent.tete.x +1)
                        {
                            serpent.direction=-1;
                            anc_dir=GAUCHE;
                            serpent.tete.x--;
                            break;
                        }
                        serpent.tete.x++;
                        break;
                    case GAUCHE :
                         if (serpent.pos[0].x==serpent.tete.x - 1)
                        {
                            serpent.direction=-1;
                            anc_dir=DROITE;
                            serpent.tete.x++;
                            break;
                        }
                        serpent.tete.x--;
                        break;
                }
                if (pomme.pos.x==serpent.tete.x && pomme.pos.y==serpent.tete.y)
                {
                    SP_MangePomme(&serpent, &pomme, ParamDefaut);
                }
                affiche_serpent(&serpent);
                infini=echec(serpent,ParamDefaut);
                msleep(500);
                printf("h");
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
