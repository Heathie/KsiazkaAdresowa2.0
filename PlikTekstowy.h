#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy {
    const string NAZWA_PLIKU_TEKSTOWEGO;
public:
    PlikTekstowy(string nazwaPliku) : NAZWA_PLIKU_TEKSTOWEGO(nazwaPliku){};
    string pobierzNazwePliku();
    static bool czyPlikJestPusty(fstream &plikTekstowy);

};
#endif
