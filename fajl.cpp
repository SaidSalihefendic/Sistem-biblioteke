#include "fajl.h"
#include <limits>

///-------------------------------------------------------------------------------------------------------------------------------------------------------------------

Fajl::Fajl() : Dokument() {}

///-------------------------------------------------------------------------------------------------------------------------------------------------------------------


Fajl::Fajl(string naziv, string kategorija, string* autori, int brojAutora,
                         string mjestoIzdanja, int brojPrimjeraka, string* dostupniJezici,
                         int brojJezika, string* dostupnaPisma, int brojPisama, int godinaIzdanja,
                         double velicina, string tip, string verzija) : Dokument(naziv, kategorija, autori, brojAutora, mjestoIzdanja, brojPrimjeraka, dostupniJezici, brojJezika, dostupnaPisma,
                                                                                                        brojPisama, godinaIzdanja)
{
    this->velicina = velicina;
    this->tip = tip;
    this->verzija = verzija;
}

///-------------------------------------------------------------------------------------------------------------------------------------------------------------------


Fajl::Fajl(const Fajl& f) : Dokument(f)
{
    velicina = f.velicina;
    tip = f.tip;
    verzija = f.verzija;
}

///-------------------------------------------------------------------------------------------------------------------------------------------------------------------

double Fajl::vratiVelicinu() const
{
    return velicina;
}

string Fajl::vratiTip() const
{
    return tip;
}

string Fajl::vratiVerziju() const
{
    return verzija;
}


///-------------------------------------------------------------------------------------------------------------------------------------------------------------------


void Fajl::unosPodataka()
{
    Dokument::unosPodataka();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //da ne dodje do situacije gdje ce se izgubiti mogucnost unosa zbog \n i getline

    cout << "Verzija: ";
    getline(cin, verzija);

    cout << "Tip: ";
    getline(cin, tip);

    cout << "Velicina (u MB): ";
    cin >> velicina;
}

///-------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Fajl::ispis() const
{
    Dokument::ispis();

    cout << "Verzija: " << verzija << endl;

    cout << "Tip: ." << tip << endl;

    cout << "Velicina: " << velicina << "MB" << endl;
}

///-------------------------------------------------------------------------------------------------------------------------------------------------------------------

Fajl& Fajl::operator=(const Fajl& f)
{
    if(this == &f) return *this;

    Dokument::operator=(f);
    velicina = f.velicina;
    tip = f.tip;
    verzija = f.verzija;

    return *this;
}
