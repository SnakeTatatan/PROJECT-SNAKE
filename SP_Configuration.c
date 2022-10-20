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
tant qu'on ne reçoit pas d'erreur (NULL)*/  /* On lit au max Taille_max caractères
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

