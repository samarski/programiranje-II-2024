#include <iostream>
#include <algorithm>

template<typename Tip>
Tip* vratiSortiran(Tip* niz, int brojElemenata) {
    Tip* rezultat = new Tip[brojElemenata];
    for (int i = 0; i < brojElemenata; i++)
        rezultat[i] = niz[i];

    std::sort(rezultat, rezultat+brojElemenata);

    return rezultat;
}

template<typename Tip>
void ispisiNiz(Tip* niz, int brojElemenata) {
    // možemo i ovako ispisati niz, umjesto dijela niže...
    while (brojElemenata--)
        std::cout << *niz++ << " ";

    /*
    for (int i = 0; i < brojElemenata; i++)
        std::cout << *niz << " ";
    */
    std::cout << std::endl;
}

int main() {
    int niz[]{10, 20, 15, -5, 35, 1, 12};

    int* sortiraniNiz = vratiSortiran(&niz[0], 7);

    ispisiNiz(sortiraniNiz, 7);

    // na kraju trebamo obrisati vraćeni niz!!!
    // vraćeni niz je alociran sa new[], a svaki new[] mora imati 
    // odgovarajući delete[]...
    delete[] sortiraniNiz;

    return 0;
}