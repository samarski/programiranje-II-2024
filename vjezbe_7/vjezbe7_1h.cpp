#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <list>

using std::vector;
using std::string;
using std::list;

using tipSortFunkcije = bool (*)(string*, string *);

void podijeli(vector<string*> &v, bool (*mojaFunc)(string*), 
    list<string*> &zadovoljava, 
    list<string*> &neZadovoljava,
    vector<string*> &rijeci,
    tipSortFunkcije sortFja) {

    for (auto s : v) {
        if (std::find_if(rijeci.begin(), rijeci.end(), 
                    [s](string *f){ return *f == *s; } ) == rijeci.end()) {

            auto kopija = new string(*s);
            if (mojaFunc(s)) {
                for (auto )
                zadovoljava.push_back(kopija);
            }
            else {
                neZadovoljava.push_back(kopija);
            }
        }
    }

    // std::sort(zadovoljava.begin(), zadovoljava.end(), sortFja);
    // std::sort(neZadovoljava.begin(), neZadovoljava.end(), sortFja);
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

    list<string*> z{};
    list<string*> nz{};
    
    auto pokazivacNaC = unos[3];

    podijeli(unos, 
        [](string* s){ return (*s)[0]=='A'; }, 
        z, nz, 
        vector<string*>{new string("CCC")},
        [](string* a, string* b){ 
            int duzina = std::min(a->size(), b->size());
            for (int p = 0; p < duzina; p++) {
                if (toupper((*a)[p]) < toupper((*b)[p]))
                    return false;
                else if (toupper((*a)[p]) > toupper((*b)[p]))
                    return true;
            }

            return a->size() > b->size(); });

    // podijeli(unos, [](string* s){ return (*s)[0]=='A'; }, z, nz, vector<string*>{ pokazivacNaC });

    ispisiVektor(unos);
    ispisiVektor(z);
    ispisiVektor(nz);

    for (auto s : z) {
        delete s;
    }

    for (auto s : nz) {
        delete s;
    }

    return 0;
}