#include "biblioteka.h"

using namespace std;

//Overloadati u klasama operator << za ispis (Prvenstveno je bio stil Jave)

int main()
{
    Biblioteka b(10);

    b.meni();

    return 0;
}




/** TESTOVI
-----------------------------------------------------------------------------------------------------------------------------------------------------
    TEST 1: POLICE (proba rada sa anonimnim objektima, dodajDokument(), operator [], izbaciDokument(), izuzeci)
//    Polica pol("proba", 10);
//
//    Dokument* knjiga = new Knjiga();
////    knjiga->unosPodataka();
//    cout << endl;
//
//    pol.dodajDokument(*knjiga);
//    pol.dodajDokument(*(new NaucniRad()));
//    pol.dodajDokument(*(new Fajl()));
//    pol.dodajDokument(*(new NaucniRad()));
//
//    pol.ispis();
//
//    cout << endl;
-----------------------------------------------------------------------------------------------------------------------------------------------------
//    Polica pol("proba", 10);
//
//    for(int i = 0; i < 3; i++)
//    {
//        pol.dodajDokument();
//    }
//
//    pol.ispis();
//
//    cout << endl;
-----------------------------------------------------------------------------------------------------------------------------------------------------
//    Polica pol("proba", 1);
//
//    for(int i = 0; i < 2; i++)
//    {
//        pol.dodajDokument();
//    }
//
//    pol.ispis();
//
//    cout << endl << endl;
//
//    try{
//        pol[3]->ispis();
//    }
//    catch(char)
//    {
//        cout << "Ne moze se pristupiti!" << endl;
//    } //end try-catch
-----------------------------------------------------------------------------------------------------------------------------------------------------
//    Polica pol("proba", 4);
//
//    pol.dodajDokument();
//    for(int i = 0; i < 2; i++)
//    {
//        pol.dodajDokument(*(new Knjiga()));
//    }
//
//    pol.ispis();
//
//    cout << endl << endl;
//
//    Dokument* preuzetiDokument;
//
//    try{
//        preuzetiDokument = pol.izbaciDokument(0);
//
//        pol.ispis();
//
//        preuzetiDokument->ispis();
//    }
//    catch(char)
//    {
//        cout << "Ne moze se pristupiti!" << endl;
//    } //end try-catch
-----------------------------------------------------------------------------------------------------------------------------------------------------
//    Polica pol("proba", 4);
//
////    pol.dodajDokument();
//    for(int i = 0; i < 2; i++)
//    {
//        pol.dodajDokument(*(new Knjiga()));
//    }
//
//    pol.ispis();
//
//    cout << endl << endl;
//
//    Dokument* preuzetiDokument;
//
//    try{
//        preuzetiDokument = pol.izbaciDokument(4);
//
//        pol.ispis();
//
//        preuzetiDokument->ispis();
//    }
//    catch(char)
//    {
//        cout << "Ne moze se pristupiti!" << endl;
//    } //end
/
//    Polica k;
//
//    k.dodajDokument(new Fajl());
//    Dokument* f = k.uzmiDokument(0);
//
//    k.ispis();
//
//    k.vratiKnjigu(f);
//
//    k.ispis();


***********TEST 2: KORISNIK****************
//    Korisnik ja("Said", "Salihefendic");
//    Dokument* k = new Knjiga();
////    k->unosPodataka();
//
////    cout << endl;
////    k->ispis();
//    ja.dodajKnjigu(k);
//    ja.dodajKnjigu(new NaucniRad());
//    ja.dodajKnjigu(new Fajl());
//    ja.dodajKnjigu(new Fajl());
//    ja.dodajKnjigu(new Fajl());
//
//    ja.ispis();

*/
