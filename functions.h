extern char carCour;
extern tSymCour symCour;
typedef enum
{
    ID_TOKEN,
    PROGRAM_TOKEN,
    PLUS_TOKEN,
    ERREUR_TOKEN,
} codesLex;
typedef struct tSymCour
{
    codesLex code;
    char nom[20];
} tSymCour;

void ouvrirFichier(char* file);
void lireCaractere();
void symSuiv();
void afficherToken(tSymCour symcour);
void lireNombre();
void lireMot();
void lireCar();
void erreur();
