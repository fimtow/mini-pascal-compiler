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
    testSymbole(PROGRAM_TOKEN,PROGRAM_ERROR);
    testSymbole(ID_TOKEN,ID_ERROR);
    testSymbole(PV_TOKEN,PV_ERROR);
    block();
    testSymbole(PT_TOKEN,PT_ERROR);
}

void block()
{
    consts();
    vars();
    insts();
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
        while(symCour.code = ID_TOKEN)
        {
            symSuiv();
            testSymbole(EG_TOKEN,EG_ERROR);
            testSymbole(NUM_TOKEN,NUM_ERROR);
            testSymbole(PV_TOKEN,PV_ERROR);
        }
        break;
    case VAR_TOKEN: break;
    case BEGIN_TOKEN: break;
    default:
        erreur(CONST_VAR_BEGIN_ERROR);
        break;
    }
}

void vars()
{
    switch (symCour.code)
    {
    case VAR_TOKEN:
        symSuiv();
        testSymbole(ID_TOKEN,ID_ERROR);
        while (symCour.code == VIR_TOKEN)
        {
            symSuiv();
            testSymbole(ID_TOKEN,ID_ERROR);
        }
        testSymbole(PV_TOKEN,PV_ERROR);
        break;
    case BEGIN_TOKEN: break;
    default:
        erreur(VAR_BEGIN_ERROR);
        break;
    }
}

void insts()
{
    testSymbole(BEGIN_TOKEN,BEGIN_ERROR);
    inst();
    while(symCour.code == PV_TOKEN)
    {
        symSuiv();
        inst();
    }
    testSymbole(END_TOKEN,END_ERROR);
}

void inst()
{

}

void affec()
{
    testSymbole(ID_TOKEN,ID_ERROR);
    testSymbole(AFF_TOKEN,AFF_ERROR);
    expr();
}

void si()
{
    testSymbole(IF_TOKEN,IF_ERROR);
    cond();
    testSymbole(THEN_TOKEN,THEN_ERROR);
    inst();
}

void tantque()
{
    testSymbole(WHILE_TOKEN,WHILE_ERROR);
    cond();
    testSymbole(DO_TOKEN,DO_ERROR);
    inst();
}

void ecrire()
{
    testSymbole(WRITE_TOKEN,WRITE_ERROR);
    testSymbole(PO_TOKEN,PO_ERROR);
    expr();
    while(symCour.code == VIR_TOKEN)
    {
        symSuiv();
        expr();
    }
    testSymbole(PF_TOKEN,PF_ERROR);
}