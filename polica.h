#ifndef POLICA_H
#define POLICA_H

#include <string>
#include "dokument.h"
#include "knjiga.h"
#include "fajl.h"
#include "naucnirad.h"

    //sortiranje dokumenata(ideja - MergeSort ili Insertion Sort prilikom unosa)
class Polica
{
public:
        //konstruktori i destruktor
    Polica();
    Polica(string oznaka, int kapacitet);
    Polica(const Polica& p);
    ~Polica();

        //funkcija koja ce dodavati dokument u niz dokumenti, ukoliko je kapacitet pun, ne ubacuje knjigu
    void dodajDokument(Dokument& d);
    void dodajDokument();
    void ispis() const;

        //da vrati koliko je jos moguce knjiga staviti na policu
    int vratiProstor() const;

    Polica& operator =(const Polica& p);

    Dokument* operator[](int index) throw (char); //baca izuzetak ukoliko se ne moze pristupiti, trebat ce zbog nacin pristupanja dokumenata unutar polica
    Dokument* izbaciDokument(int index) throw (char);
private:
    string oznaka; //da se oznaci polica
    Dokument** dokumenti;
    int kapacitet, brojKnjiga;
    int id;
    static int PID;
};

#endif // POLICA_H
