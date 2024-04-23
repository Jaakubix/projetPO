#include <iostream>
#include "klasy.h"
#include <vector>
using namespace std;

int main() {
    SerwisKomputerowy serwis;
    serwis.nazwa = "Naprawa Komputerów 24h";
    serwis.adres = "ul. Techniczna 10, Warszawa";

    Klient klient1;
    klient1.imie = "Jan";
    klient1.nazwisko = "Kowalski";
    klient1.numer_telefonu = "500600700";
    klient1.email = "jan.kowalski@example.com";

    serwis.dodaj_klienta(&klient1);

    Urzadzenie laptopKlienta1;
    laptopKlienta1.typ = "Laptop";
    laptopKlienta1.model = "Dell XPS 15";
    laptopKlienta1.numer_seryjny = "123456789";
    laptopKlienta1.wlasciciel = &klient1;

    laptopKlienta1.zarejestruj_urzadzenie();

    ZgloszenieSerwisowe zgloszenie1;
    zgloszenie1.numer_zgloszenia = 1;
    zgloszenie1.opis_problemu = "Nie wlacza sie ekran.";
    zgloszenie1.status = "Oczekuje";
    zgloszenie1.klient = &klient1;
    zgloszenie1.urzadzenie = &laptopKlienta1;

    serwis.przyjmij_zgloszenie(&zgloszenie1);

    PracownikSerwisu pracownik1;
    pracownik1.imie = "Anna";
    pracownik1.nazwisko = "Nowak";
    pracownik1.specjalizacja = "Naprawa sprzetu komputerowego";

    zgloszenie1.przypisz_pracownika(&pracownik1);
    pracownik1.przyjmij_zgloszenie(zgloszenie1.numer_zgloszenia);

    cout << "Serwis: " << serwis.nazwa << ", Adres: " << serwis.adres << endl;
    cout << "Klient: " << klient1.imie << " " << klient1.nazwisko << ", Email: " << klient1.email << endl;
    cout << "Zgloszenie: " << zgloszenie1.numer_zgloszenia << ", Opis problemu: " << zgloszenie1.opis_problemu << ", Status: " << zgloszenie1.status << endl;
    cout << "Pracownik przydzielony do zgloszenia: " << pracownik1.imie << " " << pracownik1.nazwisko << ", Specjalizacja: " << pracownik1.specjalizacja << endl;


    return 0;
}