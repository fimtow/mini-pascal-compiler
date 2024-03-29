#include "lexerfunctions.h"
#include "parserfunctions.h"
#include <string.h>
#define NBRIDFS 20
T_TAB_IDF TAB_IDFS[NBRIDFS];
int idfIndex = 0;
char idfCourant[20];
void testSymbole (codesLex cl, codesErr err){
    if(symCour.code == cl)
    {
        if(cl == ID_TOKEN)
            strcpy(idfCourant,symCour.nom);
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
    ajouterId(idfCourant,TPROG);
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
        ajouterId(idfCourant,TCONST);
        testSymbole(EG_TOKEN,EG_ERROR);
        testSymbole(NUM_TOKEN,NUM_ERROR);
        testSymbole(PV_TOKEN,PV_ERROR);
        while(symCour.code == ID_TOKEN)
        {
            ajouterId(symCour.nom,TCONST);
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
        ajouterId(idfCourant,TVAR);
        while (symCour.code == VIR_TOKEN)
        {
            symSuiv();
            testSymbole(ID_TOKEN,ID_ERROR);
            ajouterId(idfCourant,TVAR);
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
    switch (symCour.code)
    {
    case BEGIN_TOKEN:
        insts();
        break;
    case ID_TOKEN:
        affec();
        break;
    case IF_TOKEN:
        si();
        break;
    case WHILE_TOKEN:
        tantque();
        break;
    case WRITE_TOKEN:
        ecrire();
        break;
    case READ_TOKEN:
        lire();
        break;
    case PV_TOKEN:
        break;
    case END_TOKEN:
        break;
    default:
        erreur(INST_ERROR);
        break;
    }
}

void affec()
{
    testSymbole(ID_TOKEN,ID_ERROR);
    if(verifierId(idfCourant) != TVAR)
        erreur(NON_VAR);
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

void lire()
{
    testSymbole(READ_TOKEN,READ_ERROR);
    testSymbole(PO_TOKEN,PO_ERROR);
    testSymbole(ID_TOKEN,ID_ERROR);
    if(verifierId(idfCourant) != TVAR)
        erreur(NON_VAR);
    while(symCour.code == VIR_TOKEN)
    {
        symSuiv();
        testSymbole(ID_TOKEN,ID_ERROR);
        if(verifierId(idfCourant) != TVAR)
            erreur(NON_VAR);
    }
    testSymbole(PF_TOKEN,PF_ERROR);
}

void cond()
{
    expr();
    switch (symCour.code)
    {
    case EG_TOKEN:
        symSuiv();
        break;
    case DIFF_TOKEN:
        symSuiv();
        break;   
    case INF_TOKEN:
        symSuiv();
        break; 
    case SUP_TOKEN:
        symSuiv();
        break; 
    case INFEG_TOKEN:
        symSuiv();
        break; 
    case SUPEG_TOKEN:
        symSuiv();
        break; 
    default:
        erreur(COND_ERROR);
        break;
    }
    expr();
}

void expr()
{
    term();
    while(symCour.code == PLUS_TOKEN || symCour.code == MOINS_TOKEN)
    {
        symSuiv();
        term();
    }
}

void term()
{
    fact();
    while(symCour.code == MULT_TOKEN || symCour.code == DIV_TOKEN)
    {
        symSuiv();
        fact();
    }
}

void fact()
{
    switch (symCour.code)
    {
    case ID_TOKEN:
        if(verifierId(symCour.nom) == TPROG)
            erreur(IDF_PRO);
        symSuiv();
        break;
    case NUM_TOKEN:
        symSuiv();
        break;
    case PO_TOKEN:
        symSuiv();
        expr();
        testSymbole(PF_TOKEN,PF_ERROR);
        break;
    default:
        erreur(FACT_ERROR);
        break;
    }
}

void ajouterId(char* nom,TSYM type)
{
    for(int i=0;i<idfIndex;i++)
    {
        if(strcmp(nom,TAB_IDFS[i].NOM) == 0)
            erreur(DOU_DEC);
    }
    strcpy(TAB_IDFS[idfIndex].NOM,nom);
    TAB_IDFS[idfIndex].TIDF = type;
    idfIndex++;
}

TSYM verifierId(char* nom)
{
    for(int i=0;i<idfIndex;i++)
    {
        if(strcmp(nom,TAB_IDFS[i].NOM) == 0)
            return TAB_IDFS[i].TIDF;
    }
    erreur(NON_DEC);
}