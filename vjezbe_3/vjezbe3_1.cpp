#include <iostream>
#include <iomanip>

int broj_predmeta;
int broj_studenata;

const int max_broj_predmeta = 10;
const int max_broj_studenata = 100;
const int max_duzina_naziva_predmeta = 50;
const int max_duzina_imena_studenta = 50;

char naziv_predmeta[max_broj_predmeta][max_duzina_naziva_predmeta];
char ime_i_prezime_studenta[max_broj_studenata][max_duzina_imena_studenta];
int ocjena_studenta[max_broj_studenata][max_broj_predmeta];

void unesi_predmete_i_studente() {
    // std::cout << sizeof(ocjena_studenta) << "\n";
    // return;

    std::cout << "Unesite broj predmeta: ";
    std::cin >> broj_predmeta;

    std::cout << "Unesite broj studenata: ";
    std::cin >> broj_studenata;
    std::cin.ignore(10000, '\n');

    for (int i = 0; i < broj_predmeta; i++) {
        std::cout << "Unesite predmet " << (i+1) << ": ";
        std::cin.getline(naziv_predmeta[i], max_duzina_naziva_predmeta);
    }

    for (int i = 0; i < broj_studenata; i++) {
        std::cout << "Unesite studenta " << (i+1) << ": ";
        std::cin.getline(ime_i_prezime_studenta[i], max_duzina_imena_studenta);
        for (int j = 0; j < broj_predmeta; j++) {
            std::cout << "  unesite ocjenu za predmet " << naziv_predmeta[j] << ": ";
            std::cin >> ocjena_studenta[i][j];
        }
        std::cin.ignore(10000, '\n');
    }
}

double vrati_prosjecnu_ocjenu_studenta(int student) {
    int suma_ocjena = 0;
    for (int i = 0; i < broj_predmeta; i++)
        suma_ocjena += ocjena_studenta[student][i];

    return ((double)suma_ocjena)/broj_predmeta;
}


double vrati_prosjecnu_ocjenu_predmeta(int predmet) {
    int suma_ocjena = 0;
    for (int i = 0; i < broj_studenata; i++)
        suma_ocjena += ocjena_studenta[i][predmet];

    return ((double)suma_ocjena)/broj_studenata;
}


void ispisi_prosjecnu_ocjenu_studenata() {
    std::cout << "Prosječne ocjene predmeta\n";

    // za formatiranje izlaza pogledati
    // https://en.cppreference.com/w/cpp/io/manip

    for (int i = 0; i < broj_studenata; i++) {
        // redni broj
        std::cout 
            << (i+1) 
            << ". ";

        // ime i prezime studenta, poravnato ulijevo
        std::cout 
            << std::setw(max_duzina_imena_studenta) 
            << std::left 
            << ime_i_prezime_studenta[i];

        std::cout
            << " ";

        // prosječna ocjena, prikazana na dvije decimale
        std::cout  
            << std::setw(6) 
            << std::fixed 
            << std::setprecision(2) 
            << vrati_prosjecnu_ocjenu_studenta(i);

        std::cout
            << "\n";
    }

    std::cout << std::endl;
}


void ispisi_procjecnu_ocjenu_predmeta() {
    std::cout << "Prosječne ocjene studanata\n";

    for (int i = 0; i < broj_predmeta; i++) {
        std::cout 
            << (i+1) << ". ";

        std::cout 
            << std::setw(max_duzina_naziva_predmeta)  
            << std::left 
            << naziv_predmeta[i];
            
        std::cout
            << " ";

        std::cout 
            << std::setw(6) 
            << std::fixed 
            << std::setprecision(2)
            << vrati_prosjecnu_ocjenu_predmeta(i);
        
        std::cout
            << "\n";
    }

    std::cout << std::endl;
}


int main() {

    unesi_predmete_i_studente();

    ispisi_prosjecnu_ocjenu_studenata();

    ispisi_procjecnu_ocjenu_predmeta();

    return 0;
}