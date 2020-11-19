#include <stdio.h>
#include "functions.h"

int main()
{
    ouvrirFichier("pascal.p");
    lireCaractere();
    while(rester)
    {
        symSuiv();
        afficherToken();
    }
    
    getchar();
    return 1;
}