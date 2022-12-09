#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenadzer;
    adresatMenadzer = NULL;
}

void KsiazkaAdresowa::dodajAdresata(){
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer->dodajAdresata();
    }
    else{
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer->wyswietlWszystkichAdresatow();
    }
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany(){
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        return true;
    }
    else{
        return false;
    }
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu(){
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer->wyszukajAdresatowPoImieniu();
    }
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku(){
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer->wyszukajAdresatowPoNazwisku();
    }
}

void KsiazkaAdresowa::edytujAdresata(){
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer->edytujAdresata();
    }
}

void KsiazkaAdresowa::usunAdresata(){
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        adresatMenadzer->usunAdresata();
    }
}
