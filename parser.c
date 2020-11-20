#include <stdio.h>
#include "lexerfunctions.h"
#include "parserfunctions.h"

int main()
{
    ouvrirFichier("pascal.p");
    premierSym();
    program();
    if(symCour.code == FIN_TOKEN)
        printf("Le programme est correct");
    else
        printf("La fin du programme est erronee");
    getchar();
    return 1;
}