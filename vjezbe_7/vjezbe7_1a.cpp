#include <iostream>
#include <vector>
#include <string>
#include <array>
using std::vector;
using std::string;
using std::array;

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

    std::cout << "Unesite broj stringova: ";
    int n(0);
    std::cin >> n;
    std::cin.ignore(10000, '\n');

    auto unos = vector<string>(n);

    for (int i = 0; i < n; i++) {
        string s;
        std::cout << "Unesite string broj " << (i+1) << ": ";
        std::cin >> unos[i];
    }

    vector<string> z{};
    vector<string> nz{};
    
    podijeli(unos, [](string &s){ return s[0]=='A'; }, z, nz);

    ispisiVektor(unos);
    ispisiVektor(z);
    ispisiVektor(nz);

    return 0;
}