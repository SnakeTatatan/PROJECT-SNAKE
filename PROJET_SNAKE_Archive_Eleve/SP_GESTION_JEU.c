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
int SP_Gestion_Clavier(){
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

/* MOUVEMENT DU SERPENT */

void affiche_serpent(ST_SNAKE serpent)
{
    gotoxy(serpent.pos[serpent.taille-1].x,serpent.pos[serpent.taille-1].y);
    /*printf("%d , %d",serpent.pos[serpent.taille-1].x,serpent.pos[serpent.taille-1].y );*/
    printf(" ");
    gotoxy(serpent.old_tail.x,serpent.old_tail.y);
    printSnakeBody();
    gotoxy(serpent.tete.x,serpent.tete.y);
    printSnakeHead();
}



/*sous programme pomme mangée*/
void SP_MangePomme(ST_SNAKE *serpent, ST_POMME *pomme)
{
    if(pomme->pos.x==serpent->tete.x & pomme->pos.y==serpent->tete.y)
    {
        int rdx=random();
        int rdy=random();
        gotoxy(pomme->pos.x, pomme->pos.y);
        printf(" ");
        pomme->pos.x=rdx;
        pomme->pos.y=rdy;
        gotoxy(pomme->pos.x, pomme->pos.y);
        printPomme;
        serpent->taille++;
    }
}

