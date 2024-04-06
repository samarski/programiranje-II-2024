#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using std::vector;

// msr = moje super rutine
namespace msr {

    // opšta varijanta ispisa jednog vektora
    template<typename T>
    void ispisiVektor(vector<T> &v) {
        for (T &x : v) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    // varijanta ispisa vektora koji sadrži pokazivače na vektore
    template<typename T>
    void ispisiVektor(vector<vector<T>*> &v) {
        std::cout << std::string(50, '-') << "\n";
        for (auto &x : v) {
            for (auto &y : *x) {
                std::cout << y << " ";
            }
            std::cout << std::endl;
        }
    }

    // varijanta ispisa vektora koji sadrži vektore...
    template<typename T>
    void ispisiVektor(vector<vector<T>> &v) {
        std::cout << std::string(50, '-') << "\n";
        for (auto &x : v) {
            for (auto &y : x) {
                std::cout << y << " ";
            }
            std::cout << std::endl;
        }
    }

    // funkcija manji poredi dva objekta.
    // opšta varijanta
    template<typename T>
    bool manji(T a, T b) {
        return a < b;
    }

    // funkcija manji poredi dva vektora.
    // varijanta bez pokazivača (ali sa referencom)
    // TODO: probajte izmjeriti vrijeme ako nije stavljena referenca...
    template<typename T>    
    bool manji(vector<T> &a, vector<T> &b) {
        int n = std::min(a.size(), b.size());
        int p = 0;
        while (p < n) {
            if (a[p] < b[p])
                return true;
            else if (a[p] > b[p])
                return false;

            p++;
        }
        return (a.size() < b.size());
    }

    // funkcija manji poredi dva vektora.
    // varijanta sa pokazivačima
    template<typename T>    
    bool manji(vector<T> *a, vector<T> *b) {
        int n = std::min(a->size(), b->size());
        int p = 0;
        while (p < n) {
            if (a[p] < b[p])
                return true;
            else if (a[p] > b[p])
                return false;

            p++;
        }
        return (a->size() < b->size());
    }

    template<typename T>
    void mojsort(vector<T> &v) {
        for (int i = v.size()-1; i > 0; i--) {
            for (int j=0; j < i; j++) {
                // brzina značajno varira zavisno od toga kako je 
                // izvedena funkcija "manji"
                if (manji(v[j+1],v[j])) {
                    // mijenjamo v[j] i v[j+1]
                    // ključni problem brzine je upravo u sljedeća tri reda
                    T t = v[j];
                    v[j] = v[j+1];
                    v[j+1] = t;
                } 
            }
        }
    }
}


// Provjeravamo da li nam radi dobro funkcija ispisa
void test1() {
    std::cout << std::string(50,'*') << "\n";
    std::cout << "Test 1\n";

    vector<double> v{6.0,2.0,4.0,8.0,6.0,1.0,3.1};
    msr::ispisiVektor(v);
}

// Provjeravamo da li nam radi dobro funkcija sorta
void test1B() {
    std::cout << std::string(50,'*') << "\n";
    std::cout << "Test 1B\n";

    vector<double> v{6.0,2.0,4.0,8.0,6.0,1.0,3.1};
    msr::mojsort(v);
    msr::ispisiVektor(v);
}


// Sortiranje vektora koji sadrži vektore integera
void test2() {
    std::cout << std::string(50,'*') << "\n";
    std::cout << "Test 2\n";

    vector<vector<int>> v{
        vector<int>{1,2,3},
        vector<int>{2,3},
        vector<int>{1},
        vector<int>{8},
        vector<int>{5,5,5,5}};

    msr::ispisiVektor(v);
    msr::mojsort(v);
    msr::ispisiVektor(v);
}


// Sortiranje vektora pokazivača na vektore
void test3() {
    std::cout << std::string(50,'*') << "\n";
    std::cout << "Test 3\n";

    vector<vector<int>*> v{
        new vector<int>{1,2,3},
        new vector<int>{2,3},
        new vector<int>{1},
        new vector<int>{8},
        new vector<int>{5,5,5,5}};

    msr::ispisiVektor(v);
    msr::mojsort(v);
    msr::ispisiVektor(v);
}


constexpr int brojElemenata = 5'000;
constexpr int brojElemUJednomVektoru = 1'000;


// funkcija koja puni proslijeđeni vektor sa vektorima...
// ... a svaki od vektora ima slučajno generisanu vrijednost
void inicijalizujVektorSaVektorima(vector<vector<int>> &v) {
    // inicijalizujemo generator slučajnih brojeva sa tekućim vremenom
    std::srand(std::time(nullptr));

    for (int i = 0; i < brojElemenata; i++) {
        auto pomocni = vector<int>();
        // uvijek je dobro rezervisati ako znamo da ćemo imati puno dodavanja...
        // Pogledati dodatno inicijalizujVektorSaPokazivacima
        pomocni.reserve(brojElemUJednomVektoru);
        for (int j = 0; j < brojElemUJednomVektoru; j++) {
            pomocni.push_back(std::rand());
        }
        v.push_back(pomocni);
    }
}


// test4 testira brzinu izvršavanja sortiranja vektora koji je napunjen vektorima
// brzina može značajno varirati zavisno od toga kako je napunjen vektor (zašto?)
void test4() {
    std::cout << std::string(50,'*') << "\n";
    std::cout << "Test 4\n";

    using namespace std::chrono;

    vector<vector<int>> v;
    inicijalizujVektorSaVektorima(v);

    auto pocetak = high_resolution_clock::now();
    msr::mojsort(v);
    auto kraj = high_resolution_clock::now();

    auto trajanje = duration_cast<milliseconds>(kraj - pocetak);
    auto brojMilisekundi = trajanje.count();
    std::cout << "Trajanje izvršavanja (bez pokazivača) u ms: " << brojMilisekundi << std::endl;
}


// nekada je lakše raditi sa vlastitim tipovima...
using mojTip = vector<int>*;


// funkcija koja puni proslijeđeni vektor sa pokazivačima na vektore...
void inicijalizujVektorSaPokazivacima(vector<mojTip> &v) {
    // sada radimo na preporučeni način generisanja slučajnih brojeva
    // pogledati: https://en.cppreference.com/w/cpp/numeric/random

    std::random_device dev;
    std::mt19937 rng(dev());
    // brojeve koje generišemo želimo da imamo u opsegu 0-999999
    std::uniform_int_distribution<int> dist(0,999'999);

    for (int i = 0; i < brojElemenata; i++) {
        // možemo dinamički alocirati vektor koji u startu ima potreban broj elemenata
        mojTip pomocni = new vector<int>(brojElemUJednomVektoru);
        for (int j = 0; j < brojElemUJednomVektoru; j++) {
            (*pomocni)[j] = dist(rng);
        }
        v.push_back(pomocni);
    }
}


// test5 testira brzinu izvršavanja sortiranja vektora koji je napunjen
// pokazivačima na vektore. U ovom slučaju je vrijeme izvršavanja konzistentno
// i nema puno varijacija (zašto?)
void test5() {
    std::cout << std::string(50,'*') << "\n";
    std::cout << "Test 5\n";

    using namespace std::chrono;

    vector<mojTip> v;
    inicijalizujVektorSaPokazivacima(v);

    auto pocetak = high_resolution_clock::now();
    msr::mojsort(v);
    auto kraj = high_resolution_clock::now();

    auto trajanje = duration_cast<milliseconds>(kraj - pocetak);
    auto brojMilisekundi = trajanje.count();
    std::cout << "Trajanje izvršavanja (sa pokazivačima) u ms: " << brojMilisekundi << std::endl;
}


int main() {
    test1();
    test1B();
    test2();
    test3();
    test4();
    test5();

    return 0;
}