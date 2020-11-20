#include "lexerfunctions.h"
#include "parserfunctions.h"

void testSymbole (codesLex cl, codesErr err){
    if(symCour.code == cl)
    {
        symSuiv();
    }
    else
    {
        erreur(err);
    }
    
}

void premierSym()
{
    lireCaractere();
    symSuiv();
}

void program()
{

}

void consts()
{
    switch (symCour.code)
    {
    case CONST_TOKEN:
        symSuiv();
        testSymbole(ID_TOKEN,ID_ERROR);
        testSymbole(EG_TOKEN,EG_ERROR);
        testSymbole(NUM_TOKEN,NUM_ERROR);
        testSymbole(PV_TOKEN,PV_ERROR);
        // a terminer
        break;
    
    default:
        break;
    }
}