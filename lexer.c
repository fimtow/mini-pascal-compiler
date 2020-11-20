#include <stdio.h>
#include "lexerfunctions.h"

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