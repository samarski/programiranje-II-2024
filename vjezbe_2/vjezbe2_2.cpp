#include <iostream>

int funkcija(int n) {
    int binarne_cifre[sizeof(n)*8-1];
    int p = 0;

    while (n != 0) {
        binarne_cifre[p++] = (n % 2);
        n /= 2;
    }

    // r sadrži povratnu vrijednost: r(ezultat)
    int r = 0;
    while (p > 0) 
        r = 10*r + binarne_cifre[--p];

    /* moglo je i ovako 
    while (p-- != 0) 
        r = 10*r + binarne_cifre[p];
    */

    return r;
}

int main() {
    int n;

    std::cout << "Unesite broj n: ";
    std::cin >> n;
    std::cout << "Zapis broja " << n 
                << " u binarnom obliku je "
                << funkcija(n);

    std::cout << std::endl;

    return 0;
}