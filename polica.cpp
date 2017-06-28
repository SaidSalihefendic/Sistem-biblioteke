#include "polica.h"

int Polica::PID = 0;

///*************************************************************************************************************

Polica::Polica() //Standard - kapacitet 10
{
    oznaka = "A";
    kapacitet = 10;
    dokumenti = new Dokument*[kapacitet];
    jePrisutan = new bool[kapacitet];
    brojKnjiga = 0;
    id = PID++;

        //da se zna da li su knjige uzete ili nisu
    for(int i = 0; i < kapacitet; i++)
        jePrisutan[i] = true;

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
void Polica::dodajDokument(Dokument* d) //treba pogledati zasto ne zeli const da primi, da li operator & ne garantuje promjenu
{
    if(brojKnjiga != kapacitet)
        dokumenti[brojKnjiga++] = d;
}

    //da vrati koliko je jos moguce knjiga staviti na policu
int Polica::vratiBrojKnjiga() const
{
    return brojKnjiga;
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

        if(jePrisutan[i])
            cout << "Stanje: dostupno" << endl;
        else
            cout << "Stanje: nedostupno" << endl;
    }

    cout << "--------------------------------" << endl;
} //end ispis

///*************************************************************************************************************

void Polica::dodajDokument() throw (char)
{
    if(brojKnjiga != kapacitet){
        cout << "Koji je tip dokumenta?" << endl;
        cout << "1. Knjiga" << endl;
        cout << "2. Fajl" << endl;
        cout << "3. Naucni rad" << endl;
        cout << endl;
        int odluka;
        cout << "Unos (-1 za izlaz): ";

        do
        {
            cin >> odluka;
            if(odluka == -1) return;

        }while(odluka <= 0 || odluka > 3);


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
    else throw 't'; //baca izuzetak ukoliko je puna polica
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

 Dokument* Polica::uzmiDokument(int index) throw (char)
 {
     if(index < 0 || index >= brojKnjiga) throw 'c';
     else if(!jePrisutan[index]) throw 'd'; //ukoliko je vec zauzeta knjiga

     jePrisutan[index] = false; //uzeli smo sada ovu knjigu

     return dokumenti[index]; //vracamo pokazivac na dokument
 }

 ///*************************************************************************************************************

 void Polica::vratiKnjigu(Dokument* d) //vracamo sada knjigu na policu
 {
     for(int i = 0; i < brojKnjiga; i++)
     {
         if(d == dokumenti[i])
            jePrisutan[i] = true;
     }
 }

 ///*************************************************************************************************************

 string Polica::vratiOznaku() const
 {
    string a = "";

    a += this->oznaka;
    int pom = id;


    if(pom == 0)
    {
        a += (char)(pom + '0');
        return a;
    }
    string stringpom = "";
    //uzimamo cifre iz pomocne varijable i stavljamo u string (moglo je i sa sstream)
    while(pom > 0)
    {
        stringpom = (char)(pom % 10 + (int)('0')) + stringpom;
        pom /= 10;
    }//end while

    a += stringpom;

    return a;
 }

 ///*************************************************************************************************************
