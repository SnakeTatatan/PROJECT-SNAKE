#include <stdio.h>
#include <time.h>
#include "myLib.h"

#include "MesTypes.h"
#include "SP_Configuration.h"
/*#include "SP_GESTION_JEU.h"*/

/*===================================================================================
/ Nom S�mantique : FONCTION SP_Gestion_Clavier

/ S�mantique : G�re la d�tection des �v�nements clavier sur les touches de direction

/ Param�tres :
/ direction (OUT) - entier : Contient la direction sollicit�e par l'utilisateur
/ DROITE = 0 , GAUCHE = 1 , BAS = 2 , HAUT = 3 et -1 SINON
/ Pr�-condition : AUCUNE
/ Post conditions : la direction vaut -1,0,1,2,3
/ ====================================================================================
/ Test : le chiffre renvoy� correspond � la direction appuy�e
/ ====================================================================================*/
int SP_Gestion_Clavier()
{
    char direction ;
    int dir;

    if ( kbhit()) {

    direction = getkey() ;

    switch (direction){

        case KEY_UP : dir = HAUT ; break;
        case KEY_DOWN : dir = BAS ; break;
        case KEY_LEFT : dir = GAUCHE ; break;
        case KEY_RIGHT: dir= DROITE ; break;
        }
    }
    else {dir=-1;}
    return dir;
}

/* MOUVEMENT DU SERPENT*/

void affiche_serpent(ST_SNAKE *serpent, ST_POMME pomme)
{
    int i;
    int j;
    i=serpent->taille;
    if (pomme.pos.x==serpent->tete.x && pomme.pos.y==serpent->tete.y)
    {
        for (i=serpent->taille-1; i>0 ; i--)
        {
            serpent->pos[i]=serpent->pos[i-1];
        }
        serpent->pos[0]=serpent->old_tail;
        gotoxy(serpent->pos[0].x,serpent->pos[0].y);
        printSnakeBody();
        gotoxy(serpent->tete.x, serpent->tete.y);
        printSnakeHead();
    }
    else
    {
        gotoxy(serpent->pos[i-1].x,serpent->pos[i-1].y);
        printf(" ");
        for (j=serpent->taille-1; j>0 ; j--)
        {
            serpent->pos[j]=serpent->pos[j-1];
        }
        serpent->pos[0]=serpent->old_tail;
        gotoxy(serpent->pos[0].x,serpent->pos[0].y);
        printSnakeBody();
        gotoxy(serpent->tete.x, serpent->tete.y);
        printSnakeHead();
    }
}


/*sous programme pomme mang�e*/
void SP_MangePomme(ST_SNAKE *serpent, ST_POMME *pomme, ST_PARAM_JEU param)
{
    int rdx=random()%(param.L_stade-2);
    int rdy=random()%(param.H_stade-2);
    setColor(param.couleur_snake);
    gotoxy(rdx,rdy);
    pomme->pos.x=rdx;
    pomme->pos.y=rdy;
    printPomme();
    serpent->taille++;
}
