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
    Osoba(string Imie = "", string Nazwisko = "") : imie(Imie), nazwisko(Nazwisko) {}
    virtual ~Osoba() {
        cout << "Ta osoba juz nie jest w systemie" << endl;
    }
};

// Definicja klasy Klient
class Klient : public Osoba {
    friend void wyswietlInformacjeKlienta(const Klient& klient);
    friend class SerwisKomputerowy;
private:
    string numer_telefonu;
    string email;
public:
    Klient(string imie = "", string nazwisko = "", string tel = "", string mail = "") : Osoba(imie, nazwisko), numer_telefonu(tel), email(mail) {}
    void zglos_problem();
    void sprawdz_status();
    void aktualizuj_dane(string nowy_numer_telefonu, string nowy_email);
    ~Klient() {
        cout << "Ten klient juz nie jest w systemie" << endl;
    }
};

// Definicja klasy PracownikSerwisu
class PracownikSerwisu : public Osoba {
    friend class SerwisKomputerowy;
private:
    string specjalizacja;
    vector<int> zgloszenia;
public:
    PracownikSerwisu(string imie = "", string nazwisko = "", string spec = "") : Osoba(imie, nazwisko), specjalizacja(spec) {}
    void przyjmij_zgloszenie(int numerZgloszenia);
    void zakoncz_zgloszenie(int numerZgloszenia);
    void aktualizuj_specjalizacje(string nowa_specjalizacja);
    ~PracownikSerwisu() {
        cout << "Ten pracownik juz nie pracuje" << endl;
    }
};

// Definicja klasy Urzadzenie
class Urzadzenie {
    friend class SerwisKomputerowy;
    friend void zarejestrujUrzadzenie(const Urzadzenie& urzadzenie);
private:
    string typ;
    string model;
    string numer_seryjny;
public:
    Urzadzenie(string Typ = "", string Model = "", string NumerSeryjny = "") : typ(Typ), model(Model), numer_seryjny(NumerSeryjny) {}
    //void zarejestruj_urzadzenie();
    void aktualizuj_informacje();
    void zaktualizuj_model(string nowy_model);
    ~Urzadzenie() {
        cout << "To urzadzenie juz nie istnieje" << endl;
    }
};

// Definicja klasy ZgloszenieSerwisowe
class ZgloszenieSerwisowe {
    friend class SerwisKomputerowy;
    friend void aktualizujStatusZgloszenia(const ZgloszenieSerwisowe& zgloszenie);
private:
    int numer_zgloszenia;
    string opis_problemu;
    string status;
public:
    ZgloszenieSerwisowe(int numer = 0, string opis = "", string Status = "") : numer_zgloszenia(numer), opis_problemu(opis), status(Status) {}
    //void aktualizuj_status(string nowyStatus);
    void dodaj_opis_problemu(string nowy_opis);
    ~ZgloszenieSerwisowe() {
        cout << "Tego zgloszenia juz nie ma" << endl;
    }
};

// Definicja klasy SerwisKomputerowy
class SerwisKomputerowy {
    friend void sprawdzStatusSerwisu(const SerwisKomputerowy& serwis);
private:
    string nazwa;
    string adres;
    vector<PracownikSerwisu*> pracownicy;
    vector<ZgloszenieSerwisowe*> zgloszenia;
public:
    SerwisKomputerowy(string Nazwa = "", string Adres = "") : nazwa(Nazwa), adres(Adres) {}
    void dodaj_klienta(Klient* klient);
    ~SerwisKomputerowy() {
        cout << "Ten serwis komputerowy juz nie istnieje" << endl;
    }
};

// Definicja klasy CzescZamienna
class CzescZamienna {
    friend void zamowCzesc(const CzescZamienna& czesc);
private:
    string nazwa;
    string model;
    string kompatybilnosc;
    double cena;
public:
    CzescZamienna(string Nazwa = "", string Model = "", string Kompatybilnosc = "", double Cena = 0.0) : nazwa(Nazwa), model(Model), kompatybilnosc(Kompatybilnosc), cena(Cena) {}
    //void zamow_czesc();
    ~CzescZamienna() {
        cout << "Tej czesci zamiennej juz nie ma" << endl;
    }
};

// Definicja klasy NarzedziaDiagnostyczne
class NarzedziaDiagnostyczne {
private:
    string nazwa;
    string typ;
    string wersja;
public:
    NarzedziaDiagnostyczne(string Nazwa = "", string Typ = "", string Wersja = "") : nazwa(Nazwa), typ(Typ), wersja(Wersja) {}
    void wykonaj_diagnostyke(Urzadzenie* urzadzenie);
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
    RaportSerwisowy(ZgloszenieSerwisowe* Zgloszenie = nullptr, string Diagnostyka = "", string Rekomendacje = "") : zgloszenie(Zgloszenie), wyniki_diagnostyki(Diagnostyka), rekomendacje(Rekomendacje) {}
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
    HistoriaSerwisowa(Urzadzenie* Urzadzenie = nullptr) : urzadzenie(Urzadzenie) {}
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
    SystemZarzadzania() {}
    void przydziel_zgloszenie(ZgloszenieSerwisowe* zgloszenie);
    void zaktualizuj_inwentarz();
    ~SystemZarzadzania() {
        cout << "Ten system zarzadzania juz nie istnieje" << endl;
    }
};

#endif // KLASY_H