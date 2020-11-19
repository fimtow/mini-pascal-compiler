#include <stdio.h>
#include "functions.h"

int main()
{
    ouvrirFichier("pascal.p");
    lireCaractere();
    while(carCour != EOF)
    {
        symSuiv();
        AfficherToken(symCour);
    }
    getch();
    return 1;
}