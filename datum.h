#ifndef DATUM_H
#define DATUM_H

#include <iostream>
#include <string>
using namespace std;

class Datum
{
    public:
        Datum();
        Datum(int godina);
        Datum(int mjesec, int godina);
        Datum(int dan, int mjesec, int godina);

        int vratiDan() const;
        int vratiMjesec() const;
        int vratiGodinu() const;

        void postaviDan(int dan);
        void postaviMjesec(int mjesec);
        void postaviGodinu(int godina);

        friend const Datum operator+(const Datum& lijevi, int dani);
        bool jePrestupnaGodina() const;

        void ispis() const;

    private:
        int dan;
        int mjesec;
        int godina;

//        bool jeTacanDan(int dan);
};

#endif // DATUM_H
