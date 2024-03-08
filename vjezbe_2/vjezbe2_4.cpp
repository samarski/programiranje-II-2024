#include <iostream>

int vrati_najvecu_cifru(int a) {
    int r = 0;
    while (a != 0) {
        int cifra = a % 10;
        if (cifra > r)
            r = cifra;
        a /= 10;
    }

    return r;
}

int vrati_najvecu_cifru_u_nizu(int niz[], int n) {
    /* I varijanta.
    int najveca_cifra = 0;
    for (int i = 0; i < n; i++) {
        int t = vrati_najvecu_cifru(niz[i]);
        if (t > najveca_cifra) 
            najveca_cifra = t;
    }
    */

    // II. varijanta
    // Pod uslovom da je n > 0, odnosno da imamo barem jedan element
    int najveca_cifra = vrati_najvecu_cifru(niz[0]);
    // sada i ide od 1, a ne od 0
    for (int i = 1; i < n; i++) {
        int t = vrati_najvecu_cifru(niz[i]);
        if (t > najveca_cifra) 
            najveca_cifra = t;
    }

    return najveca_cifra;
}


int broj_pojavljivanja_cifre(int n, int cifra) {
    int broj_pojavljivanja(0);

    while (n != 0) {
        if (n % 10 == cifra) 
            broj_pojavljivanja++;

        n /= 10;
    }

    return broj_pojavljivanja;
}


int main() {
    int niz[100];
    int p = 0; // p - pozicija

    while (true) {
        std::cout << "Unesite broj " << (p+1) << ": ";
        int broj;
        std::cin >> broj;

        if (broj == 0)
            break;

        niz[p++] = broj;

        // pretpostavka je da se neće unijeti više od 100 brojeva
        // u praksi, donji red ne bi bio pod komentarom
        // if (p > 100) break;
    }

    if (p == 0) {
        std::cout << "Nema unesenih elemenata\n";

        // povratna vrijednost -1 (odnosno != 0) označava da program nije završio na uobičajen način
        return -1;
    }

    std::cout << std::endl;

    int najveca_cifra_u_nizu = vrati_najvecu_cifru_u_nizu(niz, p);

    std::cout << "Najveca cifra u nizu je " << najveca_cifra_u_nizu << "\n";

    // ovaj put radimo malo drugacije - nalazimo poziciju elementa niza
    // koji ima najvise najvecih cifara
    int pozicija_sa_najvise_n_c = -1;
    int najvise_n_c = 0;
    for (int i = 0; i < p; i++) {
        int t = broj_pojavljivanja_cifre(niz[i], najveca_cifra_u_nizu);
        if (t > najvise_n_c) {
            najvise_n_c = t;
            pozicija_sa_najvise_n_c = i;
        }
    }

    std::cout << "Broj sa najviše najvećih cifara je " << niz[pozicija_sa_najvise_n_c] << "\n";
    std::cout << std::endl;

    return 0;
}