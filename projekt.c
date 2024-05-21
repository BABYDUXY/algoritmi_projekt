#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char ime;
    char liga;
    char stadion;
    int kolicina;
} Nogometni_klub;

typedef struct Celija
{
    Nogometni_klub element;
    struct Celija *psljedeca;
} CelijaNogometniKlub;

CelijaNogometniKlub *pronadjiZadnju(CelijaNogometniKlub *ppolaznaCelija);

void menu()
{

    printf("-------------ODABERI OPCIJU-------------\n\n");
    printf("1: Unos");
    printf("\n2: Ispis");
    printf("\n3: Izmjena");
    printf("\n4: Brisanje");
    printf("\n5: Pretrazivanje");
    printf("\n6: IZLAZ\n\n");
};

int main()
{
    int odabir;
    Nogometni_klub nogometni_klub;

    menu();
    scanf_s("%d", &odabir);
    printf("%d", odabir);
    return 0;
}