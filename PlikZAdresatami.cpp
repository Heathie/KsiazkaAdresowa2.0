#include "PlikZAdresatami.h"

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO.c_str(), ios::out | ios::app);

    if (plikTekstowy.good()) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

            plikTekstowy << liniaZDanymiAdresata  <<  endl;

        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdAdresata()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownikaDoKtoregoNalezyAdresat()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    vector <Adresat> adresaci;
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }

            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        }
        plikTekstowy.close();
    }

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        system("pause");
    }
    return adresaci;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < (int) daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawIdAdresata(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownikaDoKtoregoNalezyAdresat(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata() {
    return idOstatniegoAdresata;
}

void PlikZAdresatami::zaktualizujDaneWybranegoAdresataWPliku(Adresat adresat, bool czyUsunac) {
    int nr_pola = 1;
    string linia;
    string temp;
    Adresat kumpel;

    fstream odczytywanyPlikTekstowy;
    fstream tymczasowyPlikTekstowy;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO,ios::in);
    tymczasowyPlikTekstowy.open("TYMCZASOWY_" + NAZWA_PLIKU_TEKSTOWEGO,ios::out | ios::trunc);

    if (!tymczasowyPlikTekstowy.good()) {
        tymczasowyPlikTekstowy<<"\n";
    } else if (odczytywanyPlikTekstowy.good()) {
        while(!odczytywanyPlikTekstowy.eof()) {
            getline(odczytywanyPlikTekstowy, linia);;

            for (int i = 0; i < (int) linia.length(); i++) {
                if (linia[i] == '|') {
                    switch(nr_pola) {
                    case 1:
                        kumpel.ustawIdAdresata(atoi(temp.c_str()));
                        break;
                    case 2:
                        kumpel.ustawIdUzytkownikaDoKtoregoNalezyAdresat(atoi(temp.c_str()));
                        break;
                    case 3:
                        kumpel.ustawImie(temp);
                        break;
                    case 4:
                        kumpel.ustawNazwisko(temp);
                        break;
                    case 5:
                        kumpel.ustawNumerTelefonu(temp);
                        break;
                    case 6:
                        kumpel.ustawEmail(temp);
                        break;
                    case 7:
                        kumpel.ustawAdres(temp);
                        break;
                    }

                    if (nr_pola == 7) {
                        nr_pola = 1;
                    } else {
                        nr_pola++;
                    }

                    temp = "";
                } else {
                    temp.push_back(linia.at(i));
                }
            }

            if (kumpel.pobierzIdAdresata()!=adresat.pobierzIdAdresata()) {
                tymczasowyPlikTekstowy<<linia;
            } else {
                if (czyUsunac) {
                    continue;
                } else {
                    tymczasowyPlikTekstowy<<zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
                }
            }

            kumpel.ustawIdAdresata(atoi("")); kumpel.ustawIdUzytkownikaDoKtoregoNalezyAdresat(atoi("")); kumpel.ustawImie(""); kumpel.ustawNazwisko(""); kumpel.ustawNumerTelefonu(""); kumpel.ustawEmail(""); kumpel.ustawAdres("");

            if (!odczytywanyPlikTekstowy.eof()) {
                tymczasowyPlikTekstowy << endl;
            }
        }
    }
    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    usunPlik(NAZWA_PLIKU_TEKSTOWEGO);
    zmienNazwePliku("TYMCZASOWY_" + NAZWA_PLIKU_TEKSTOWEGO, NAZWA_PLIKU_TEKSTOWEGO);

    return;
}
