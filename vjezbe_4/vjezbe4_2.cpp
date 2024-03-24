#include <iostream>
#include <vector>
using std::vector;


template<typename T>
vector<T> pomnozi(vector<T> &v) {
    vector<T> rezultat;

    vector<T> niz1;
    vector<T> niz2;

    {
        // TODO: Eliminisati posljednje (nepotrebno) množenje koje se dešava za i == v.size() - 1
        T P{1};
        for (int i = 0; i < v.size(); i++) {
            niz1.push_back(P);
            P *= v[i];
        }
    }

    {
        T P{1};
        for (int i = v.size() - 1; i >= 0; i--) {
            niz2.push_back(P);
            P *= v[i];
        }
    }

    for (int i = 0; i < v.size(); i++) {
        rezultat.push_back(niz1[i] * niz2[v.size() - i - 1]);
    }

    /*
        // Alternativno, gornji fragment smo mogli napisati i ovako:
        // da ne računamo svaki put u petlji izraz v.size() - i - 1, uvodimo varijablu j.
        // Kako i ide od 0 naviše, tako j ide od v.size() naniže.
        // Obratiti pažnju na prefix ++ i postfix --.

        int i(0), j(v.size());
        while (j != 0) {
            rezultat.push_back(niz1[i++] * niz2[--j]);
        }
    */

    return rezultat;
}


template<typename T>
void ispisiVektor(vector<T> v) {
    std::cout << std::string(50, '-') << "\n";
    for (T &x : v) {
        std::cout << x << "\n";
    }
    std::cout << std::string(50, '-') << "\n";
}


int main() {
    vector<double> v{2.01, 3.0, 4.0, 5.0};

    // ispisiVektor(v);
    auto r = pomnozi(v);
    ispisiVektor(r);

    vector<int> v1{2, 3, 4, 5};
    ispisiVektor(pomnozi(v1));

    return 0;
}
