#ifndef FAJL_H
#define FAJL_H

#include "dokument.h"


class Fajl : public Dokument
{
public:
    Fajl();
    Fajl(string naziv, string kategorija, string* autori, int brojAutora,
                         string mjestoIzdanja, int brojPrimjeraka, string* dostupniJezici,
                         int brojJezika, int godinaIzdanja,
                         double velicina, string tip, string verzija);
    Fajl(const Fajl& f);

    double vratiVelicinu() const;
    string vratiTip() const;
    string vratiVerziju() const;

    void ispis() const;
    void unosPodataka();

    Fajl& operator=(const Fajl& f);

protected:
    double velicina; //velicina fajla
    string tip;
    string verzija;
};

#endif // FAJL_H
