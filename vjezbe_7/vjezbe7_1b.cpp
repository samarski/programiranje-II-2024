#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
using std::vector;
using std::string;
using std::array;

void podijeli(vector<string> &v, bool (*mojaFunc)(string&), 
    vector<string> &zadovoljava, 
    vector<string> &neZadovoljava,
    vector<string> &rijeci) {

    for (auto s : v) {
        if (std::find(rijeci.begin(), rijeci.end(), s) == rijeci.end())
            if (mojaFunc(s))
                zadovoljava.push_back(s);
            else
                neZadovoljava.push_back(s);
    }

    std::sort(zadovoljava.begin(), zadovoljava.end());
    std::sort(neZadovoljava.begin(), neZadovoljava.end());
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

    auto unos = vector<string>(5);
    unos[0] = "Aleksandar";
    unos[1] = "Test";
    unos[2] = "Proba";
    unos[3] = "CCC";
    unos[4] = "TTT";

    vector<string> z{};
    vector<string> nz{};
    
    podijeli(unos, [](string &s){ return s[0]=='A'; }, z, nz, vector<string>{"CCC"});

    ispisiVektor(unos);
    ispisiVektor(z);
    ispisiVektor(nz);

    return 0;
}