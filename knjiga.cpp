#include "knjiga.h"
#include <iostream>
#include <limits>
using namespace std;
///----------------------------------------------------------------------------------------------------------------------

Knjiga::Knjiga() : Dokument() {}

///----------------------------------------------------------------------------------------------------------------------

Knjiga::Knjiga(string naziv, string kategorija, string* autori, int brojAutora,
                         string mjestoIzdanja, string* dostupniJezici,
                         int brojJezika, int godinaIzdanja,
                         int brojStranica, int brojIzdanja, string izdavac, string stampa) : Dokument(naziv, kategorija, autori, brojAutora, mjestoIzdanja, dostupniJezici, brojJezika, godinaIzdanja)
{
    this->brojStranica = brojStranica;
    this->brojIzdanja = brojIzdanja;
    this->izdavac = izdavac;
    this->stampa = stampa;
}

///----------------------------------------------------------------------------------------------------------------------

Knjiga::Knjiga(const Knjiga& k) : Dokument(k)
{
    brojStranica = k.brojStranica;
    brojIzdanja = k.brojIzdanja;
    izdavac = k.izdavac;
    stampa = k.stampa;
}

///----------------------------------------------------------------------------------------------------------------------

    //getteri

int Knjiga::vratiBrojStranica() const
{
    return brojStranica;
}

int Knjiga::vratiBrojIzdanja() const
{
    return brojIzdanja;
}

string Knjiga::vratiIzdavaca() const
{
    return izdavac;
}

string Knjiga::vratiStampu() const
{
    return stampa;
}


///----------------------------------------------------------------------------------------------------------------------

void Knjiga::ispis() const
{
    Dokument::ispis();

    cout << "Broj stranica: " << brojStranica << endl;

    cout << "Broj izdanja: " << brojIzdanja << endl;

    cout << "Izdavac: " << izdavac << endl;

    cout << "Stampa: " << stampa << endl;

}

///----------------------------------------------------------------------------------------------------------------------

void Knjiga::unosPodataka()
{
    Dokument::unosPodataka();

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Izdavac: ";
    getline(cin, izdavac);

    cout << "Stampa: ";
    getline(cin, stampa);

    cout << "Broj izdanja: ";
    cin >> brojIzdanja;

    cout << "Broj stranica: ";
    cin >> brojStranica;
}


///----------------------------------------------------------------------------------------------------------------------
Knjiga& Knjiga::operator=(const Knjiga& k)
{
    if(this == &k) return *this;

    Dokument::operator=(k);
    brojStranica = k.brojStranica;
    brojIzdanja = k.brojIzdanja;
    izdavac = k.izdavac;
    stampa = k.stampa;

    return *this;
}
