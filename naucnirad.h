#ifndef NAUCNIRAD_H
#define NAUCNIRAD_H

#include "knjiga.h"

class NaucniRad : public Knjiga
{
public:
    NaucniRad();
    NaucniRad(string naziv, string kategorija, string* autori, int brojAutora,
                         string mjestoIzdanja, string* dostupniJezici,
                         int brojJezika, int godinaIzdanja,
                         int brojStranica, int brojIzdanja, string izdavac, string stampa, string mentor, string oblast);

    NaucniRad(const NaucniRad& nr);

        //getteri
    string vratiMentora() const;
    string vratiOblast() const;

    void unosPodataka();
    void ispis() const;

    NaucniRad& operator=(const NaucniRad& nr);
protected:
    string mentor;
    string oblast;

};

#endif // NAUCNIRAD_H
