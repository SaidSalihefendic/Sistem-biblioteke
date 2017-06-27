#include "polica.h"

int Polica::PID = 0;

///*************************************************************************************************************

Polica::Polica() //Standard - kapacitet 10
{
    oznaka = "A";
    kapacitet = 10;
    dokumenti = new Dokument*[kapacitet];
    brojKnjiga = 0;
    id = PID++;
}//end constructor

///*************************************************************************************************************

Polica::Polica(string oznaka, int kapacitet)
{
    this->oznaka = oznaka;
    this->kapacitet = kapacitet;
    dokumenti = new Dokument*[kapacitet];

    brojKnjiga = 0;
    id = PID++;
} //end constructor

///*************************************************************************************************************

Polica::Polica(const Polica& p)
{
    this->oznaka = p.oznaka;
    this->kapacitet = p.kapacitet;
    brojKnjiga = p.brojKnjiga;

    dokumenti = new Dokument*[kapacitet];

        //treba naci nacin kako da se izbjegne dijeljenje objekta
    for(int i = 0; i < brojKnjiga; i++)
    {
        dokumenti[i] = p.dokumenti[i]; //nije ovo ispravno, jer su ovo u pitanju pokazivaci
    } //end for

    id = p.id;
} //end copy constructor

///*************************************************************************************************************

Polica::~Polica()
{
//    cout << "Destruktor pozvan" << endl;

    for(int i = 0; i < brojKnjiga; i++)
    {
        delete dokumenti[i];
    }

    delete [] dokumenti;
} //end destruktor

///*************************************************************************************************************

    //funkcija koja ce dodavati dokument u niz dokumenti, ukoliko je kapacitet pun, ne ubacuje knjigu i ignorise zahtjev
void Polica::dodajDokument(Dokument& d) //treba pogledati zasto ne zeli const da primi, da li operator & ne garantuje promjenu
{
    if(brojKnjiga != kapacitet)
        dokumenti[brojKnjiga++] = &d;
}

    //da vrati koliko je jos moguce knjiga staviti na policu
int Polica::vratiProstor() const
{
    return kapacitet - brojKnjiga;
}

///*************************************************************************************************************

Polica& Polica::operator =(const Polica& p)
{
    if(this == &p) return *this;

        //oslobadjamo memoriju od stare police
    for(int i = 0; i < brojKnjiga; i++)
    {
        delete dokumenti[i]; //brisemo pokazivac koji pokazuje na taj objekat
    }

    if(brojKnjiga != 0)
        delete [] dokumenti;

    this->oznaka = p.oznaka;
    this->kapacitet = p.kapacitet;
    brojKnjiga = p.brojKnjiga;

    dokumenti = new Dokument*[kapacitet];

        //treba naci nacin kako da se izbjegne dijeljenje objekta
    for(int i = 0; i < brojKnjiga; i++)
    {
        dokumenti[i] = p.dokumenti[i]; //nije ovo ispravno, jer su ovo u pitanju pokazivaci
    } //end for

    return *this;
} //end operator =

///*************************************************************************************************************

void Polica::ispis() const
{
    cout << "Polica " << this->oznaka << this->id << endl << endl;
    for(int i = 0; i < brojKnjiga; i++)
    {
        cout << i + 1<< "." << endl << "--------------------------------" << endl;
        dokumenti[i]->ispis();
        cout << endl;
    }

    cout << "--------------------------------" << endl;
} //end ispis

///*************************************************************************************************************

void Polica::dodajDokument()
{
    if(brojKnjiga != kapacitet){
        cout << "Koji je tip dokumenta?" << endl;
        cout << "1. Knjiga" << endl;
        cout << "2. Fajl" << endl;
        cout << "3. Naucni rad" << endl;
        cout << endl;
        int odluka;
        cout << "Unos: ";
        cin >> odluka;


        switch(odluka)
        {
        case 1:
            dokumenti[brojKnjiga++] = new Knjiga(); break;
        case 2:
            dokumenti[brojKnjiga++] = new Fajl(); break;
        case 3:
            dokumenti[brojKnjiga++] = new NaucniRad(); break;
        }//end switch

        dokumenti[brojKnjiga - 1]->unosPodataka();
        cout << "--------------------------------------------------------------------------" << endl;
    }//end if
}//end dodajDokument

///*************************************************************************************************************

Dokument* Polica::operator[](int index) throw (char)
 {
    if(index >= brojKnjiga || index < 0) throw 'a';

    return dokumenti[index];
 } //end [] operator

 ///*************************************************************************************************************
    //vraca pokazivac na dokument koji mi zelimo da uzmemo iz police, a polica se azurira i smanjuje broj knjiga za 1
 Dokument* Polica::izbaciDokument(int index) throw (char)
 {
    if(index >= brojKnjiga || index < 0) throw 'b';

    Dokument* pom = dokumenti[index];

    //sada prebacujemo sve knjige za poziciju manje
    for(int i = index; i < brojKnjiga - 1; i++)
    {
        dokumenti[i] = dokumenti[i + 1];
    }
    brojKnjiga--;

    return pom;
 } //end izbaciDokument

 ///*************************************************************************************************************
