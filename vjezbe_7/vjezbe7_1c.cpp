#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
using std::vector;
using std::string;
using std::array;

void podijeli(vector<string*> &v, bool (*mojaFunc)(string*), 
    vector<string*> &zadovoljava, 
    vector<string*> &neZadovoljava,
    vector<string*> &rijeci) {

    for (auto s : v) {
        if (std::find_if(rijeci.begin(), rijeci.end(), 
                    [s](string *f){ return *f == *s; } ) == rijeci.end()) {

            if (mojaFunc(s))
                zadovoljava.push_back(s);
            else
                neZadovoljava.push_back(s);
        }
    }

    std::sort(zadovoljava.begin(), zadovoljava.end());
    std::sort(neZadovoljava.begin(), neZadovoljava.end());
}


bool filterFunc(string* s) {
    return (*s)[0] == 'A';
}

void ispisiVektor(vector<string*> &v) {
    for (auto &s: v) {
        std::cout << *s << "\n";
    }
    std::cout << std::endl;
}


int main() {

    auto unos = vector<string*>(5);
    unos[0] = new string("Aleksandar");
    unos[1] = new string("Test");
    unos[2] = new string("Proba");
    unos[3] = new string("CCC");
    unos[4] = new string("TTT");

    vector<string*> z{};
    vector<string*> nz{};
    
    auto pokazivacNaC = unos[3];

    podijeli(unos, [](string* s){ return (*s)[0]=='A'; }, z, nz, vector<string*>{new string("CCC")});
    // podijeli(unos, [](string* s){ return (*s)[0]=='A'; }, z, nz, vector<string*>{ pokazivacNaC });

    ispisiVektor(unos);
    ispisiVektor(z);
    ispisiVektor(nz);

    return 0;
}