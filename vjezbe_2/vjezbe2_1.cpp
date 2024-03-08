#include <iostream>
// using namespace std;

void funkcija(int n) {
    int niz[sizeof(n)*8-1];

    int p = 0;
    // int p{0};
    // int p(0);

    while (n != 0) {
        niz[p++] = (n % 2);
        n /= 2;
    }

    /*
    for (int i = p-1; i >= 0; i--)
        std::cout << niz[i];
    */
    while (p > 0) 
        std::cout << niz[--p];
}


int main() {

    int n;
    std::cout << "Unesite broj n: ";
    std::cin >> n;
    std::cout << "Zapis broja " << n 
                << " u binarnom obliku je ";

    funkcija(n);

    std::cout << std::endl;

    return 0;
}