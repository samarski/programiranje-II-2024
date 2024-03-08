#include <iostream>

// U zadatku nije navedeno kako treba da se zove funkcija, pa je onda 
// zovemo - funkcija :). Uvijek je dobro staviti adekvatan naziv.

void funkcija(int niz[], int n, int& negativni, int& razliciti) {
    negativni = 0;
    for (int i = 0; i < n; i++) {
        if (niz[i] < 0)
            negativni++; 
    }

    razliciti = 1;
    // N.B. i ide od 1, a ne od nula! Prvi broj od kojeg krećemo je sigurno 
    // različit od prethodnih brojeva (dodjela razliciti = 1).
    // Stoga, brojanje možemo krenuti od drugog elementa niza (i = 1). 
    for (int i = 1; i < n; i++) {
        bool nasao = false;
        for (int j = 0; j < i; j++) {
            if (niz[j] == niz[i]) {
                nasao = true;
                break;
            }
        }

        if (!nasao)
            razliciti++;
    }

    // A mogli smo ići i drugačije - da brojimo koliko ima istih...
    // Da li bi kod bio jednostavniji ili elegantniji? 
}


int main() {
    int moj_niz[] = {10, 20, -30, 20, -1, 1, -1, 2};

    int p_negativni, p_razliciti;

    // broj elemenata niza smo mogli staviti sizeof(moj_niz) / sizeof(int)
    // pri tome treba voditi računa kakav je bazni tip podatka i da li postoji
    // tzv. alignment..., a tada sizeof(moj_niz) / sizeof(tip_podatka) ne mora dati 
    // broj članova niza...
    funkcija(moj_niz, 8, p_negativni, p_razliciti);

    std::cout << "Negativnih ima " << p_negativni
        << ", a različitih ima " << p_razliciti << "\n";
    std::cout << std::endl;

    return 0;
}