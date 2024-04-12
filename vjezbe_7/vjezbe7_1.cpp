#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

void podijeli(vector<string> &v, bool (*mojaFunc)(string&), 
    vector<string> &zadovoljava, 
    vector<string> &neZadovoljava) {

    for (auto s : v) {
        if (mojaFunc(s))
            zadovoljava.push_back(s);
        else
            neZadovoljava.push_back(s);
    }
}


bool filterFunc(string& s) {
    return s[0] == 'A';
}

void ispisiVektor(vector<string> &v) {
    for (auto &s: v) {
        std::cout << s << "\n";
    }
    std::cout << std::endl;
}


int main() {
    vector<string> unos;

    int br(0);
    while (true) {
        string s;
        std::cout << "Unesite string broj " << ++br << ": ";
        std::cin >> s;
        if (s == "KRAJ")
            break;

        unos.push_back(s);
    }

    vector<string> z{};
    vector<string> nz{};
    
    podijeli(unos, [](string &s){ return s[0]=='A'; }, z, nz);

    ispisiVektor(unos);
    ispisiVektor(z);
    ispisiVektor(nz);

    return 0;
}