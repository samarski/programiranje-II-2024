#include <iostream>

int vrati_najvecu_cifru(int a) {
    int r = 0;
    while (a != 0) {
        /*
        int cifra = a % 10;
        if (cifra > r)
            r = cifra;
        */
        r = std::max(r, a % 10);
        a /= 10;
    }

    return r;
}

int main() {
    int n;
    std::cout << "Unesite broj n: ";
    std::cin >> n;

    int niz[n];
    for (int i = 0; i < n; i++) {
        std::cout << "Unesite element " << (i+1) << ": ";
        std::cin >> niz[i];
    }

    std::cout << std::endl;
   
    int najveca_cifra_u_nizu = 0;
    for (int i = 0; i < n; i++) {
        int t = vrati_najvecu_cifru(niz[i]);
        if (t > najveca_cifra_u_nizu) 
            najveca_cifra_u_nizu = t;
    }

    std::cout << "Najveca cifra u nizu brojeva je " << najveca_cifra_u_nizu << std::endl;

    for (int i = 0; i < n; i++) {
        if (vrati_najvecu_cifru(niz[i]) == najveca_cifra_u_nizu) {
            std::cout << "Broj sa najvecom cifrom je " << niz[i] << std::endl;
            // ispisujemo samo prvi nađeni broj
            break;            
        }
    }
    

    /* Prethodni fragment smo mogli napisati i ovako    

    // N.B. inicijalizujemo varijablu najveca_cifra_u_nizu tako da sigurno uđemo u prvi if.
    // Naravno, da bismo ušli u prvi if i ako bismo stavili 0.
    int najveca_cifra_u_nizu = -1; 
    int broj_sa_najvecom_cifrom; // ne moramo inicijalizovati, svakako će ući u prvi if;

    for (int i = 0; i < n; i++) {
        // t kao temporary (privremena - pomoćna) varijabla
        int t = vrati_najvecu_cifru(niz[i]);
        if (najveca_cifra_u_nizu < t) {
            najveca_cifra_u_nizu = t;
            broj_sa_najvecom_cifrom = niz[i];
        }
    }

    std::cout << "Najveca cifra je " << najveca_cifra_u_nizu << "\n";
    std::cout << "Broj sa najvecom cifrom u nizu je " << broj_sa_najvecom_cifrom << std::endl;

    */

    std::cout << std::endl;

    return 0;
}