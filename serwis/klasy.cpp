#include "klasy.h"
#include <iostream>
using namespace std;

// Implementacja metod dla Klienta
void Klient::zglos_problem() {
    cout << "Zg�oszenie problemu przez klienta: " << imie << " " << nazwisko << endl;
}

void Klient::sprawdz_status() {
    cout << "Sprawdzanie statusu zg�oszenia przez klienta: " << imie << " " << nazwisko << endl;
}

// Implementacja metod dla PracownikaSerwisu
void PracownikSerwisu::przyjmij_zgloszenie(int numerZgloszenia) {
    cout << "Przyj�cie zg�oszenia nr " << numerZgloszenia << " przez pracownika: " << imie << " " << nazwisko << endl;
    zgloszenia.push_back(numerZgloszenia);
}

void PracownikSerwisu::zakoncz_zgloszenie(int numerZgloszenia) {
    cout << "Zako�czenie zg�oszenia nr " << numerZgloszenia << " przez pracownika: " << imie << " " << nazwisko << endl;
}

// Implementacja metod dla Urzadzenia
void Urzadzenie::zarejestruj_urzadzenie() {
    cout << "Rejestracja urz�dzenia: " << model << endl;
}

void Urzadzenie::aktualizuj_informacje() {
    cout << "Aktualizacja informacji urz�dzenia: " << model << endl;
}

// Implementacja metod dla ZgloszeniaSerwisowego
void ZgloszenieSerwisowe::aktualizuj_status(std::string nowyStatus) {
    status = nowyStatus;
    cout << "Aktualizacja statusu zg�oszenia nr " << numer_zgloszenia << " na: " << status << endl;
}

void ZgloszenieSerwisowe::przypisz_pracownika(PracownikSerwisu* pracownik) {
    // Tutaj nale�a�oby zaimplementowa� dodatkow� logik�
    cout << "Przypisanie pracownika do zg�oszenia nr " << numer_zgloszenia << endl;
}

// Implementacja metod dla SerwisuKomputerowego
void SerwisKomputerowy::dodaj_klienta(Klient* klient) {
    klienci.push_back(klient);
    cout << "Dodanie klienta: " << klient->imie << " " << klient->nazwisko << endl;
}

void SerwisKomputerowy::przyjmij_zgloszenie(ZgloszenieSerwisowe* zgloszenie) {
    zgloszenia.push_back(zgloszenie);
    cout << "Przyj�cie zg�oszenia nr " << zgloszenie->numer_zgloszenia << endl;
}

void SerwisKomputerowy::wydaj_urzadzenie(Urzadzenie* urzadzenie) {
    cout << "Wydanie urz�dzenia: " << urzadzenie->model << endl;
}

// Implementacja metod dla NarzedziDiagnostycznych
void NarzedziaDiagnostyczne::wykonaj_diagnostyke(Urzadzenie* urzadzenie) {
    cout << "Wykonanie diagnostyki urz�dzenia: " << urzadzenie->model << endl;
}

void NarzedziaDiagnostyczne::aktualizuj_oprogramowanie() {
    cout << "Aktualizacja oprogramowania narz�dzi diagnostycznych" << endl;
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
    cout << "Dodanie zg�oszenia nr " << zgloszenie->numer_zgloszenia << " do historii urz�dzenia" << endl;
}

void HistoriaSerwisowa::pobierz_historie() {
    cout << "Pobieranie historii serwisowej urz�dzenia" << endl;
}

// Implementacja metod dla SystemuZarzadzania
void SystemZarzadzania::przydziel_zgloszenie(ZgloszenieSerwisowe* zgloszenie) {
    cout << "Przydzielenie zg�oszenia nr " << zgloszenie->numer_zgloszenia << endl;
}

void SystemZarzadzania::zaktualizuj_inwentarz() {
    cout << "Aktualizacja inwentarza systemu zarz�dzania" << endl;
}
