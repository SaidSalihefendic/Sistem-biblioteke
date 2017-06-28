#ifndef POLICA_H
#define POLICA_H

#include <string>
#include "dokument.h"
#include "knjiga.h"
#include "fajl.h"
#include "naucnirad.h"

    //sortiranje dokumenata(ideja - MergeSort ili Insertion Sort prilikom unosa), uzimanjeKnjige()
class Polica
{
public:
        //konstruktori i destruktor
    Polica();
    Polica(string oznaka, int kapacitet);
    Polica(const Polica& p);
    ~Polica();

        //funkcija koja ce dodavati dokument u niz dokumenti, ukoliko je kapacitet pun, ne ubacuje knjigu
    void dodajDokument(Dokument* d);
    void dodajDokument() throw (char);
    void ispis() const;

        //A10, primjer
    string vratiOznaku() const;

        //da vrati koliko je jos moguce knjiga staviti na policu
    int vratiBrojKnjiga() const;

    Polica& operator =(const Polica& p);

    Dokument* operator[](int index) throw (char); //baca izuzetak ukoliko se ne moze pristupiti, trebat ce zbog nacin pristupanja dokumenata unutar polica
    Dokument* izbaciDokument(int index) throw (char);
    Dokument* uzmiDokument(int index) throw (char);
    void vratiKnjigu(Dokument* d);

private:
    string oznaka; //da se oznaci polica
    Dokument** dokumenti;
    bool* jePrisutan; //da se zna koji su se dokumenti uzeli iz
    int kapacitet, brojKnjiga;
    int id;
    static int PID;
};

#endif // POLICA_H
