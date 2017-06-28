#ifndef KORISNIK_H
#define KORISNIK_H

#include <string>
#include "polica.h"
using namespace std;

class Korisnik
{
private:
    string ime, prezime;
    static int ID;
    int brojClanske;
//  string password;
    Dokument** preuzeteKnjige; //Maksimalno 5 knjiga moze se preuzeti
    int trenutniBrojKnjiga; //Koliko je trenutno preuzeo knjiga

public:
    Korisnik();
    Korisnik(string ime, string prezime);
    ~Korisnik();
    Korisnik(const Korisnik& kopija);

        //getteri
    int vratiClansku() const;
    string vratiIdentitet() const;
    int vratiTrenutniBrojKnjiga() const;

    void dodajKnjigu(Dokument* p);
    void izbaciKnjigu(int index);
    void ispis() const;
    void listaKnjiga() const;

    Dokument* operator[](int index) throw (char); //operator koji omogucava da se pristupi dokumentima koji je korisnik preuzeo

    Korisnik& operator = (const Korisnik& kopija);
};

#endif // KORISNIK_H
