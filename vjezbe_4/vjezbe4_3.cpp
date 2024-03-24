#include <iostream>
#include <vector>
using std::vector;

// TODO: za vježbu, prebaciti na template funkciju
int brojTrocifrenihBrojeva(int *p1, const int *p2) {
    int rezultat{0};

    // TODO: Pitanje - šta je vrijednost izraza: p2 - p1

    while (p1 < p2) {
        int v = abs(*p1);
        if ((v >= 100) && (v <= 999))
            rezultat++;

        p1++;
    }

    return rezultat;
}


int main() {
    int niz[] = {-123, 45, 380, 1, 2, 1060,
                 22, 881};

    std::cout << brojTrocifrenihBrojeva(&niz[2], &niz[6])
        << std::endl;

    std::cout << brojTrocifrenihBrojeva(niz, niz+55)
              << std::endl;

    vector<int> v{123, 234, 1000, 1, 300};
    std::cout << brojTrocifrenihBrojeva(&v[0], &v[5])
              << std::endl;

    std::cout << brojTrocifrenihBrojeva(&v[0], &v[v.size()+1])
              << std::endl;

    // N.B: std::vector ima funkcije front() i back():
    //    https://en.cppreference.com/w/cpp/container/vector/front
    //    https://en.cppreference.com/w/cpp/container/vector/back
    // ali ponašanje front() i back() je nedefinisano ako se
    // radi o "praznom" vektoru.
    std::cout << brojTrocifrenihBrojeva(&v.front(), &v.back()+1)
              << std::endl;

    return 0;
}
