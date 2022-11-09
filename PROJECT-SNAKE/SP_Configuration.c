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


void Initialisation_jeu (ST_PARAM_JEU Param_jeu)
{
    gotoxy(1,1);
    int h,i,j,k,l ;
    for (h=0 ; h<30 ; h++)
    {
        printf("                                                                                                               \n");
    }
    gotoxy(1,1);

    for (k=0 ; k<Param_jeu.L_stade +2; k++)   /* mur haut du stade */
    {
        printStadeElement();
    }
    printf("\n");

    setBackgroundColor(Param_jeu.couleur_stade);

    for (i=0;i<Param_jeu.H_stade;i++)       /* initialise un terrain de H*L */
    {
         printStadeElement();
         for (j=0; j<Param_jeu.L_stade; j++)
         {

             printf(" ");
         }
         printStadeElement();
         printf("\n");
    }

    for (l=0 ; l<Param_jeu.L_stade+2; l++)       /* mur bas du stade */
    {
        printStadeElement();
    }

    int rd_x =random()%(Param_jeu.L_stade) ; int rd_y = random()%(Param_jeu.H_stade);   /* initialisation du serpent au milieu et d'une pomme aléatoire */
    gotoxy(rd_x,rd_y);
    printPomme();
    gotoxy(Param_jeu.L_stade/2,(Param_jeu.H_stade -1)/2);
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
        printf("Difficulte: %d\nDimensions stade: %dx%d\n\n", Param.difficulte, Param.H_stade, Param.L_stade);
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
