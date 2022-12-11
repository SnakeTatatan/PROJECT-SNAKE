#include <stdio.h>
#include <time.h>
#include "myLib.h"
#include "MesTypes.h"
#include "SP_Configuration.h"

/* SP de gestion des fleches directionnelles*/
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

/* SP de mise en mouvement du serpent*/
void affiche_serpent(ST_SNAKE *serpent, ST_POMME pomme)
{
    int i;
    int j;
    i=serpent->taille;
    if (pomme.pos.x==serpent->tete.x && pomme.pos.y==serpent->tete.y)
    {
        /*gere l'affichage du serpent dans le cas particulier ou celui ci mange une pomme*/
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
        /*affiche le mouvement du serpent dans le cas general*/
        gotoxy(serpent->pos[i-1].x,serpent->pos[i-1].y);
        printf(" "); /*efface le dernier element de la queue du serpent*/
        for (j=serpent->taille-1; j>0 ; j--)
        {
            serpent->pos[j]=serpent->pos[j-1]; /*chaque element de la queue prend l'ancienne position de l'element suivant*/
        }
        serpent->pos[0]=serpent->old_tail; /*le premier element de la queue prend l'ancienne position de la tete*/
        gotoxy(serpent->pos[0].x,serpent->pos[0].y);
        printSnakeBody(); /*affiche un element de la queue à l'ancienne position de la tete*/
        gotoxy(serpent->tete.x, serpent->tete.y);
        printSnakeHead();/* affiche la tete a sa nouvelle position*/
    }
}


/*SP pomme mangee*/
void SP_MangePomme(ST_SNAKE *serpent, ST_POMME *pomme, ST_PARAM_JEU param)
{
    int a=1;
    /*nouvelles coordonees de la pomme, a l'interieur du stade*/
    int rdx=random()%(param.L_stade-2)+1;
    int rdy=random()%(param.H_stade-2)+1;
    for(a==1; a==serpent->taille; a++)
    {
        /*cas ou la pomme apparait sur le serpent -> elle doit s'afficher autre part*/
        if (rdx==serpent->pos[a].x && rdy==serpent->pos[a].y || rdx==1 || rdy==1)
        {
            SP_MangePomme(&serpent, &pomme, param);
        }
    }
    setColor(param.couleur_snake);
    gotoxy(rdx,rdy);
    pomme->pos.x=rdx;
    pomme->pos.y=rdy;
    printPomme(); /*affiche la nouvelle pomme a une position valide*/
    serpent->taille++; /* incrementation de la taille du serpent*/
}
