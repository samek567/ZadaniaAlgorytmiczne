#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Drzewo
{
    long long wzrost;
    long long odleglosc;
};

struct Odtwarzanie
{
    bool czy_bierzemy;
    long long idx_poprzedniej;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n = 0;
    long long d = 0;
    long long aktualna_liczba = 0;
    long long suma = 0;
    long long opcja1 = 0;
    long long opcja2 = 0;
    long long poczatek = 0;
    long long srodek = 0;
    long long koniec = 0;
    long long szukana = 0;
    long long aktualny_wskaznik = 0;

    vector<Drzewo> drzewa;
    vector<int> numery_zostawionych;

    cin >> n >> d;

    long long w[n]; // Maksymalna wysokosc jaka mozemy zostawic bioroc pod uwage jedynie pierwsze i drzew.
    Odtwarzanie odtwarzanie[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> aktualna_liczba;
        drzewa.push_back({0,aktualna_liczba});
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> aktualna_liczba;
        drzewa[i].wzrost = aktualna_liczba;
        suma += aktualna_liczba;
    }

    w[0] = drzewa[0].wzrost;

    odtwarzanie[0].czy_bierzemy = true;
    odtwarzanie[0].idx_poprzedniej = -1;

    for (int i = 1; i < n; ++i)
    {
        opcja1 = w[i-1]; // Nie bierzemy
        opcja2 = drzewa[i].wzrost; // Bierzemy

        poczatek = -1;
        koniec = i;
        srodek = 0;
        szukana = drzewa[i].odleglosc - d;

        while (koniec - poczatek != 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (drzewa[srodek].odleglosc <= szukana)
            {
                poczatek = srodek;
            }
            else
            {
                koniec = srodek;
            }
        }
        if (poczatek != -1) // Znalezlismy dodajemy.
        {
            opcja2 += w[poczatek];
        }

        //w[i] = max(opcja1,opcja2);
        if (opcja1 > opcja2)
        {
            w[i] = opcja1;
            odtwarzanie[i].czy_bierzemy = false;
        }
        else
        {
            w[i] = opcja2;
            odtwarzanie[i].czy_bierzemy = true;
            // Musimy sprawdzic czy znalezlismy.
            if (poczatek != -1)
            {
                odtwarzanie[i].idx_poprzedniej = poczatek;
            }
            else
            {
                odtwarzanie[i].idx_poprzedniej = -2; // -2 oznacza ze konczymy sprawdzac.
            }
        }
    }

    for (int i = n-1; i >= 0; --i)
    {
        if (odtwarzanie[i].czy_bierzemy == false)
        {
            continue;
        }
        numery_zostawionych.push_back(i+1);
        if(odtwarzanie[i].idx_poprzedniej == -1 || odtwarzanie[i].idx_poprzedniej == -2 )
        {
            break;
        }
        i = odtwarzanie[i].idx_poprzedniej;
        i++; // Dlatego ze w petli for jest i--, a my skaczemy do ustalonego innego i.
    }

    sort(numery_zostawionych.begin(),numery_zostawionych.end());

    printf("%lld \n",(suma - w[n-1]));
    printf("%lld \n",(n-numery_zostawionych.size()));

    for (int i = 1; i <= n; ++i)
    {
        if (i == numery_zostawionych[aktualny_wskaznik])
        {
            aktualny_wskaznik++;
        }
        else
        {
            printf("%lld ",i);
        }
    }

    return 0;
}