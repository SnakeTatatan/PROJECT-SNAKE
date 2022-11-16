#include <stdio.h>
#include "myLib.h"
#include "SP_GESTION_JEU.h"
#include "MesTypes.h"
/*#include "SP_Configuration.h"*/

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


void Initialisation_jeu (ST_PARAM_JEU Param_jeu, ST_SNAKE *serpent, ST_POMME *pomme)
{
    serpent->taille=0;      /* taille du serpent à l'initialisation */
    serpent->direction=DROITE;    /* on fais avancer le serpent lors de l'initialisation*/

    gotoxy(1,1);
    int h,i,j,k,l ;
    for (h=0 ; h<30 ; h++)
    {
        printf("                                                                                                               \n");
    }
    gotoxy(1,1);
    setBackgroundColor(Param_jeu.couleur_stade);

    for (k=0 ; k<Param_jeu.L_stade +2; k++)   /* mur haut du stade */
    {
        printStadeElement();
    }
    printf("\n");

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

    int rd_x =random()%(Param_jeu.L_stade-5) ; int rd_y = random()%(Param_jeu.H_stade-5);   /* initialisation du serpent au milieu et d'une pomme aléatoire */
    setColor(Param_jeu.couleur_snake);
    gotoxy(rd_x,rd_y);
    pomme->pos.x=rd_x;
    pomme->pos.y=rd_y;
    printPomme();
    gotoxy(floor(Param_jeu.L_stade/2),floor(Param_jeu.H_stade/2));
    serpent->tete.x=floor(Param_jeu.L_stade/2)+1;
    serpent->tete.y=floor(Param_jeu.H_stade/2);
    serpent->pos[serpent->taille].x=floor(Param_jeu.L_stade/2);
    serpent->pos[serpent->taille].y=floor(Param_jeu.H_stade/2);
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
    printf("Couleur Stade : %d\nCouleur Snake : %d\n", &Param->couleur_stade, Param->couleur_snake);
    printf("Difficulte: %d\nDimiensions stade: %d x %d\n\n", &Param->difficulte, Param->L_stade, Param->H_stade);
    printf("voulez vous modifiez les options de jeu?\n 1.Oui\n 2.Non\n\n");
    scanf("%d",&choix1);
    if(choix1==1)
    {
        printf("\n\n 1.Couleur Stade\n 2.Couleur Snake\n 3.Difficulte\n 4.Longueur stade\n 5.Hauteur Stade\n 6.Quitter\n\n");
        scanf("%d", &choix2);
        switch (choix2)
        {
            case 1:
                printf("\n modifiez la couleur du stade:\n 0.BLACK\n 1.BLUE\n 2.GREEN\n 3.CYAN\n 4.RED\n 5.MAGENTA\n 6.BROWN\n 7.GREY\n 8.DARKGREY\n 9.LIGHTBLUE\n 10.LIGHTGREEN\n 11.LIGHTCYAN\n 12.LIGHTRED\n 13.LIGHTMAGENTA\n 14.YELLOW\n 15.WHITE\n");
                scanf("%d", &Param->couleur_stade);
                menu_options(&Param);
                break;
            case 2:
                printf("\n modifiez la couleur du serpent:\n 0.BLACK\n 1.BLUE\n 2.GREEN\n 3.CYAN\n 4.RED\n 5.MAGENTA\n 6.BROWN\n 7.GREY\n 8.DARKGREY\n 9.LIGHTBLUE\n 10.LIGHTGREEN\n 11.LIGHTCYAN\n 12.LIGHTRED\n 13.LIGHTMAGENTA\n 14.YELLOW\n 15.WHITE\n");
                scanf("%d", &Param->couleur_snake);
                menu_options(&Param);
                break;
            case 3:
                printf("\n modifiez le niveau de difficulté: 1, 2 ou 3\n");
                scanf("%d", &Param->difficulte);
                menu_options(&Param);
                break;
            case 4 :
                printf("\n modifiez la longueur du stade:\n");
                scanf("%d", &Param->L_stade);
                menu_options(&Param);
                break;
             case 5 :
                printf("\n modifiez la hauteur du stade:\n");
                scanf("%d", &Param->H_stade);
                menu_options(&Param);
                break;
            case 6 :
                menu_options(&Param);
                printf("Couleur Stade : %d\nCouleur Snake : %d\n", &Param->couleur_stade, Param->couleur_snake);
                printf("Difficulte: %d\nDimiensions stade: %d x %d\n\n", &Param->difficulte, Param->L_stade, Param->H_stade);
                break;
        }
    }
    else if (choix1==2)
    {
        printf("pas de modif des options, retour a l'acceuil\n");
    }
    else if (choix1!=1 & choix1!=2)
    {
        printf("erreur");
        menu_options(Param);
    }
}



/*SP affichage*/
void SP_Titre()
{
    setColor(RED);
    gotoxy(20,5);
    printf("*************************************************************************************\n");
    gotoxy(50,6);
    printf("BIENVENUE DANS SNAKE\n");
    gotoxy(20,7);
    printf("*************************************************************************************\n");
    hidecursor();
}

void SP_menuppl()
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
}

/*renvoie la traduction de la difficulte en un temps en ms*/

int difficulte (ST_PARAM_JEU Param)
{
    int tps = 0 ;
    switch (Param.difficulte)
    {
    case 1 :
        tps=3000;
        break;

    case 2 :
        tps = 2000;
        break;

    case 3 :
        tps = 1000;
        break;

    default :
        break;

    }
    return tps;
}

/*SP avancer tete serpent*/

void avancer_tete(ST_SNAKE serpent)  /*fais avancer le serpent d'une case */
{
    switch(serpent.direction)
                    {
                    case HAUT :
                        serpent.tete.y += 1 ;
                        serpent.pos[0].y += 1 ;
                        break;
                    case BAS :
                        serpent.tete.y += -1 ;
                        serpent.pos[0].y += -1 ;
                        break;
                    case GAUCHE :
                        serpent.tete.x += -1 ;
                        serpent.pos[0].x += -1 ;
                        break;
                    case DROITE :
                        serpent.tete.x += 1 ;
                        serpent.pos[0].x += 1 ;
                        break;
                    default :
                        serpent.tete.x += 1 ;
                        serpent.pos[0].x += 1 ;
                        break;
                    }
}

/*SP_position serpent*/

void affichage_pos(ST_SNAKE serpent)
{
    gotoxy(serpent.tete.x,serpent.tete.y);
    printf(" %d , %d   ",serpent.tete.x,serpent.tete.y);
    printSnakeHead();
}


/* Parametre joueur */

void param_joueur(ST_JOUEUR jeu)
{
     cls();
     SP_Titre();
     setColor(YELLOW);
     printf(" \n \n Votre pseudo :");
     scanf("%c",&jeu.nom);
     cls();
}
