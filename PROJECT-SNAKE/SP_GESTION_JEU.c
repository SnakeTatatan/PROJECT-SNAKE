#include <stdio.h>
#include <time.h>
#include "myLib.h"
#include "MesTypes.h"
#include "SP_Configuration.h"
/*#include "SP_GESTION_JEU.h"*/

/*===================================================================================
/ Nom Sémantique : FONCTION SP_Gestion_Clavier
/ Sémantique : Gère la détection des évènements clavier sur les touches de direction
/ Paramètres :
/ direction (OUT) - entier : Contient la direction sollicitée par l'utilisateur
/ DROITE = 0 , GAUCHE = 1 , BAS = 2 , HAUT = 3 et -1 SINON
/ Pré-condition : AUCUNE
/ Post conditions : la direction vaut -1,0,1,2,3
/ ====================================================================================
/ Test : le chiffre renvoyé correspond à la direction appuyée
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


/*sous programme pomme mangée*/
void SP_MangePomme(ST_SNAKE *serpent, ST_POMME *pomme, ST_PARAM_JEU param)
{
    if(pomme->pos.x==serpent->tete.x & pomme->pos.y==serpent->tete.y)
    {
        int rdx=random()%(param.L_stade-5);
        int rdy=random()%(param.H_stade-5);
        setColor(param.couleur_snake);
        gotoxy(rdx,rdy);
        pomme->pos.x=rdx;
        pomme->pos.y=rdy;
        printPomme;
        serpent->taille++;
    }
}


/* MOUVEMENT DU SERPENT */

void affiche_serpent(ST_SNAKE *serpent)
{
    int i;
    i=serpent->taille;
    gotoxy(serpent->pos[i].x,serpent->pos[i].y);
    printf(" ");
    for (i=serpent->taille-1 ; i>0 ; i--)
    {
        serpent->pos[i]=serpent->pos[i-1];
    }
    serpent->pos[0]=serpent->old_tail;
    gotoxy(serpent->pos[0].x,serpent->pos[0].y);
    printSnakeBody();
    gotoxy(serpent->tete.x, serpent->tete.y);
    printSnakeHead();
}


/* Condition d'echec */

int echec (ST_SNAKE serpent, ST_PARAM_JEU Param_jeu)
{
    int i;
    for (i=0 ; i=serpent.taille ; i--)
    {
        if (serpent.tete.x==serpent.pos[i].x && serpent.tete.y==serpent.pos[i].y)
            {
                return 0;
            }

    }
    if (serpent.tete.x>=Param_jeu.L_stade || serpent.tete.x==0)
    {
        return 0;
    }
    else if (serpent.tete.y >= Param_jeu.H_stade || serpent.tete.y==0)
    {
        return 0;
    }
    return 1;
}


