#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using std::vector;
using std::string;


int brojStudenataNaPredmetu(
    const vector< vector<string> > &p_studenata,
    const string &naziv_predmeta) {

    int broj_studenata(0);

    for (int i = 0; i < p_studenata.size(); i++) {
        for (int j = 0; j < p_studenata[i].size(); j++) {
            if (p_studenata[i][j] == naziv_predmeta) {
                broj_studenata++;
                break; 
            }
        }
    }

    return broj_studenata;
}

void ispisiStudenteNaPredmetu(
    const vector<string> &imena_studenata,
    const vector<vector<string>> &predmeti_studenata,
    const string predmet) {

    std::cout << "Lista studenata koji slušaju predmet " << predmet << "\n";

    for (int i = 0; i < imena_studenata.size(); i++) {
        for (int j = 0; j < predmeti_studenata[i].size(); j++) {
            if (predmeti_studenata[i][j] == predmet) {
                std::cout << imena_studenata[i] << "\n";
            }
        }
    }

    std::cout << std::endl;
}


void unesiImenaStudenata(
    vector<string> &imena_studenata) {

    int broj_studenata(0);

    while (true) {
        std::cout << "Unesi studenta br. " << ++broj_studenata << ": ";
        string ime_studenta;

        std::getline(std::cin, ime_studenta);
        if (ime_studenta == "KRAJ")
            break;

        imena_studenata.push_back(ime_studenta);

        /*
        // da ne koristimo stringove, mogli smo ovako... (C)

        char ime_studenta[100];
        std::cin.getline(ime_studenta, 100);

        if (strcmp(ime_studenta, "KRAJ") == 0)
            break;

        imena_studenata.push_back(ime_studenta);
        */
    }

}


void dodajPredmet(
    const vector<string> &imena_studenata,
    vector<vector<string>> &predmeti_studenata,
    const string &student, 
    const string &predmet) {

    // ako je p == -1, onda nismo našli studenta
    // u suprotnom, p pokazuje na poziciju u nizu imena_studenata
    int p = -1;

    for (int i = 0; i < imena_studenata.size(); i++) {
        if (imena_studenata[i] == student) {
            p = i;
            break;
        }
    }

    // fragment niže smo mogli ubaciti i pod if na liniji 85
    // (ispod if (imena_studenata[i] == student))
    if (p != -1) {
        // ...a dio koda pod ovim if-om smo mogli staviti i u 
        // posebnu funkciju
        bool nasao_predmet = false;
        for (int j = 0; j < predmeti_studenata[p].size(); j++) {
            if (predmeti_studenata[p][j] == predmet) {
                nasao_predmet = true;
                break;
            }
        }

        // predmet dodajemo samo ako on već ne postoji
        // za datog studenta
        if (!nasao_predmet)
            predmeti_studenata[p].push_back(predmet);
    } else {
        // prijava greške? nisam našao studenta
    }
} 


void ispisiImenaStudenata(
    const vector<string> &imena_studenata) {

    /*
    for (int i = 0; i < imena_studenata.size(); i++) {
        std::cout << imena_studenata[i] << "\n";
    }
    */

    for (auto it = imena_studenata.begin(); it < imena_studenata.end(); it++) {
        std::cout << *it << "\n";
    }
}


void unesiPredmeteZaStudente(
    vector<string> &imena_studenata,
    vector<vector<string>> &predmeti_studenata) {

    for (auto it = imena_studenata.begin(); it < imena_studenata.end(); it++) {
        std::cout 
            << "Unesi predmete za studenta " 
            << *it 
            << "\n";

        auto predmeti_jednog_studenta = vector<string>();

        while (true) {
            string predmet;
            std::getline(std::cin, predmet);
            if (predmet == "KRAJ") {
                break;
            }
            predmeti_jednog_studenta.push_back(predmet);
        }

        // ispod bi trebalo da stoji zapravo
        // ...push_back(std::move(...)) ali o tome kasnije...
        predmeti_studenata.push_back(predmeti_jednog_studenta);
    }
}


void ispisiPredmeteZaStudente(
    const vector<string> &imena_studenata,
    const vector<vector<string>> &predmeti_studenata) {

    for (int i = 0; i < imena_studenata.size(); i++) {
        std::cout << imena_studenata[i] << "\n";
        for (int j = 0; j < predmeti_studenata[i].size(); j++) {
            std::cout << "  " << predmeti_studenata[i][j] << "\n";
        }
    }
}


int main() {

    vector<string> imena_studenata;
    vector<vector<string>> predmeti_studenata;

    // ili deklaraciju smo mogli staviti i ovako:
    // auto imena_studenata = vector<string>();
    // auto predmeti_studenata = vector<vector<string>>();
    // ...
    // a ako znamo unaprijed dimenziju vektora
    // auto imena_studenata = vector<string>(10);
    // ...
    // za vježbu uraditi transkripciju zadatka 3-1 na vektore..
    // više o vektorima:
    //    https://en.cppreference.com/w/cpp/container/vector

    unesiImenaStudenata(imena_studenata);

    // ispisiImenaStudenata(imena_studenata);

    unesiPredmeteZaStudente(imena_studenata, predmeti_studenata);

    ispisiPredmeteZaStudente(imena_studenata, predmeti_studenata);

    std::cout 
        << "Broj studenata na predmetu Programiranje II: " 
        << brojStudenataNaPredmetu(predmeti_studenata, "Programiranje II") 
        << std::endl;

    ispisiStudenteNaPredmetu(imena_studenata, predmeti_studenata, "Programiranje II");

    dodajPredmet(imena_studenata, predmeti_studenata, 
        "Test student", "Programiranje II");

    ispisiPredmeteZaStudente(imena_studenata, predmeti_studenata);

    return 0;
}