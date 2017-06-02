#include "knjiga.h"
#include <iostream>
#include <limits>
using namespace std;
///----------------------------------------------------------------------------------------------------------------------

///*Knjiga();
//    Knjiga(string naziv, string kategorija, string* autori, int brojAutora,
//                         string mjestoIzdanja, int brojPrimjeraka, string* dostupniJezici,
//                         int brojJezika, string* dostupnaPisma, int brojPisama, int godinaIzdanja,
//                         string* recenzenti, int brojRecenzenata, int brojStranica, int brojIzdanja,
//                         string izdavac, string stampa);
//
//        //getteri
//    int vratiBrojStranica() const;
//    int vratiBrojIzdanja() const;
//    int vratiBrojRecenzenata() const;
//    string* vratiRecenzente() const;
//    string vratiIzdavaca() const;
//    string vratiStampu() const;
//
//
//    void ispis() const;
//    void unosPodataka();*/
Knjiga::Knjiga() : Dokument()
{
    brojRecenzenata = 0;
}


Knjiga::Knjiga(string naziv, string kategorija, string* autori, int brojAutora,
                         string mjestoIzdanja, int brojPrimjeraka, string* dostupniJezici,
                         int brojJezika, string* dostupnaPisma, int brojPisama, int godinaIzdanja,
                         string* recenzenti, int brojRecenzenata, int brojStranica, int brojIzdanja,
                         string izdavac, string stampa) : Dokument(naziv, kategorija, autori, brojAutora, mjestoIzdanja, brojPrimjeraka, dostupniJezici, brojJezika, dostupnaPisma,
                                                                                          brojPisama, godinaIzdanja)
{
    this->brojRecenzenata = brojRecenzenata;
    this->recenzenti = new string[brojRecenzenata];
    for(int i = 0; i < brojRecenzenata; i++)
    {
        this->recenzenti[i] = recenzenti[i];
    }

    this->brojStranica = brojStranica;
    this->brojIzdanja = brojIzdanja;
    this->izdavac = izdavac;
    this->stampa = stampa;
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

int Knjiga::vratiBrojRecenzenata() const
{
    return brojRecenzenata;
}

string* Knjiga::vratiRecenzente() const
{
    return recenzenti;
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

    cout << "Recenzenti: ";
    for(int i = 0; i < brojRecenzenata; i++)
    {
        cout << recenzenti[i];

        if(i != brojRecenzenata - 1)
        {
            cout << ", ";
        }
    } //end for
    cout << endl;
}


void Knjiga::unosPodataka()
{
    Dokument::unosPodataka();

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Recenzenti(enter prazno za prekid): ";

    string recenzent;
    while(true)
    {
        getline(cin, recenzent);

        if(recenzent != "")
        {
            if(brojRecenzenata == 0)
            {
                recenzenti = new string[brojRecenzenata + 1];
                recenzenti[brojRecenzenata] = recenzent;
                brojRecenzenata++;
            }
            else
            {
                string* pomocniNiz = new string[brojRecenzenata + 1];
                for(int i = 0; i < brojRecenzenata; i++)
                    pomocniNiz[i] = recenzenti[i];

                delete[] recenzenti;
                recenzenti = pomocniNiz;
                recenzenti[brojRecenzenata] = recenzent;
                brojRecenzenata++;
            }//end if-else unutra
        }//end if

        else break; //prekida se petlja kada unese prazan string
    } //end while

    cout << "Izdavac: ";
    getline(cin, izdavac);

    cout << "Stampa: ";
    getline(cin, stampa);

    cout << "Broj izdanja: ";
    cin >> brojIzdanja;

    cout << "Broj stranica: ";
    cin >> brojStranica;
}
