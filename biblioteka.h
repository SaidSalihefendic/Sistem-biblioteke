#ifndef BIBLIOTEKA_H
#define BIBLIOTEKA_H

#include <iostream>
#include <fstream>
#include "polica.h"
#include "korisnik.h"

    //glavna klasa, koja sadrzava police s dokumentima i podatke o korisnicima, njihovim knjigama
    //
class Biblioteka
{
private:
    Korisnik* korisnici;
    int brojKorisnika;
    Polica* police;
    int brojPolica;

public:
    Biblioteka(int brojPolica);

    void meni();

    void dodajKorisnika();
    void ispisKorisnika() const; //ispisuje korisnike i njegove detalje o preuzetim knjigama
    void ispisPolica() const;
    void dodajDokument();

    void korisnikPreuzima();
    void korisnikVraca();
    void provjeraStanja() const;
};

#endif // BIBLIOTEKA_H
