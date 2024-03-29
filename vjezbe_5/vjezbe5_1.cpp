#include <iostream>

template<typename Tip>
void Obrni(Tip* pocetak, Tip* iza_kraja) {
    iza_kraja--;
    while (pocetak < iza_kraja) {
        Tip t = *pocetak;
        *pocetak++ = *iza_kraja;
        *iza_kraja-- = t;
    }
}


template<typename T>
void ispisiNiz(T* pocetak, T* izaKraja) {
    while (pocetak < izaKraja)
        std::cout << *pocetak++ << " ";

    std::cout << std::endl;
}


int main() {
    int niz[]{0,1,2,3,4,5,6,7,8,9};

    Obrni(&niz[2], &niz[7]);
    
    ispisiNiz(&niz[0], &niz[10]);

    return 0;
}