#ifndef DOKUMENT_H
#define DOKUMENT_H

#include <iostream>
#include <string>
#include "datum.h"
using namespace std;

    //konstante radi lakseg rada i preglednosti koda

    //postoji sansa da ovo bude abstraktna klasa zbog konkretnih primjera kasnije, za sada nije zbog testiranja
class Dokument
{
public:
        //defaultni konstruktor, radi lakseg rada
    Dokument();
        //konstruktor za inicijalizaciju osnovnih informacija jednog tipa dokumenta
    Dokument(string naziv, string kategorija, string* autori, int brojAutora,
                     string mjestoIzdanja, int brojPrimjeraka, string* dostupniJezici,
                     int brojJezika, string* dostupnaPisma, int brojPisama, int godinaIzdanja);

        //destruktor, koji ce biti zasluzan za ponistavanje citave knjige, eksplicitan poziv u arhivi
    ~Dokument();

        //getteri
    string vratiNaziv() const;
    string vratiKategoriju() const;
    string vratiZanr() const;
    string* vratiAutore() const;    //najvjerovatnije da treba proslijediti parametar neki niz, tako da ne dodje se do konflikta pokazivaca koji pokazuju na istu mem. lokaciju
    int vratiBrojAutora() const;
    string vratiMjestoIzdanja() const;
    int vratiBrojPrimjeraka() const;
    string* vratiDostupneJezike() const;    //najvjerovatnije da treba proslijediti parametar neki niz, tako da ne dodje se do konflikta pokazivaca koji pokazuju na istu mem. lokaciju
    int vratiBrojJezika() const;
    string* vratiDostupnaPisma() const;    //najvjerovatnije da treba proslijediti parametar neki niz, tako da ne dodje se do konflikta pokazivaca koji pokazuju na istu mem. lokaciju
    int vratiBrojPisama() const;

        //konzolni ispis
    virtual void ispis() const; //  bitno je da bude virtuelna zbog kasnije niza dokumenata sto cemo imati
    virtual void unosPodataka();
protected:
        //odnosit ce se na sve dokumente, neovisno da li je u pitanju knjiga, enciklopedija...
    static int jedinstveniBarkod;
        //svaki dokument ima svoju sifru, tj. barkod
    int barkod;
    int godinaIzdanja;
    string naziv;
    string kategorija; //da li je za obrazovanje ili komercijala ili vec sta
    string zanr;

        //niz autora
    string* autori;
    int brojAutora;

        //zelimo imati mjesto izdanja dokumenta, broj primjeraka tog dokumenta i slicno
    string mjestoIzdanja;
    int brojPrimjeraka;

        //na kojim jezicima je taj dokument dostupan
    string* dostupniJezici;
    int brojJezika;

        //na kojim pismima su pisani dokumenti
    string* dostupnaPisma;
    int brojPisama;
};


    //knjige, enciklopedije, manuskripti, ... Ustvari, svaki papirni format je, u sustini, neka vrsta knjige



class Fajl : public Dokument
{
public:
    Fajl();
    Fajl(string naziv, string kategorija, string* autori, int brojAutora,
                         string mjestoIzdanja, int brojPrimjeraka, string* dostupniJezici,
                         int brojJezika, string* dostupnaPisma, int brojPisama, int godinaIzdanja,
                         double velicina, string tip, string verzija);

    double vratiVelicinu() const;
    string vratiTip() const;
    string vratiVerziju() const;

    void ispis() const;
    void unosPodataka();

protected:
    double velicina; //velicina fajla
    string tip;
    string verzija;
};

#endif // DOKUMENT_H
