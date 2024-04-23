#include <iostream>
#include "klasy.h"
#include <vector>
using namespace std;

int main() {
    
    // Creating instances of each class
    Klient klient1("Jan", "Kowalski");
    klient1.aktualizuj_dane("123456789", "jan@example.com");

    PracownikSerwisu pracownik1("Adam", "Nowak");
    pracownik1.przyjmij_zgloszenie(101);
    pracownik1.zakoncz_zgloszenie(101);

    Urzadzenie urzadzenie1("Printer Model X");
    urzadzenie1.aktualizuj_informacje();
    urzadzenie1.zaktualizuj_model("Printer Model X Plus");

    ZgloszenieSerwisowe zgloszenie1;
    zgloszenie1.aktualizuj_status("Resolved");

    NarzedziaDiagnostyczne narzedzie1("Skaner", "Diagnostyczne", "v1.2");
    narzedzie1.wykonaj_diagnostyke(&urzadzenie1);

    RaportSerwisowy raport1(&zgloszenie1, "Dane diagnostyczne", "Wymienić części");
    raport1.utworz_raport();
    raport1.aktualizuj_raport();

    HistoriaSerwisowa historia1(&urzadzenie1);
    historia1.dodaj_wpis(&zgloszenie1);
    historia1.pobierz_historie();

    SystemZarzadzania system1;
    system1.przydziel_zgloszenie(&zgloszenie1);
    system1.zaktualizuj_inwentarz();

    CzescZamienna czesc1("Dysk SSD", "HP", "12345XYZ");
    delete czesc1;

    return 0;
}