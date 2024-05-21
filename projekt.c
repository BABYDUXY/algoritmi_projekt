#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

// Struktura podataka
typedef struct
{
    char ime[50];
    char liga[50];
    char stadion[50];
    int kapacitet;
    int godina_osnivanja;
    int broj_naslova;
} Nogometni_klub;

typedef struct Celija
{
    Nogometni_klub element;
    struct Celija *psljedeca;
} CelijaNogometniKlub;

// Funkcije

CelijaNogometniKlub *pronadjiZadnju(CelijaNogometniKlub *ppolaznaCelija)
{
    CelijaNogometniKlub *pzadnjaCelija = ppolaznaCelija;

    while (pzadnjaCelija->psljedeca != NULL)
    {
        pzadnjaCelija = pzadnjaCelija->psljedeca;
    }

    return pzadnjaCelija;
}
// Unos kluba
void unosKlub(Nogometni_klub *pNogometni_klub)
{
    printf("\n Unesite ime kluba: ");
    scanf_s("%50s", &pNogometni_klub->ime, 50);

    printf("\n Unesite ligu kluba: ");
    scanf_s("%50s", &pNogometni_klub->liga, 50);

    printf("\n Unesite stadion kluba: ");
    scanf_s("%50s", &pNogometni_klub->stadion, 50);

    printf("\n Unesite kapacitet stadiona kluba: ");
    scanf_s("%d", &pNogometni_klub->kapacitet);

    printf("\n Unesite godinu osnivanja kluba: ");
    scanf_s("%d", &pNogometni_klub->godina_osnivanja);

    printf("\n Unesite broj osvojenih naslova kluba: ");
    scanf_s("%d", &pNogometni_klub->broj_naslova);
}

// Ispis kluba
void ispisKlub(CelijaNogometniKlub *ppolaznaCelija)
{
    CelijaNogometniKlub *ptrenutnaCelija = ppolaznaCelija;
    int brojac = 0;

    printf("\n\n Trenutni klub (adresa kluba: %p)", ptrenutnaCelija);
    printf("\n\t element: -");
    printf("\n\t psljedeca %p", ptrenutnaCelija->psljedeca);

    while (ptrenutnaCelija->psljedeca != NULL)
    {
        ptrenutnaCelija = ptrenutnaCelija->psljedeca;
        brojac++;

        printf("\n Ime kluba: %s", ptrenutnaCelija->element.ime);

        printf("\n Liga: %s", ptrenutnaCelija->element.liga);

        printf("\n Stadion: %s", ptrenutnaCelija->element.stadion);

        printf("\n Kapacitete stadiona: %d", ptrenutnaCelija->element.kapacitet);

        printf("\n Godina osnivanja kluba: %d", ptrenutnaCelija->element.godina_osnivanja);

        printf("\n Broj naslova: %d", ptrenutnaCelija->element.broj_naslova);
    }
}

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

// Izmjena elementa
void izmjena(Nogometni_klub izmijenjeniElement, CelijaNogometniKlub *pcelijaZaIzmjenu)
{
    pcelijaZaIzmjenu->element = izmijenjeniElement;
}

// Brisanje elementa
void Brisanje()
{
}

int main()
{
    int odabir;
    Nogometni_klub nogometni_klub;
    CelijaNogometniKlub *ppolaznaCelija;

    ppolaznaCelija = (CelijaNogometniKlub *)malloc(sizeof(CelijaNogometniKlub));
    ppolaznaCelija->psljedeca = NULL;

    CelijaNogometniKlub *pzadnjaCelija;

    do
    {
        menu();
        scanf_s("%d", &odabir);
        switch (odabir)
        {
        case 1:
            unosKlub(&nogometni_klub);
            break;

        case 2:
            ispisKlub(&nogometni_klub);
            break;

        case 3:

        case 4:
            printf("dasda");
            break;
        case 5:
            break;
        }
    } while (odabir < 6);

    return 0;
}
