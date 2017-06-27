#include "naucnirad.h"
#include <limits>

///------------------------------------------------------------------------------------------------------------------------

NaucniRad::NaucniRad() : Knjiga() {}

///------------------------------------------------------------------------------------------------------------------------

NaucniRad::NaucniRad(string naziv, string kategorija, string* autori, int brojAutora,
                                 string mjestoIzdanja, string* dostupniJezici,
                                 int brojJezika, int godinaIzdanja,
                                 int brojStranica, int brojIzdanja, string izdavac, string stampa, string mentor, string oblast)
                                     : Knjiga(naziv, kategorija, autori, brojAutora, mjestoIzdanja, dostupniJezici, brojJezika,
                                                  godinaIzdanja, brojStranica, brojIzdanja, izdavac, stampa)
{
    this->mentor = mentor;
    this->oblast = oblast;
}

///------------------------------------------------------------------------------------------------------------------------

NaucniRad::NaucniRad(const NaucniRad& nr) : Knjiga(nr)
{
    this->mentor = nr.mentor;
    this->oblast = nr.oblast;
}

///------------------------------------------------------------------------------------------------------------------------

string NaucniRad::vratiMentora() const
{
    return mentor;
}

string NaucniRad::vratiOblast() const
{
    return oblast;
}

///------------------------------------------------------------------------------------------------------------------------

void NaucniRad::unosPodataka()
{
    Knjiga::unosPodataka();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Mentor: ";
    getline(cin, this->mentor);

    cout << "Oblast: ";
    getline(cin, this->oblast);
}

///------------------------------------------------------------------------------------------------------------------------

void NaucniRad::ispis() const
{
    Knjiga::ispis();

    cout << "Oblast: " << oblast << endl;
    cout << "Mentor: " << mentor << endl;
}

///------------------------------------------------------------------------------------------------------------------------


NaucniRad& NaucniRad::operator=(const NaucniRad& nr)
{
    if(&nr == this) return *this;

    Knjiga::operator=(nr);

    mentor = nr.mentor;
    oblast = nr.oblast;

    return *this;
}

