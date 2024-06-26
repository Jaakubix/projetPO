#include "klasy.h"
#include <iostream>
using namespace std;

// Implementacja metod dla Klienta
void Klient::zglos_problem() {
    cout << "Zg這szenie problemu przez klienta: " << imie << " " << nazwisko << endl;
}

void Klient::sprawdz_status() {
    cout << "Sprawdzanie statusu zg這szenia przez klienta: " << imie << " " << nazwisko << endl;
}

void Klient::aktualizuj_dane(string nowy_numer_telefonu, string nowy_email) {
    this->numer_telefonu = nowy_numer_telefonu;
    this->email = nowy_email;
    cout << "Dane klienta zaktualizowane: " << this->numer_telefonu << ", " << this->email << endl;
}

// Implementacja metod dla PracownikaSerwisu
void PracownikSerwisu::przyjmij_zgloszenie(int numerZgloszenia) {
    cout << "Przyj璚ie zg這szenia nr " << numerZgloszenia << " przez pracownika: " << imie << " " << nazwisko << endl;
    zgloszenia.push_back(numerZgloszenia);
}

void PracownikSerwisu::zakoncz_zgloszenie(int numerZgloszenia) {
    cout << "Zako鎍zenie zg這szenia nr " << numerZgloszenia << " przez pracownika: " << imie << " " << nazwisko << endl;
}

void PracownikSerwisu::aktualizuj_specjalizacje(string nowa_specjalizacja) {
    this->specjalizacja = nowa_specjalizacja;
    cout << "Specjalizacja pracownika zaktualizowana: " << this->specjalizacja << endl;
}

// Implementacja metod dla Urzadzenia
/*void Urzadzenie::zarejestruj_urzadzenie() {
    cout << "Rejestracja urz鉅zenia: " << model << endl;
}*/

void Urzadzenie::aktualizuj_informacje() {
    cout << "Aktualizacja informacji urz鉅zenia: " << model << endl;
}

void Urzadzenie::zaktualizuj_model(string nowy_model) {
    this->model = nowy_model;
    cout << "Model urz鉅zenia zaktualizowany: " << this->model << endl;
}

// Implementacja metod dla ZgloszeniaSerwisowego
/*void ZgloszenieSerwisowe::aktualizuj_status(std::string nowyStatus) {
    status = nowyStatus;
    cout << "Aktualizacja statusu zg這szenia nr " << numer_zgloszenia << " na: " << status << endl;
}*/

void ZgloszenieSerwisowe::przypisz_pracownika(PracownikSerwisu* pracownik) {
    // Tutaj nale瘸這by zaimplementowa� dodatkow� logik�
    cout << "Przypisanie pracownika do zg這szenia nr " << numer_zgloszenia << endl;
}

void ZgloszenieSerwisowe::dodaj_opis_problemu(string nowy_opis) {
    this->opis_problemu = nowy_opis;
    cout << "Opis problemu zaktualizowany: " << this->opis_problemu << endl;
}

// Implementacja metod dla SerwisuKomputerowego
void SerwisKomputerowy::dodaj_klienta(Klient* klient) {
    klienci.push_back(klient);
    cout << "Dodanie klienta: " << klient->imie << " " << klient->nazwisko << endl;
}

void SerwisKomputerowy::przyjmij_zgloszenie(ZgloszenieSerwisowe* zgloszenie) {
    zgloszenia.push_back(zgloszenie);
    cout << "Przyj璚ie zg這szenia nr " << zgloszenie->numer_zgloszenia << endl;
}

void SerwisKomputerowy::wydaj_urzadzenie(Urzadzenie* urzadzenie) {
    cout << "Wydanie urz鉅zenia: " << urzadzenie->model << endl;
}

// Implementacja metod dla NarzedziDiagnostycznych
void NarzedziaDiagnostyczne::wykonaj_diagnostyke(Urzadzenie* urzadzenie) {
    cout << "Wykonanie diagnostyki urz鉅zenia: " << urzadzenie->model << endl;
}

void NarzedziaDiagnostyczne::aktualizuj_oprogramowanie() {
    cout << "Aktualizacja oprogramowania narz璠zi diagnostycznych" << endl;
}

// Implementacja metod dla RaportuSerwisowego
void RaportSerwisowy::utworz_raport() {
    cout << "Utworzenie raportu serwisowego" << endl;
}

void RaportSerwisowy::aktualizuj_raport() {
    cout << "Aktualizacja raportu serwisowego" << endl;
}

// Implementacja metod dla HistoriiSerwisowej
void HistoriaSerwisowa::dodaj_wpis(ZgloszenieSerwisowe* zgloszenie) {
    historia_zgloszen.push_back(zgloszenie);
    cout << "Dodanie zg這szenia nr " << zgloszenie->numer_zgloszenia << " do historii urz鉅zenia" << endl;
}

void HistoriaSerwisowa::pobierz_historie() {
    cout << "Pobieranie historii serwisowej urz鉅zenia" << endl;
}

// Implementacja metod dla SystemuZarzadzania
void SystemZarzadzania::przydziel_zgloszenie(ZgloszenieSerwisowe* zgloszenie) {
    cout << "Przydzielenie zg這szenia nr " << zgloszenie->numer_zgloszenia << endl;
}

void SystemZarzadzania::zaktualizuj_inwentarz() {
    cout << "Aktualizacja inwentarza systemu zarz鉅zania" << endl;
}

//friend
void wyswietlInformacjeKlienta(const Klient& klient) {
    cout << "Klient: " << klient.imie << " " << klient.nazwisko << ", tel: " << klient.numer_telefonu << ", email: " << klient.email << endl;
}

void zarejestrujUrzadzenie(const Urzadzenie& urzadzenie) {
    cout << "Rejestracja urz鉅zenia: " << urzadzenie.model << " - " << urzadzenie.numer_seryjny << endl;
}

void aktualizujStatusZgloszenia(const ZgloszenieSerwisowe& zgloszenie) {
    cout << "Aktualizacja statusu zg這szenia nr " << zgloszenie.numer_zgloszenia << " na: " << zgloszenie.status << endl;
}

void sprawdzStatusSerwisu(const SerwisKomputerowy& serwis) {
    cout << "Serwis komputerowy: " << serwis.nazwa << " znajduje si� pod adresem: " << serwis.adres << endl;
}

void zamowCzesc(const CzescZamienna& czesc) {
    cout << "Zam闚ienie cz��ci: " << czesc.nazwa << ", model: " << czesc.model << ", cena: " << czesc.cena << " PLN" << endl;
}