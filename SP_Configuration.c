#include <stdio.h>
#include "myLib.h"
#include "SP_GESTION_JEU.h"
#include "MesTypes.h"
#include "SP_Configuration.h"

/* Codage tableau des scores */
#define TAILLE_MAX 1000  /*tableau de taille 1000 */

void scores ()
{
    FILE *tableau_des_scores =NULL ;
    char chaine [TAILLE_MAX] = "";
    tableau_des_scores = fopen ("Tableau_des_scores.txt","rt");
    if (tableau_des_scores != NULL)
    {
        while (fgets(chaine,TAILLE_MAX,tableau_des_scores) != NULL)
/* on lit le fichier tant qu'on ne re�oit pas d'erreur (NULL)*/  /* On lit au max Taille_max caracteres
du fichier, on stocke le tout dans "chaine" */
        {
            printf("%s", chaine); /* on affiche la chaine */
        }

        fclose(tableau_des_scores);
    }

    return ;
}



/* INITIALISATION DU JEU */


void Initialisation_jeu (ST_PARAM_JEU Param)
{
    gotoxy(1,1);
    int j;
    int k;
    for (j=0;j<Param.H_stade;j++) /* initialise un terrain de L*H */
    {
        for (k=0;k<Param.L_stade;k++)
        {
            setColor(Param.couleur_stade);
            printStadeElement();
        }
    }
    int rd_x =random()%(Param.L_stade+1) ; int rd_y = random()%(Param.H_stade+1);
    gotoxy(rd_x,rd_y);
    setColor(LIGHTRED);
    printPomme();
    rd_x =random()%(Param.L_stade-5) ; rd_y = random()%(Param.H_stade+1) ;
    gotoxy(rd_x,rd_y);
    setColor(Param.couleur_snake);
    printSnakeBody();
    printSnakeHead();
}


/*OPTIONS*/
/*Sous programme menu options*/

void menu_options(ST_PARAM_JEU *Param)
{
    int choix1;
    int choix2;
    printf("**************\n Menu Options \n**************\n\n");
    printf("Couleur Stade : %d\nCouleur Snake : %d\n", Param->couleur_stade, Param->couleur_snake);
    printf("Difficulte: %d\nDimiensions stade: %d x %d\n\n", Param->difficulte, Param->L_stade, Param->H_stade);
    printf("voulez vous modifiez les options de jeu?\n 1.Oui\n 2.Non\n\n");
    scanf("%d",&choix1);
    if(choix1==1)
    {
        printf("\n\n 1.Couleur Stade\n 2.Couleur Snake\n 3.Difficulte\n 4.Longueur stade\n 5.Hauteur Stade\n 6.Quitter\n\n");
        scanf("%d", &choix2);
        switch (choix2)
        {
            case 1:
                printf("\n modifiez la couleur du stade:\n 1.BLACK\n 2.BLUE\n 3.GREEN\n 4.CYAN\n 5.RED\n 6.MAGENTA\n 7.BROWN\n 8.GREY\n 9.DARKGREY\n 10.LIGHTBLUE\n 11.LIGHTGREEN\n 12.LIGHTCYAN\n 13.LIGHTRED\n 14.LIGHTMAGENTA\n 15.YELLOW\n 16.WHITE\n");
                scanf("%d", &Param->couleur_stade);
                menu_options(Param);
                break;
            case 2:
                printf("\n modifiez la couleur du serpent:\n 1.BLACK\n 2.BLUE\n 3.GREEN\n 4.CYAN\n 5.RED\n 6.MAGENTA\n 7.BROWN\n 8.GREY\n 9.DARKGREY\n 10.LIGHTBLUE\n 11.LIGHTGREEN\n 12.LIGHTCYAN\n 13.LIGHTRED\n 14.LIGHTMAGENTA\n 15.YELLOW\n 16.WHITE\n");
                scanf("%d", &Param->couleur_snake);
                menu_options(Param);
                break;
            case 3:
                printf("\n modifiez le niveau de difficulté: 1, 2 ou 3\n");
                scanf("%d", &Param->difficulte);
                menu_options(Param);
                break;
            case 4 :
                printf("\n modifiez la longueur du stade:\n");
                scanf("%d", &Param->L_stade);
                menu_options(Param);
                break;
             case 5 :
                printf("\n modifiez la hauteur du stade:\n");
                scanf("%d", &Param->H_stade);
                menu_options(Param);
                break;
            case 6 :
                menu_options(Param);
                break;
        }
    }
    else if (choix1==2)
    {
        printf("pas de modif des options, retour a l'acceuil\n");
    }
    else
    {
        printf("erreur");
        menu_options(Param);
    }
}



/*SP affichage*/
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

