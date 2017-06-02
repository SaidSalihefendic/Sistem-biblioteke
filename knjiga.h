#ifndef KNJIGA_H
#define KNJIGA_H

#include "dokument.h"

class Knjiga : public Dokument
{
public:
    Knjiga();
    Knjiga(string naziv, string kategorija, string* autori, int brojAutora,
                         string mjestoIzdanja, int brojPrimjeraka, string* dostupniJezici,
                         int brojJezika, string* dostupnaPisma, int brojPisama, int godinaIzdanja,
                         string* recenzenti, int brojRecenzenata, int brojStranica, int brojIzdanja,
                         string izdavac, string stampa);

        //getteri
    int vratiBrojStranica() const;
    int vratiBrojIzdanja() const;
    int vratiBrojRecenzenata() const;
    string* vratiRecenzente() const;
    string vratiIzdavaca() const;
    string vratiStampu() const;


    void ispis() const;
    void unosPodataka();

protected:
    int brojStranica;
    int brojIzdanja;

        //niz jer moze dokument imati vise recenzenata
    string* recenzenti;
    int brojRecenzenata;

    string izdavac;
    string stampa;
};


#endif // KNJIGA_H
