#include "functions.h"
#include <stdio.h>

char carCour;
tSymCour symCour;
FILE* fichier;

void ouvrirFichier(char* file)
{
    fichier = fopen(file,"r");
}

void lireCaractere()
{
    carCour = fgetc(fichier);
}

void symSuiv()
{
    if(isalpha(carCour))
    {
        lireMot();
    }
    else if(isdigit(carCour))
    {
        lireNombre();
    }
    else
    {
        switch(carCour)
        {
            case '+' : symCour.code = PLUS_TOKEN; lireCar(); break;
            default : symCour.code = ERREUR_TOKEN; erreur();
        }
    }
    
}

void afficherToken(tSymCour symcour)
{
    switch (symCour)
    {
    case ID_TOKEN:
        printf("ID_TOKEN\n");
        break;
    
    default:
        break;
    }
}

void lireNombre()
{

}

void lireMot()
{

}

void lireCar()
{

}

void erreur()
{

}