#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
using std::vector;
using std::array;
using std::string;

// N.B. const i &
unsigned int vratiBrojPojavljivanja(const string &s) {
    bool pojavljivanje[256];
    for (int i = 0; i < 256; i++)
        pojavljivanje[i] = false;

    for (char c : s) 
        pojavljivanje[c & 0xFF] = true;
    
    unsigned int rezultat(0);
    for (int i = 0; i < 256; i++) 
        if (pojavljivanje[i])
            rezultat++;

    return rezultat;
}


// N.B. const i &
bool mojaSortFunkcija(const string &a, const string &b) {
    int razlika = vratiBrojPojavljivanja(a) - vratiBrojPojavljivanja(b);
    if (razlika < 0)
        return true;
    else if (razlika > 0)
        return false;
    
    return a < b;
}

void test() {
    constexpr int brojStringova = 4;

    string *nizStringova = new string[brojStringova];
    nizStringova[0] = string("Programiranje");
    nizStringova[1] = string("je");
    nizStringova[2] = string("zaista");
    nizStringova[3] = string("zabavno");

    // koristimo default sortiranje, a to je onda
    // uobičajeno poređenje stringova
    std::sort(&nizStringova[0], &nizStringova[brojStringova]);

    for (int i = 0; i < brojStringova; i++) {
        std::cout << nizStringova[i] << "\n";
    }
    std::cout << std::endl;
}

void testArray() {
    array<string,6> niz{
        "Test test",
        "Proba",
        "TTT",
        "Def",
        "Abc",
        "Cdefg"
    };

    std::sort(niz.begin(), niz.end(), mojaSortFunkcija);

    for (auto &v : niz) {
        std::cout << v << "\n";
    }
    std::cout << std::endl;
}

void testNiz() {
    string niz2[6]{
        "Test test",
        "Proba",
        "TTT",
        "Def",
        "Abc",
        "Cdefg"
    };

    std::sort(niz2, niz2+6, mojaSortFunkcija);

    for (string* p = niz2; p < niz2+6; p++) {
        std::cout << *p << "\n";
    }
    std::cout << std::endl;
}

int main() {

    test();

    testNiz();

    testArray();

    return 0;
}