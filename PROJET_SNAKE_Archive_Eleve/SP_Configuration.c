#include <stdio.h>
#include "myLib.h"
#include "SP_GESTION_JEU.h"
#include "MesTypes.h"

/* Codage tableau des scores */
#define TAILLE_MAX 1000  /*tableau de taille 1000 */

/*SP de lecture du fichier score*/
void lecture_scores (FILE *scores)
{
    scores=fopen("scores.txt","rt"); /*ouvre le fichier en mode lecture*/
    char c;
    while((c=fgetc(scores))!=EOF)
    {
        printf("%c",c); /*affiche le contenu du fichier*/
    }
    fclose(scores); /*ferme le fichier*/
}



/* INITIALISATION DU JEU */
void Initialisation_jeu (ST_PARAM_JEU Param_jeu, ST_SNAKE *serpent, ST_POMME *pomme)
{
    serpent->taille=5;      /* taille du serpent à l'initialisation */
    serpent->direction=DROITE;    /* on fais avancer le serpent vers la droite lors de l'initialisation*/
    gotoxy(1,1);
    int p;
    int h,i,j,k,l ;
    for (h=0 ; h<30 ; h++)
    {
        printf("                                                                                                               \n");
    }
    gotoxy(1,1);
    setBackgroundColor(Param_jeu.couleur_stade);
    for (k=0 ; k<Param_jeu.L_stade +2; k++)   /* affiche le mur du haut du stade */
    {
        printStadeElement();
    }
    printf("\n");
    for (i=0;i<Param_jeu.H_stade;i++)       /* affiche les murs des cotes du stade*/
    {
         printStadeElement();
         for (j=0; j<Param_jeu.L_stade; j++)
         {
             printf(" ");
         }
         printStadeElement();
         printf("\n");
    }
    for (l=0 ; l<Param_jeu.L_stade+2; l++)       /* affiche le mur bas du stade */
    {
        printStadeElement();
    }
    int rd_x =random()%(Param_jeu.L_stade-2)+1 ; int rd_y = random()%(Param_jeu.H_stade-2)+1;   /* initialisation du serpent au milieu du stade et d'une pomme à un endroit aléatoire */
    setColor(Param_jeu.couleur_snake);
    gotoxy(rd_x,rd_y);
    pomme->pos.x=rd_x;
    pomme->pos.y=rd_y;
    printPomme();
    serpent->tete.x=floor(Param_jeu.L_stade/2);
    serpent->tete.y=floor(Param_jeu.H_stade/2);
    gotoxy(serpent->tete.x, serpent->tete.y );
    printSnakeHead();
}

/*Sous programme menu options*/
void menu_options(ST_PARAM_JEU *Param)
{
    int choix1;
    int choix2;
    printf("**************\n Menu Options \n**************\n\n");
    printf("Couleur Stade : %d\nCouleur Snake : %d\n", &Param->couleur_stade, &Param->couleur_snake);
    printf("Difficulte: %d\nDimiensions stade: %d x %d\n\n", &Param->difficulte, &Param->L_stade, &Param->H_stade); /*affiche les parametres actuels*/
    printf("voulez vous modifiez les options de jeu?\n 1.Oui\n 2.Non\n\n");
    scanf("%d",&choix1); /* le joueur choisis si il veut ou non modifier les options de jeu*/
    if(choix1==1)
    {
        while(choix2!=6)
        {
            /*affiche les parametres pouvant etre modifies*/
            printf("\n\n 1.Couleur Stade\n 2.Couleur Snake\n 3.Difficulte\n 4.Longueur stade\n 5.Hauteur Stade\n 6.Quitter\n\n");
            scanf("%d", &choix2);
            switch (choix2)
            {
                /*pour chaque choix, les valeurs pouvant être prises par le paramètre sont affichées et une doit être selectionnée par le joueur*/
                case 1:
                    printf("\n modifiez la couleur du stade:\n 0.BLACK\n 1.BLUE\n 2.GREEN\n 3.CYAN\n 4.RED\n 5.MAGENTA\n 6.BROWN\n 7.GREY\n 8.DARKGREY\n 9.LIGHTBLUE\n 10.LIGHTGREEN\n 11.LIGHTCYAN\n 12.LIGHTRED\n 13.LIGHTMAGENTA\n 14.YELLOW\n 15.WHITE\n");
                    scanf("%d", &Param->couleur_stade);
                    break;
                case 2:
                    printf("\n modifiez la couleur du serpent:\n 0.BLACK\n 1.BLUE\n 2.GREEN\n 3.CYAN\n 4.RED\n 5.MAGENTA\n 6.BROWN\n 7.GREY\n 8.DARKGREY\n 9.LIGHTBLUE\n 10.LIGHTGREEN\n 11.LIGHTCYAN\n 12.LIGHTRED\n 13.LIGHTMAGENTA\n 14.YELLOW\n 15.WHITE\n");
                    scanf("%d", &Param->couleur_snake);
                    break;
                case 3:
                    printf("\n modifiez le niveau de difficulté: facile : 200\n intermediaire: 100\n dificile: 50\n");
                    scanf("%d", &Param->difficulte);
                    break;
                case 4 :
                    printf("\n modifiez la longueur du stade:\n");
                    scanf("%d", &Param->L_stade);
                    break;
                case 5 :
                    printf("\n modifiez la hauteur du stade:\n");
                    scanf("%d", &Param->H_stade);
                    break;
                case 6 :
                    menu_options(&Param);
                    printf("Couleur Stade : %d\nCouleur Snake : %d\n", &Param->couleur_stade, &Param->couleur_snake);
                    printf("Difficulte: %d\nDimiensions stade: %d x %d\n\n", &Param->difficulte, &Param->L_stade, &Param->H_stade);
                    break;
            }
        }

    }
    /*retour au menu principal*/
    else if (choix1==2)
    {
        printf("pas de modif des options, retour a l'acceuil\n");
    }
    /*erreur de saisie*/
    else if (choix1!=1 & choix1!=2)
    {
        printf("erreur");
        menu_options(&Param);
    }
}



/*SP affichage du titre du jeu*/
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

/*SP affichage du menu principal*/
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

/*renvoie la traduction de la difficulte en un temps de pause en ms*/
int difficulte (ST_PARAM_JEU Param)
{
    int tps = 0 ;
    switch (Param.difficulte)
    {
    case 1 :
        tps=200;
        break;

    case 2 :
        tps = 100;
        break;

    case 3 :
        tps = 50;
        break;
    default :
        break;

    }
    return tps;
}

/*SP avancer tete serpent*/
void avancer_tete(ST_SNAKE serpent)  /*fais avancer la tete du serpent d'une case selon la direction choisie*/
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

/* Parametre joueur */
void param_joueur(ST_JOUEUR jeu)
{
    /*demande et enregistre le nom du joueur en debut de partie*/
     cls();
     SP_Titre();
     setColor(YELLOW);
     printf(" \n \n Votre pseudo :");
     scanf("%c",&jeu.nom);
     cls();
}

/*sp fin de jeu*/
void game_over(int score)
{
    /*affiche une page de fin de jeu ainsi que le score de la partie*/
    setBackgroundColor(BLACK),
    cls();
    setColor(WHITE);
    gotoxy(20,5);
    printf("*************************************************************************************\n");
    gotoxy(50,6);
    printf("GAME OVER\n");
    gotoxy(20,7);
    printf("*************************************************************************************\n");
    gotoxy(50,9);
    printf ("score : %d", score);
    hidecursor();
    msleep(3000);
}

/* SP enregistre scores*/
void ecriture_score(FILE *f, ST_JOUEUR joueur, int score)
{
    /*ouvre le fichier texte contenant les scores et ecrit un nouveau score et le nom du joueur correspondant*/
    f=fopen("scores.txt"," wt ");
    fprintf(f,"Nom\t Score\n\n") ;
    fprintf(f,"%s %i\n",joueur.nom, score);
    fclose(f);
}

