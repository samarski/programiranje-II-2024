#include <iostream>

// varijanta sa referencom na pokazivač
template<typename T>
void SmjestiMinIMax(T* const pocetak, T* const izaKraja, 
    T* &pokazivacNaMin, T* &pokazivacNaMax) {

    if (pocetak >= izaKraja)
        throw std::invalid_argument("početak je veći ili jednak izaKraja");

    // inicijalno, Min i Max su prvi element niza
    pokazivacNaMin = pokazivacNaMax = pocetak;

    // idemo od drugog elementa
    for (T* p = pocetak+1; p < izaKraja; p++) {
        if (*p < *pokazivacNaMin)
            pokazivacNaMin = p;
        else if (*p > *pokazivacNaMax)
            pokazivacNaMax = p;
    }
}


// varijanta sa pokazivačem na pokazivač
template<typename T>
void SmjestiMinIMaxPokazivac(T* const pocetak, T* const izaKraja, 
    T** pokazivacNaMin, T** pokazivacNaMax) {

    if (pocetak >= izaKraja)
        throw std::invalid_argument("početak je veći ili jednak izaKraja");

    // inicijalno, Min i Max su prvi element niza
    *pokazivacNaMin = *pokazivacNaMax = pocetak;

    // idemo od drugog elementa
    for (T* p = pocetak+1; p < izaKraja; p++) {
        if (*p < **pokazivacNaMin)
            *pokazivacNaMin = p;
        else if (*p > **pokazivacNaMax)
            *pokazivacNaMax = p;
    }
}


int main() {
    int niz[]{6,2,4,8,6,1,3};

    int* pMin = nullptr;
    int* pMax = nullptr;

    // &niz[0] ili niz...
    // &niz[7] ili niz+7
    SmjestiMinIMax(&niz[0], &niz[7], pMin, pMax);

    std::cout << "Minimalni element je " << *pMin << "\n";
    std::cout << "Maksimalni element je " << *pMax << "\n";
    std::cout << std::string(50, '*') << "\n";

    // ili varijanta sa pokazivačem na pokazivač
    SmjestiMinIMaxPokazivac(&niz[0], &niz[7], &pMin, &pMax);
    std::cout << "Minimalni element je " << *pMin << "\n";
    std::cout << "Maksimalni element je " << *pMax << "\n";

    std::cout << std::endl;
}