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

// Implementacja metod dla PracownikaSerwisu
void PracownikSerwisu::przyjmij_zgloszenie(int numerZgloszenia) {
    cout << "Przyj璚ie zg這szenia nr " << numerZgloszenia << " przez pracownika: " << imie << " " << nazwisko << endl;
    zgloszenia.push_back(numerZgloszenia);
}

void PracownikSerwisu::zakoncz_zgloszenie(int numerZgloszenia) {
    cout << "Zako鎍zenie zg這szenia nr " << numerZgloszenia << " przez pracownika: " << imie << " " << nazwisko << endl;
}

// Implementacja metod dla Urzadzenia
void Urzadzenie::zarejestruj_urzadzenie() {
    cout << "Rejestracja urz鉅zenia: " << model << endl;
}

void Urzadzenie::aktualizuj_informacje() {
    cout << "Aktualizacja informacji urz鉅zenia: " << model << endl;
}

// Implementacja metod dla ZgloszeniaSerwisowego
void ZgloszenieSerwisowe::aktualizuj_status(std::string nowyStatus) {
    status = nowyStatus;
    cout << "Aktualizacja statusu zg這szenia nr " << numer_zgloszenia << " na: " << status << endl;
}

void ZgloszenieSerwisowe::przypisz_pracownika(PracownikSerwisu* pracownik) {
    // Tutaj nale瘸這by zaimplementowa� dodatkow� logik�
    cout << "Przypisanie pracownika do zg這szenia nr " << numer_zgloszenia << endl;
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
