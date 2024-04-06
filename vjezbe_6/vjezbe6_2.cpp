#include <iostream>

// razmisliti kako bi se mogla uraditi rotiranje bez
// dinamičke alokacije... i nije tako komplikovano...
void Rotiraj(int** matrica, int n) {
    int** rotiranaMatrica = new int*[n];
    for (int i = 0; i < n; i++) {
        rotiranaMatrica[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            // i-ta kolona ide u j-tu kolone kopirane matrice
            // a j-ta kolona ide u i-tu kolonu, ali obrnutim redoslijedom
            // (n-1)-i element ide u 0-ti element, itd...
            rotiranaMatrica[n-j-1][i] = matrica[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrica[i][j] = rotiranaMatrica[i][j];

    // na kraju oslobađamo memoriju
    for (int i = 0; i < n; i++)
        delete[] rotiranaMatrica[i];
    delete[] rotiranaMatrica;
}

void ispisiMatricu(int** matrica, const int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << matrica[i][j] << " ";
        std::cout << "\n";
    }
    std::cout.flush();
}

void test1() {
    std::cout << "Varijanta I\n";

    constexpr int n = 3;
    int** matrica;
    matrica = new int*[n];
    for (int i = 0; i < 3; i++)
        matrica[i] = new int[3];
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            matrica[i][j] = 10*(i+1) + (j+1);

    Rotiraj(matrica, 3);
    ispisiMatricu(matrica, 3);

    for (int i = 0; i < n; i++)
        delete[] matrica[i];
    delete[] matrica;

    std::cout << std::string(50, '-') << std::endl;
}

void test2() {
    std::cout << "Varijanta II\n";

    int prviRed[3]{11, 12, 13};
    int drugiRed[3]{21, 22, 23};
    int treciRed[3]{31, 32, 33};
    int* matrica[3]{prviRed, drugiRed, treciRed};

    Rotiraj(matrica, 3);
    ispisiMatricu(matrica, 3);

    std::cout << std::string(50, '-') << std::endl;
}

int main() {
    
    test1();

    test2();
}

