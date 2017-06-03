#include "dokument.h"

int Dokument::jedinstveniBarkod = 0;


    //defaultni konstruktor ce nam posluziti da samo napravimo objekt, zavisit ce od inputa (ovo su za konzolne svrhe)
Dokument::Dokument() : brojAutora(0), brojJezika(0), brojPisama(0)
{
    barkod = jedinstveniBarkod++;
}

//--------------------------------------------------------------------------------------------------

//  konstruktor koji konstruise osnovne informacije svakog dokumenta, nebitno da li je pitanje o knjizi, enciklopediji, eknjizi i slicno (GUI svrha)
Dokument::Dokument(string naziv, string kategorija, string* autori, int brojAutora,
                                    string mjestoIzdanja, int brojPrimjeraka, string* dostupniJezici,
                                    int brojJezika, string* dostupnaPisma, int brojPisama, int godinaIzdanja)
{
    this->naziv = naziv;
    this->kategorija = kategorija;

        //ovdje se radi o dinamickom nizu, tj. pokazivacu na niz zbog uzimanja podataka iz fajlova
    this->brojAutora = brojAutora;
    this->autori = new string[brojAutora];
    for(int i = 0; i < brojAutora; i++)
    {
        this->autori[i] = autori[i];
    }

    this->mjestoIzdanja = mjestoIzdanja;
    this->brojPrimjeraka = brojPrimjeraka;

        //ovdje se radi o dinamickom nizu, tj. pokazivacu na niz zbog uzimanja podataka iz fajlova
    this->brojJezika = brojJezika;
    this->dostupniJezici = new string[brojJezika];
    for(int i = 0; i < brojJezika; i++)
    {
        this->dostupniJezici[i] = dostupniJezici[i];
    }

        //ovdje se radi o dinamickom nizu, tj. pokazivacu na niz zbog uzimanja podataka iz fajlova
    this->brojPisama = brojPisama;
    this->dostupnaPisma = new string[brojPisama];
    for(int i = 0; i < brojPisama; i++)
    {
        this->dostupnaPisma[i] = dostupnaPisma[i];
    }

    this->barkod = jedinstveniBarkod++;
    this->godinaIzdanja = godinaIzdanja;
}

//--------------------------------------------------------------------------------------------------

Dokument::Dokument(const Dokument& d)
{
    /*string naziv, string kategorija, string* autori, int brojAutora,
                                    string mjestoIzdanja, int brojPrimjeraka, string* dostupniJezici,
                                    int brojJezika, string* dostupnaPisma, int brojPisama, int godinaIzdanja*/
    naziv = d.naziv;
    kategorija = d.kategorija;
    brojAutora = d.brojAutora;

    if(brojAutora > 0)
    {
        autori = new string[brojAutora];

        for(int i = 0; i < brojAutora; i++)
        {
            autori[i] = d.autori[i];
        }
    }


    mjestoIzdanja = d.mjestoIzdanja;
    brojPrimjeraka = d.brojPrimjeraka;

    brojJezika = d.brojJezika;

    if(brojJezika > 0)
    {
        dostupniJezici = new string[brojJezika];

        for(int i = 0; i < brojJezika; i++)
        {
            dostupniJezici[i] = d.dostupniJezici[i];
        }
    }


    brojPisama = d.brojPisama;

    if(brojPisama > 0)
    {
        dostupnaPisma = new string[brojPisama];

        for(int i = 0; i < brojPisama; i++)
        {
            dostupnaPisma[i] = d.dostupnaPisma[i];
        }
    }

    godinaIzdanja = d.godinaIzdanja;
    barkod = jedinstveniBarkod++;
}

//--------------------------------------------------------------------------------------------------

    //destruktor
Dokument::~Dokument()
{
    if(brojAutora != 0)
        delete[] autori;
    if(brojPisama != 0)
        delete[] dostupnaPisma;

    if(brojJezika != 0)
        delete[] dostupniJezici;
}

//--------------------------------------------------------------------------------------------------

    //getteri
 string Dokument::vratiNaziv() const
 {
     return this->naziv;
 }
string Dokument::vratiKategoriju() const
{
    return this->kategorija;
}
string* Dokument::vratiAutore() const
{
    return this->autori;
}    //najvjerovatnije da treba proslijediti parametar neki niz, tako da ne dodje se do konflikta pokazivaca koji pokazuju na istu mem. lokaciju
int Dokument::vratiBrojAutora() const
{
    return this->brojAutora;
}
string Dokument::vratiMjestoIzdanja() const
{
    return this->mjestoIzdanja;
}
int Dokument::vratiBrojPrimjeraka() const
{
    return this->brojPrimjeraka;
}
string* Dokument::vratiDostupneJezike() const
{
    return this->dostupniJezici;
}    //najvjerovatnije da treba proslijediti parametar neki niz, tako da ne dodje se do konflikta pokazivaca koji pokazuju na istu mem. lokaciju
int Dokument::vratiBrojJezika() const
{
    return this->brojJezika;
}
string* Dokument::vratiDostupnaPisma() const
{
    return this->dostupnaPisma;
}    //najvjerovatnije da treba proslijediti parametar neki niz, tako da ne dodje se do konflikta pokazivaca koji pokazuju na istu mem. lokaciju
int Dokument::vratiBrojPisama() const
{
    return this->brojPisama;
}

//--------------------------------------------------------------------------------------------------

    //funkcija konzolnog ispisa
    //Testni ispis na konzoli, provjera rada konstruktora
void Dokument::ispis() const
{
    cout << "Naziv: " << naziv << endl;
    cout << "Kategorija: " << kategorija << endl;

        //ispis autora dokumenta, ako ima
    if(brojAutora > 0)
    {
        cout << "Autori: ";
        for(int i = 0; i < brojAutora; i++)
        {
            cout << autori[i];
            if(i != brojAutora - 1)
                cout << ", ";
        }
        cout << endl;
    }

    cout << "Mjesto izdanja: " << mjestoIzdanja << endl;

        //ispis dostupnih jezika, ako ima
    if(brojJezika > 0)
    {
        cout << "Jezici: ";
        for(int i = 0; i < brojJezika; i++)
        {
            cout << dostupniJezici[i];
            if(i != brojJezika - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }


        //ispis dostupnih pisamam, ako ih ima
    if(brojPisama > 0)
    {
        cout << "Pisma: ";
        for(int i = 0; i < brojPisama; i++)
        {
            cout << dostupnaPisma[i];
            if(i != brojPisama - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }

    cout << "Godina izdanja: " << godinaIzdanja << "." << endl;

    cout << "Barkod: " << barkod << endl;
}

//--------------------------------------------------------------------------------------------------

void Dokument::unosPodataka()
{
   /* string naziv, string kategorija, string zanr, string* autori, int brojAutora,
                                    string mjestoIzdanja, int brojPrimjeraka, string* dostupniJezici,
                                    int brojJezika, string* dostupnaPisma, int brojPisama, int godinaIzdanja*/
    cout << "Naziv: ";
    getline(cin, naziv); //hvatamo citav string


    cout << "Kategorija: ";
    getline(cin, kategorija);


    cout << "Autori (enter prazno za prekid): ";
        //Uzimamo sada autore koliko je potrebno
    string autor;
    while(true)
    {
        getline(cin, autor);


        if(autor != "")
        {
            if(brojAutora == 0)
            {
                autori = new string[brojAutora + 1];
                autori[brojAutora] = autor;
                brojAutora++;
            }
            else
            {
                string* pomocniNiz = new string[brojAutora + 1];
                for(int i = 0; i < brojAutora; i++)
                    pomocniNiz[i] = autori[i];

                delete[] autori;
                autori = pomocniNiz;
                autori[brojAutora] = autor;
                brojAutora++;
            }//end if-else unutra
        }

        else break; //prekida se petlja kada unese prazan string
    } //end while

    cout << "Mjesto izdanja: ";
    getline(cin, mjestoIzdanja);

    cout << "Jezici(enter prazno za prekid): ";
    string jezik;
    while(true)
    {
        getline(cin, jezik);

        if(jezik != "")
        {
            if(brojJezika == 0)
            {
                dostupniJezici = new string[brojJezika + 1];
                dostupniJezici[brojJezika] = jezik;
                brojJezika++;
            }
            else
            {
                string* pomocniNiz = new string[brojJezika + 1];
                for(int i = 0; i < brojJezika; i++)
                    pomocniNiz[i] = dostupniJezici[i];

                delete[] dostupniJezici;
                dostupniJezici = pomocniNiz;
                dostupniJezici[brojJezika] = jezik;
                brojJezika++;
            }//end if-else unutra
        }//end if

        else break; //prekida se petlja kada unese prazan string
    } //end while

    cout << "Pisma(enter prazno za prekid): ";
    string pismo;
    while(true)
    {
        getline(cin, pismo);

        if(pismo != "")
        {
            if(brojPisama == 0)
            {
                dostupnaPisma = new string[brojPisama + 1];
                dostupnaPisma[brojPisama] = pismo;
                brojPisama++;
            }
            else
            {
                string* pomocniNiz = new string[brojPisama + 1];
                for(int i = 0; i < brojPisama; i++)
                    pomocniNiz[i] = dostupnaPisma[i];

                delete[] dostupnaPisma;
                dostupnaPisma = pomocniNiz;
                dostupnaPisma[brojPisama] = pismo;
                brojPisama++;
            }//end if-else unutra
        }//end if

        else break; //prekida se petlja kada unese prazan string
    } //end while

    cout << "Godina izdanja: ";
    cin >> godinaIzdanja;

//    cout << "Broj primjeraka: ";
//    cin >> brojPrimjeraka;
}//end input funkcije

//--------------------------------------------------------------------------------------------------

Dokument& Dokument::operator=(const Dokument& d)
{
    if(this == &d) return *this;

        //brisemo sada nizove
    if(brojAutora != 0)
        delete[] autori;
    if(brojPisama != 0)
        delete[] dostupnaPisma;

    if(brojJezika != 0)
        delete[] dostupniJezici;

    naziv = d.naziv;
    kategorija = d.kategorija;
    brojAutora = d.brojAutora;

    if(brojAutora > 0)
    {
        autori = new string[brojAutora];

        for(int i = 0; i < brojAutora; i++)
        {
            autori[i] = d.autori[i];
        }
    }


    mjestoIzdanja = d.mjestoIzdanja;
    brojPrimjeraka = d.brojPrimjeraka;

    brojJezika = d.brojJezika;

    if(brojJezika > 0)
    {
        dostupniJezici = new string[brojJezika];

        for(int i = 0; i < brojJezika; i++)
        {
            dostupniJezici[i] = d.dostupniJezici[i];
        }
    }


    brojPisama = d.brojPisama;

    if(brojPisama > 0)
    {
        dostupnaPisma = new string[brojPisama];

        for(int i = 0; i < brojPisama; i++)
        {
            dostupnaPisma[i] = d.dostupnaPisma[i];
        }
    }

    godinaIzdanja = d.godinaIzdanja;


    return *this;
}
//--------------------------------------------------------------------------------------------------
