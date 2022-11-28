#include "Adresat.h"

void Adresat::ustawIdAdresata(int noweIdAdresata){
    if (noweIdAdresata >= 0)
        idAdresata = noweIdAdresata;
}
void Adresat::ustawIdUzytkownikaDoKtoregoNalezyAdresat(int idZalogowanegoUzytkownika){
    idUzytkownikaDoKtoregoNalezyAdresat = idZalogowanegoUzytkownika;
}
void Adresat::ustawImie(string noweImie){
    imie = noweImie;
}
void Adresat::ustawNazwisko(string noweNazwisko){
    nazwisko = noweNazwisko;
}
void Adresat::ustawNumerTelefonu(string nowyNumerTelefonu){
    numerTelefonu = nowyNumerTelefonu;
}
void Adresat::ustawEmail (string nowyEmail){
    email = nowyEmail;
}
void Adresat::ustawAdres (string nowyAdres){
    adres = nowyAdres;
}

int Adresat::pobierzIdAdresata(){
    return idAdresata;
}
int Adresat::pobierzIdUzytkownikaDoKtoregoNalezyAdresat(){
    return idUzytkownikaDoKtoregoNalezyAdresat;
}
string Adresat::pobierzImie(){
    return imie;
}
string Adresat::pobierzNazwisko(){
    return nazwisko;
}
string Adresat::pobierzNumerTelefonu(){
    return numerTelefonu;
}
string Adresat::pobierzEmail(){
    return email;
}
string Adresat::pobierzAdres(){
    return adres;
}
