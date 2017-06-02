#include "datum.h"

    //konstruktori
Datum::Datum()
{
    dan = 1;
    mjesec = 1;
    godina = 1970;
}


Datum::Datum(int godina) : dan(0), mjesec(0)
{
    this->godina = godina;
}


    //throwat ce exception
Datum::Datum(int mjesec, int godina) : dan(0)
{
    this->mjesec = mjesec;
    this->godina = godina;
}

    //throwat ce exception
Datum::Datum(int dan, int mjesec, int godina)
{
    this->dan = dan;
    this->mjesec = mjesec;
    this->godina = godina;
}


    //getteri
int Datum::vratiDan() const
{
    return dan;
}

int Datum::vratiMjesec() const
{
    return mjesec;
}

int Datum::vratiGodinu() const
{
    return godina;
}


    //setteri
void Datum::postaviDan(int dan)
{
    this->dan = dan;
}


void Datum::postaviMjesec(int mjesec)
{
    this->mjesec = mjesec;
}


void Datum::postaviGodinu(int godina)
{
    this->godina = godina;
}


    //ispis datuma u formati 1. Januar, 1970. god.
void Datum::ispis() const
{
    if(dan != 0)
        cout << dan << ". ";

    switch(mjesec)
    {
    case 0:
        cout << ""; break;
    case 1:
        cout << "Januar"; break;
    case 2:
        cout << "Februar"; break;
    case 3:
        cout << "Mart"; break;
    case 4:
        cout << "April"; break;
    case 5:
        cout << "Maj"; break;
    case 6:
        cout << "Juni"; break;
    case 7:
        cout << "Juli"; break;
    case 8:
        cout << "August"; break;
    case 9:
        cout << "Septembar"; break;
    case 10:
        cout << "Oktobar"; break;
    case 11:
        cout << "Novembar"; break;
    default:
        cout << "Decembar"; break;
    }

    if(mjesec != 0)
        cout << ", ";
    cout << godina << ". god." << endl;
}


const Datum operator+(const Datum& lijevi, int dani)
{
    int dan = lijevi.dan + dani;
    int mjesec = lijevi.mjesec;
    int godina = lijevi.godina;

        //sada gledamo kako nam se ponasaju dodaci dana
    switch(lijevi.mjesec)
    {
    case 1:
        if(dan > 31)
        {
            dan -= 31;
            mjesec++;
        }
        break;

    case 2:
        if(dan > 29 && lijevi.jePrestupnaGodina())
        {
            dan -= 29;
            mjesec++;
        }

        else if(dan > 28)
        {
            dan -= 28;
            mjesec++;
        }
        break;

    case 3:
        if(dan > 31)
        {
            dan -= 31;
            mjesec++;
        }
        break;

    case 4:
        if(dan > 30)
        {
            dan -= 30;
            mjesec++;
        }
        break;

    case 5:
        if(dan > 31)
        {
            dan -= 31;
            mjesec++;
        }
        break;

    case 6:
        if(dan > 30)
        {
            dan -= 30;
            mjesec++;
        }
        break;

    case 7:
        if(dan > 31)
        {
            dan -= 31;
            mjesec++;
        }
        break;

    case 8:
        if(dan > 31)
        {
            dan -= 31;
            mjesec++;
        }
        break;

    case 9:
        if(dan > 30)
        {
            dan -= 30;
            mjesec++;
        }
        break;

    case 10:
        if(dan > 31)
        {
            dan -= 31;
            mjesec++;
        }
        break;

    case 11:
        if(dan > 30)
        {
            dan -= 30;
            mjesec++;
        }
        break;

    case 12:
        if(dan > 31)
        {
            dan -= 31;
            mjesec = 1;
            godina++;
        }
        break;
    }//end switch


    return Datum(dan, mjesec, godina);
}


bool Datum::jePrestupnaGodina() const
{
    if((this->godina % 4 == 0 && this->godina % 100 != 0) || this->godina % 400 == 0)
    {
        return true;
    }

    return false;
}

    //funkcija provjere tacnosti dana
//bool Datum::jeTacanDan(int dan) const
//{
//    if(dan > 31) return false;
//
//    switch(this->mjesec)
//    {
//    case 1:
//        if(dan > 31 || dan < 1) return false;
//        break;
//    case 2:
//        if(this->jePrijestupnaGodina())
//    }
//}
