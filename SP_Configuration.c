#include <stdio.h>
#include "myLib.h"
#include "SP_GESTION_JEU.h"
#include "MesTypes.h"
#include "SP_Configuration.h"

/* Codage tableau des scores */
#define TAILLE_MAX 1000  /*tableau de taille 1000 */

void scores (){
    FILE *tableau_des_scores =NULL ;
    char chaine [TAILLE_MAX] = "";
    tableau_des_scores = fopen ("Tableau_des_scores.txt","rt");
    if (tableau_des_scores != NULL)
    {
        while (fgets(chaine,TAILLE_MAX,tableau_des_scores) != NULL)  /* on lit le fichier
tant qu'on ne re�oit pas d'erreur (NULL)*/  /* On lit au max Taille_max caract�res
du fichier, on stocke le tout dans "chaine" */
        {
            printf("%s", chaine); /* on affiche la chaine */
        }

        fclose(tableau_des_scores);
    }

    return ;
}



/* INITIALISATION DU JEU */


void Initialisation_jeu ()
{
    gotoxy(1,1);
    int j ;
    for (j=0;j<120*30;j++) /* initialise un terrain de 120*30 */
    {
         printStadeElement();
    }
    int rd_x =random()%(120+1) ; int rd_y = random()%(30+1);
    gotoxy(rd_x,rd_y);
    printPomme();
    rd_x =random()%(115) ; rd_y = random()%(30+1) ;
    gotoxy(rd_x,rd_y);
    printSnakeBody();
    printSnakeHead();
}

/*Sous programme menu options*/

void menu_options(ST_PARAM_JEU ParamDef)
{
    ST_PARAM_JEU Param=ParamDef;
    int choix1;
    int choix2;
    printf("**************\n Menu Options \n**************\n\n");
    while(choix2!=2)
    {
        printf("Couleur Stade : %d\nCouleur Snake : %d\n", Param.couleur_stade, Param.couleur_snake);
        printf("Difficulte: %d\nDimiensions stade: %dx%d\n\n", Param.difficulte, Param.H_stade, Param.L_stade);
        printf("voulez vous modifiez les options de jeu?\n 1.Oui\n 2.Non\n\n");
        scanf("%d",&choix1);
        if(choix1==1)
        {
            printf("\n\n 1.Couleur Stade\n 2.Couleur Snake\n 3.Difficulte\n 4.Hauteur stade\n 5.Longueur Stade\n 6.Quitter\n\n");
            scanf("%d", &choix2);
            switch (choix2)
            {
                case 1:
                    printf("\n modifiez l'option\n");
                    scanf("%d", &Param.couleur_stade);
                    break;
                case 2:
                    printf("\n modifiez l'option\n");
                    scanf("%d", &Param.couleur_snake);
                    break;
                case 3:
                    printf("\n modifiez l'option\n");
                    scanf("%d", &Param.difficulte);
                    break;
                case 4 :
                    printf("\n modifiez l'option\n");
                    scanf("%d", &Param.H_stade);
                    break;
                case 5 :
                    printf("\n modifiez l'option\n");
                    scanf("%d", &Param.L_stade);
                    break;
                case 6 :
                    SP_Titre();
                    SP_menuppl();
                    break;
            }
        }
        else if (choix1==2)
        {
            printf("pas de modif des options, retour � l'acceuil");
            SP_Titre();
            SP_menuppl();
        }
        else
        {
            printf("erreur");
        }
    }
}

void SP_Titre()
{
    setColor(RED);
    gotoxy(30,5);
    printf("**************************************\n");
    gotoxy(40,6);
    printf("BIENVENUE DANS SNAKE\n");
    gotoxy(30,7);
    printf("**************************************\n");
    hidecursor();
}

void SP_menuppl()
{
        gotoxy(40,10);
        setColor(GREEN);
        printf("%c Jouer\n",254);
        setColor(YELLOW);
        gotoxy(40,12);
        printf("%c Options",254);
        setColor(BLUE);
        gotoxy(40,14);
        printf("%c Scores",254);
        gotoxy(40,16);
        setColor(RED);
        printf("%c Quitter\n\n",254);
        setColor(WHITE);
}

