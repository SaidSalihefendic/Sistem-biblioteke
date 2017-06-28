#include "biblioteka.h"
#include <cstdlib>
#include <limits>
/*********************************************************************************************/

    //Kapacitet polica je namjesteno na 10 knjiga maks, a broj korisnika je 0
Biblioteka::Biblioteka(int brojPolica)
{
    this->brojPolica = brojPolica;
    police = new Polica[brojPolica];
    brojKorisnika = 0;
}

/****************************************   MENI    *****************************************/

    //terminalni meni
void Biblioteka::meni()
{
        //mainloop
    while(true)
    {
        system("cls"); //windows poziv
        cout << "AS Bibliotekarski server" << endl;
        cout << "--------------------------------" << endl << endl;
        cout << "Izaberite opciju: " << endl;
        cout << "1. Dodaj korisnika" << endl;
        cout << "2. Ispis korisnika i njihovih detalja" << endl;
        cout << "3. Ispis polica, dokumenata na tim policama i njihova stanja" << endl;
        cout << "4. Dodaj dokument" << endl;
        cout << "5. Prijava preuzimanje knjige" << endl;
        cout << "6. Vracanje knjige" << endl;
        cout << "7. Provjera knjige na stanju" << endl;

        cout << endl << "/*****************/" << endl << endl;

        cout << "Izbor: ";

        int odluka;
        do
        {
            cin >> odluka;
        } while(odluka <= 0 || odluka > 7);
        cout << endl;

        system("cls"); //da se ocisti prozor na terminalu
        cout << endl << "/*****************/" << endl << endl;

        switch(odluka)
        {
        case 1:
            cout << "Dodaj korisnika" << endl << "'---------------------------" << endl << endl;
            this->dodajKorisnika(); break;
        case 2:
            cout << "Spisak korisnika" << endl << "'---------------------------" << endl << endl;
            this->ispisKorisnika(); break;
        case 3:
            cout << "Spisak polica" << endl << "'---------------------------" << endl << endl;
            this->ispisPolica(); break;
        case 4:
            cout << "Dodaj dokument" << endl << "'---------------------------" << endl << endl;
            this->dodajDokument(); break;
        case 5:
            cout << "Preuzimanje knjige" << endl << "'---------------------------" << endl << endl;
            this->korisnikPreuzima(); break;
        case 6:
            cout << "Vracanje knjige" << endl << "'---------------------------" << endl << endl;
            this->korisnikVraca(); break;
        case 7:
            cout << "Provjera stanja" << endl << "'---------------------------" << endl << endl;
            this->provjeraStanja(); break;
        }//end switch

        cout << endl << "/*****************/" << endl << endl;
        cout << "Zaustaviti program(0) ili nastaviti dalje(1): ";

        do
        {
            cin >> odluka;
        } while(odluka != 0 && odluka != 1);

        if(odluka == 0) //zaustavlja mainloop
            break;
        cout << endl << endl;
    }//end mainloop (while)
}

/*********************************************************************************************/

void Biblioteka::dodajKorisnika()
{
    string ime, prezime;
    cout << "Ime: ";
    cin >> ime;
    cout << "Prezime: ";
    cin >> prezime;

    Korisnik* pom = new Korisnik[brojKorisnika + 1];

    for(int i = 0; i < brojKorisnika; i++)
        pom[i] = korisnici[i];

    pom[brojKorisnika] = *(new Korisnik(ime, prezime)); //pravimo anonimni objekat

        //Provjeravamo da li uopste imamo korisnika na pocetku
    if(brojKorisnika != 0)
        delete [] korisnici;
    brojKorisnika++;

    korisnici = pom;
}

/*********************************************************************************************/

void Biblioteka::ispisKorisnika() const
{
    for(int i = 0; i < brojKorisnika; i++)
    {
        korisnici[i].ispis();
        cout << endl;
    }
}

/*********************************************************************************************/

void Biblioteka::ispisPolica() const
{
    for(int i = 0; i < brojPolica; i++)
    {
        police[i].ispis();
        cout << endl;
    }
}

/*********************************************************************************************/

void Biblioteka::dodajDokument()
{
    cout << "Izaberite policu: " << endl;
    for(int i = 0; i < brojPolica; i++)
    {
        cout << i + 1 << ". " << police[i].vratiOznaku() << endl;
    }
        //Ispisali smo sve oznake police u biblioteci, odaberimo sada koju policu zelimo
    cout << endl << "Izbor: ";
    int odluka;
    do
    {
        cin >> odluka;
    } while(odluka <= 0 || odluka > brojPolica);
    cout << endl << "/*****************/" << endl << endl;

    try
    {
        police[odluka - 1].dodajDokument();
    }catch(char)
    {
        cout << "Polica je trenutno puna" << endl;
    } //end trycatch blok
}

/*********************************************************************************************/

void Biblioteka::korisnikPreuzima()
{
    cout << "Unesite clansku kartu: ";
    int clanska;
    cin >> clanska;

    int pozicijaClana = -1;
        //trazimo clana, pretpostavljamo da ga nema
    for(int i = 0; i < brojKorisnika; i++)
    {
        if(korisnici[i].vratiClansku() == clanska)
            pozicijaClana = i;
    }

        //slucaj ako ga nema
    if(pozicijaClana == -1)
    {
        cout << "Clan ne postoji!" << endl;
        return;
    }

    cout << "Polica gdje se knjiga nalazi: ";
    string oznaka;
    int pozicijaPolice = -1;
    cin >> oznaka;
        //provjerimo da li postoji ta polica, pretpostavljamo da ne postoji
    for(int i = 0; i < brojPolica; i++)
    {
        if(oznaka == police[i].vratiOznaku())
        {
            pozicijaPolice = i;
        }
    }

        //ako ne postoji ta polic/********************************************************************************************************/a
    if(pozicijaPolice == -1)
    {
        cout << "Polica ne postoji!" << endl;
        return;
    }

    cout << "Pozicija: ";
    int pozicijaDokumenta;
    cin >> pozicijaDokumenta;

    if(pozicijaDokumenta - 1 < 0 || pozicijaDokumenta - 1 > police[pozicijaPolice].vratiBrojKnjiga())
    {
        cout << "Nema dokumenta na toj poziciji" << endl;
        return;
    }

    try
    {
        korisnici[pozicijaClana].dodajKnjigu(police[pozicijaPolice].uzmiDokument(pozicijaDokumenta - 1));
    } catch(char)
    {
        cout << "Trenutno ta knjiga na toj poziciji nije dostupna!" << endl;
        return;
    }//end try catch blok
}

/*********************************************************************************************/

void Biblioteka::korisnikVraca()
{
    cout << "Unesite clansku kartu: ";
    int clanska;
    cin >> clanska;

    int pozicijaClana = -1;
        //trazimo clana, pretpostavljamo da ga nema
    for(int i = 0; i < brojKorisnika; i++)
    {
        if(korisnici[i].vratiClansku() == clanska)
            pozicijaClana = i;
    }

        //slucaj ako ga nema
    if(pozicijaClana == -1)
    {
        cout << "Clan ne postoji!" << endl;
        return;
    }

    cout << "Pozicija (knjigu koju zelite vratiti): ";
    int pozicijaDokumenta;
    cin >> pozicijaDokumenta;

    if(pozicijaDokumenta - 1 < 0 || pozicijaDokumenta - 1 > korisnici[pozicijaClana].vratiTrenutniBrojKnjiga()) // - 1 jer zelimo da korisnici koriste od 1 do n, a ne od 0
    {
        cout << "Nema dokumenta na toj poziciji" << endl;
        return;
    }

        //ne treba dodatno provjeravati da li dokument postoji, jer svakako korisnici samo unutar biblioteke mogu uzimati knjige
    for(int i = 0; i < brojPolica; i++)
    {
        police[i].vratiKnjigu(korisnici[pozicijaClana][pozicijaDokumenta]); //za bar jednu policu ce ovo uraditi i morat ce, jer korisnik samo iz neke od polica moze knjige uzeti
    }
    korisnici[pozicijaClana].izbaciKnjigu(pozicijaDokumenta); //izbacujemo iz korisnika takodjer knjigu koju je uzeo i koju je vratio
}

/*********************************************************************************************/

void Biblioteka::provjeraStanja() const
{
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Unesite naziv knjige: ";
    string nazivKnjige("");
    getline(cin, nazivKnjige); //uzimamo naziv knjige

    string oznaka("");
    int pozicija = -1;

    for(int i = 0; i < brojPolica; i++)
    {
//        cout << police[i].vratiOznaku() << endl;
        for(int j = 0; j < police[i].vratiBrojKnjiga(); j++)
        {
//            cout << police[i][j]->vratiNaziv() << endl;
            if(nazivKnjige == police[i][j]->vratiNaziv()) //-> je operator jer se radi o pokazivacu na Dokument (tip Dokument*)
            {
//                cout << "Prosli" << endl;
                oznaka = police[i].vratiOznaku();
                pozicija = j;
            }
        }
    }//end for i petlje

    if(pozicija == -1)
   {
        cout << "Dokument koji trazite ne postoji" << endl; return;
   }
    else
    {
        cout << "Dokument koji trazite se nalazi na polici " << oznaka << ", pozicija " << pozicija << endl;
        return;
    }

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*********************************************************************************************/
