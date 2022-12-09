#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy {

protected:
    const string NAZWA_PLIKU_TEKSTOWEGO;
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
public:
    PlikTekstowy(string nazwaPliku) : NAZWA_PLIKU_TEKSTOWEGO(nazwaPliku){};
    string pobierzNazwePliku();
    static bool czyPlikJestPusty(fstream &plikTekstowy);

};
#endif
