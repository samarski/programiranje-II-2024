#include <iostream>
#include <cmath>

double vratiVrijednostIzraza(double niz[], int n) {
    double S{0.0};

    try {
        if (n == 0)
            throw std::string("Dužina niza je 0");

        for (int i = n - 1; i >= 0; i--) {
            double izraz = niz[i] + S;
            if (izraz < 0.0)
                throw std::invalid_argument("Negativna podkorijena vrijednost");
            // throw std::string("pojavila se negativna vrijednost");

            S = sqrt(izraz);
        }
    }
    catch (double greska) {
        // ako se pojavio ovaj exception onda zaista ne mogu ništa uraditi
        throw;
    }
    catch (std::string opisnaGreska) {
        // šta da se radi, ipak je to ok
    }

    return S;
}

int main() {
    double niz[] = {1.0, 2.0, -3.0};

    // https://en.cppreference.com/w/cpp/error/exception
    try {
        std::cout << vratiVrijednostIzraza(niz, 3)
                  << std::endl;
    }
    catch (std::invalid_argument ia) {
        std::cout << "Invalid argument: " << ia.what() << std::endl;
    }
    catch (std::string greska) {
        std::cout << "std::string:" << greska << std::endl;
    }
    catch (int greska) {
        std::cout << "Brojna int greska " << greska << std::endl;
    }
    catch (double greska) {
        std::cout << "Brojna double greška " << greska << std::endl;
    }
    // Obratiti pažnju na prenos po referenci &e. Šta bi značilo ako bi stajalo samo e?
    catch (std::exception &e) {
        std::cout << "Uhvatio!!!\n";
        std::cout << e.what() << "\n";
        // if (....)
            throw;
    }
    catch (...) {
        std::cout << "Ovo je sad zaista nešto novo!!!\n";
    }

    return 0;
}
