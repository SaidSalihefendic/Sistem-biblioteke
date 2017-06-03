#ifndef KNJIGA_H
#define KNJIGA_H

#include "dokument.h"

    ///Nasljedjuje ga naucni rad, udzbenik, roman i enciklopedija (uradjeno: Naucni rad)
class Knjiga : public Dokument
{
public:
    Knjiga();
    Knjiga(string naziv, string kategorija, string* autori, int brojAutora,
                         string mjestoIzdanja, int brojPrimjeraka, string* dostupniJezici,
                         int brojJezika, string* dostupnaPisma, int brojPisama, int godinaIzdanja,
                         int brojStranica, int brojIzdanja,
                         string izdavac, string stampa);

    Knjiga(const Knjiga& k);

        //getteri
    int vratiBrojStranica() const;
    int vratiBrojIzdanja() const;
    string vratiIzdavaca() const;
    string vratiStampu() const;


    virtual void ispis() const;
    virtual void unosPodataka();

    Knjiga& operator=(const Knjiga& k);


protected:
    int brojStranica;
    int brojIzdanja;
    string izdavac;
    string stampa;
};


#endif // KNJIGA_H
