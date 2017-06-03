#include "dokument.h"
#include "knjiga.h"
#include "fajl.h"
#include "datum.h"

using namespace std;

int main()
{
    Knjiga k;
    k.unosPodataka();

    Dokument* k2 = new Knjiga(k);
    k2->ispis();


    return 0;
}
