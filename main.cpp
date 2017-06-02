#include "dokument.h"
#include "knjiga.h"
#include "datum.h"

using namespace std;

int main()
{
        //Test konstruktora
    int N = 2;
    string* autori = new string[N];
    autori[0] = "Esmir Pilav";
    autori[1] = "Senada Kalabusic";

    string* jezici = new string[3];
    jezici[0] = "bosanski";
    jezici[1] = "engleski";
    jezici[2] = "njemacki";

    string* pisma = new string[2];
    pisma[0] = "latinica";
    pisma[1] = "cirilica";

    Dokument d("Obicne diferencijalne jednacine", "udzbenik", autori, N,
                        "Sarajevo", 50, jezici, 3, pisma, 2, 2012);
    d.ispis();
    cout << endl;

        //test barkoda
    Dokument d2("Specijalne diferencijalne jednacine", "udzbenik", autori, N,
                        "Beograd", 50, jezici, 3, pisma, 2, 2013);
    d2.ispis();

    cout << endl;

        //test rada sa pokazivacima kroz projekat
    Dokument* k = new Knjiga();
    k->unosPodataka();
    cout << endl;

    k->ispis();

    return 0;
}
