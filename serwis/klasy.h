#ifndef KLASY_H
#define KLASY_H

#include<iostream>
#include <string>
#include <vector>
using namespace std;

// Definicja klasy Osoba
class Osoba {
public:
    string imie;
    string nazwisko;
    virtual ~Osoba() {
        cout << "Ta osoba juz nie jest w systemie" << endl;
    }
};

// Definicja klasy Klient
class Klient : public Osoba {
public:
    string numer_telefonu;
    string email;

    void zglos_problem();
    void sprawdz_status();
    ~Klient() {
        cout << "Ten klient juz nie jest w systemie" << endl;
    }
};

// Definicja klasy PracownikSerwisu
class PracownikSerwisu : public Osoba {
public:
    string specjalizacja;
    vector<int> zgloszenia;

    void przyjmij_zgloszenie(int numerZgloszenia);
    void zakoncz_zgloszenie(int numerZgloszenia);
    ~PracownikSerwisu() {
        cout << "Ten pracownik juz nie pracuje" << endl;
    }
};

// Definicja klasy Urzadzenie
class Urzadzenie {
public:
    string typ;
    string model;
    string numer_seryjny;
    Klient* wlasciciel;

    void zarejestruj_urzadzenie();
    void aktualizuj_informacje();
    ~Urzadzenie() {
        cout << "To urzadzenie juz nie istnieje" << endl;
    }
};

// Definicja klasy ZgloszenieSerwisowe
class ZgloszenieSerwisowe {
public:
    int numer_zgloszenia;
    string opis_problemu;
    string status;
    Klient* klient;
    Urzadzenie* urzadzenie;

    void aktualizuj_status(std::string nowyStatus);
    void przypisz_pracownika(PracownikSerwisu* pracownik);
    ~ZgloszenieSerwisowe() {
        cout << "Tego zgloszenia juz nie ma" << endl;
    }
};

// Definicja klasy SerwisKomputerowy
class SerwisKomputerowy {
public:
    string nazwa;
    string adres;
    vector<PracownikSerwisu*> pracownicy;
    vector<ZgloszenieSerwisowe*> zgloszenia;
    vector<Klient*> klienci;

    void dodaj_klienta(Klient* klient);
    void przyjmij_zgloszenie(ZgloszenieSerwisowe* zgloszenie);
    void wydaj_urzadzenie(Urzadzenie* urzadzenie);
    ~SerwisKomputerowy() {
        cout << "Ten serwis komputerowy juz nie istnieje" << endl;
    }
};

// Definicja klasy CzescZamienna
class CzescZamienna {
public:
    string nazwa;
    string model;
    string kompatybilnosc;
    double cena;

    void zamow_czesc();
    void sprawdz_dostepnosc();
    ~CzescZamienna() {
        cout << "Tej czesci zamiennej juz nie ma" << endl;
    }
};

// Definicja klasy NarzedziaDiagnostyczne
class NarzedziaDiagnostyczne {
public:
    string nazwa;
    string typ;
    string wersja;

    void wykonaj_diagnostyke(Urzadzenie* urzadzenie);
    void aktualizuj_oprogramowanie();
    ~NarzedziaDiagnostyczne() {
        cout << "Tego narzedzia diagnistycznego juz nie ma" << endl;
    }
};

// Definicja klasy RaportSerwisowy
class RaportSerwisowy {
public:
    ZgloszenieSerwisowe* zgloszenie;
    string wyniki_diagnostyki;
    string rekomendacje;

    void utworz_raport();
    void aktualizuj_raport();
    ~RaportSerwisowy() {
        cout << "Ten raport serwisowy juz nie jest w systemie" << endl;
    }
};

// Definicja klasy HistoriaSerwisowa
class HistoriaSerwisowa {
public:
    Urzadzenie* urzadzenie;
    vector<ZgloszenieSerwisowe*> historia_zgloszen;

    void dodaj_wpis(ZgloszenieSerwisowe* zgloszenie);
    void pobierz_historie();
    ~HistoriaSerwisowa() {
        cout << "Tej historii serwisowej juz nie ma w systemie" << endl;
    }
};

// Definicja klasy SystemZarzadzania
class SystemZarzadzania {
public:
    vector<ZgloszenieSerwisowe*> zgloszenia;
    vector<PracownikSerwisu*> pracownicy;
    vector<NarzedziaDiagnostyczne*> narzedzia;
    vector<CzescZamienna*> czesci_zamienne;

    void przydziel_zgloszenie(ZgloszenieSerwisowe* zgloszenie);
    void zaktualizuj_inwentarz();
    ~SystemZarzadzania() {
        cout << "Ten system zarzadzania juz nie istnieje" << endl;
    }
};

#endif // KLASY_H