#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat{
    int idAdresata;
    int idUzytkownikaDoKtoregoNalezyAdresat;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;

public:
    void ustawIdAdresata(int noweIdAdresata);
    void ustawIdUzytkownikaDoKtoregoNalezyAdresat(int idZalogowanegoUzytkownika);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNumerTelefonu (string nowyNumerTelefonu);
    void ustawEmail (string nowyEmail);
    void ustawAdres (string nowyAdres);

    int pobierzIdAdresata();
    int pobierzIdUzytkownikaDoKtoregoNalezyAdresat();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();

};
#endif
