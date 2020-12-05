#include <stdio.h>
#include "lexerfunctions.h"
#include "parserfunctions.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
        erreur(ARG_ERR);
    ouvrirFichier(argv[1]);
    premierSym();
    program();
    if(symCour.code == FIN_TOKEN)
        printf("Le programme est correct");
    else
        printf("La fin du programme est erronee");
    getchar();
    return 1;
}