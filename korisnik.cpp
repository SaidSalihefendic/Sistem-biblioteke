#include "korisnik.h"


int Korisnik::ID = 0;

/********************************************************************************************************/

Korisnik::Korisnik(string ime, string prezime)
{
    this->ime = ime;
    this->prezime = prezime;
    this->brojClanske = ++ID;
    trenutniBrojKnjiga = 0;
    preuzeteKnjige = new Dokument*[5];
}

/********************************************************************************************************/

Korisnik::Korisnik(const Korisnik& kopija)
{
    ime = kopija.ime;
    prezime = kopija.prezime;
    brojClanske = kopija.brojClanske;
    trenutniBrojKnjiga = kopija.trenutniBrojKnjiga;
    preuzeteKnjige = new Dokument*[5];

    for(int i = 0; i < trenutniBrojKnjiga; i++)
        preuzeteKnjige[i] = kopija.preuzeteKnjige[i];
}

/********************************************************************************************************/

Korisnik::~Korisnik()
{
    delete [] preuzeteKnjige;
}

/********************************************************************************************************/

void Korisnik::dodajKnjigu(Dokument* p)
{
    if(trenutniBrojKnjiga == 5) return;

    preuzeteKnjige[trenutniBrojKnjiga++] = p;
}

/********************************************************************************************************/

void Korisnik::izbaciKnjigu(int index)
{
    if(trenutniBrojKnjiga == 0 || index < 0 || index >= trenutniBrojKnjiga) return;

    for(int i = index; i < trenutniBrojKnjiga - 1; i++)
        preuzeteKnjige[i] = preuzeteKnjige[i + 1];

    trenutniBrojKnjiga--;
    preuzeteKnjige[trenutniBrojKnjiga] = new Dokument();

    delete preuzeteKnjige[trenutniBrojKnjiga]; //da se izbjegne situacija memory leak-a
}

/********************************************************************************************************/

void Korisnik::listaKnjiga() const
{
    for(int i = 0; i < trenutniBrojKnjiga; i++)
        preuzeteKnjige[i]->ispis();

    cout << endl;
}

/********************************************************************************************************/

Korisnik& Korisnik::operator=(const Korisnik& kopija)
{
    if(this == &kopija) return *this;

    delete [] preuzeteKnjige;

    ime = kopija.ime;
    prezime = kopija.prezime;
    brojClanske = kopija.brojClanske;
    trenutniBrojKnjiga = kopija.trenutniBrojKnjiga;
    preuzeteKnjige = new Dokument*[5];

    for(int i = 0; i < trenutniBrojKnjiga; i++)
        preuzeteKnjige[i] = kopija.preuzeteKnjige[i];

    return *this;
}

/********************************************************************************************************/

void Korisnik::ispis() const
{
    cout << ime << " " << prezime << ", " << brojClanske << endl;

    cout << "Preuzete knjige: " << endl;
    cout << "------------------------------------------------------------------" << endl;
    for(int i = 0; i < trenutniBrojKnjiga; i++)
    {
        cout << i + 1 << "." << endl;
        preuzeteKnjige[i]->ispis();
        cout << endl << "------------------------------------------------------------------" << endl;
    } //end for
}
