#include <stdio.h>
#include "myLib.h"
#include "SP_GESTION_JEU.h"
#include "Mes_SP.h"
#include "MesTypes.h"

int main()
{
    setColor(RED);
    gotoxy(30,5);
    printf("**************************************\n");
    gotoxy(40,6);
    printf("BIENVENUE DANS SNAKE\n");
    gotoxy(30,7);
    printf("**************************************\n");
    char choix[10];
    hidecursor();
    while (strcmp(choix,"quitter") || strcmp(choix,"quitter") == 1 )
    {
        printf("bonjouuuuuuur %s",choix);
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
        scanf("%s",choix);
        if (strcmp(choix,"Options") strcmp(choix,"options"))
        {

        }
        else if (strcmp (choix,"Jouer") || strcmp(choix,"jouer"))
        {

        }
        else if (strcmp(choix,"scores") || strcmp(choix,"Scores"))
        {

        }
        else
        {
            printf("Erreur de saisie, veuillez r�essayer\n");

        }
    }

    return 0;
}


