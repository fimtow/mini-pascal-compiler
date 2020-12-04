typedef enum
{
    TPROG,
    TCONST,
    TVAR
} TSYM;

typedef struct T_TAB_IDF
{
    char NOM[20];
    TSYM TIDF;
} T_TAB_IDF;


void testSymbole (codesLex cl, codesErr err);
void premierSym();
void program();
void block();
void consts();
void vars();
void insts();
void inst();
void affec();
void si();
void tantque();
void ecrire();
void lire();
void cond();
void expr();
void term();
void fact();
void ajouterId(char* id,TSYM type);
TSYM verifierId(char* id);