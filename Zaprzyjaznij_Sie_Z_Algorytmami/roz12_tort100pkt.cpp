#include <iostream>
#include <algorithm>

using namespace std;

long long cnt (long long k, long long boki_x[], long long boki_y[], long long rozmiar_tortu) // Zwraca nam ile jest elementow o polu nie mniejszych niz k.
{
    long long wynik = 0;
    long long wskaznik_i = 0;
    for (int i = rozmiar_tortu - 1; i >= 0; --i)
    {
        for (int j = wskaznik_i; j < rozmiar_tortu; ++j)
        {
            if (boki_x[j] * boki_y[i] >= k)
            {
                wynik += rozmiar_tortu - j;
                wskaznik_i = j;
                break;
            }
            if (j == rozmiar_tortu - 1)
            {
                return wynik;
            }
        }
    }
    return wynik;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long szerokosc_tortu = 0;
    long long wysokosc_tortu = 0;
    long long liczba_ciec = 0;
    long long szukany_kawalek = 0;
    long long wczytane_ciecie = 0;
    long long wskaznik_poprzedni = 0;

    cin >> szerokosc_tortu >> wysokosc_tortu >> liczba_ciec >> szukany_kawalek;

    long long boki_x[liczba_ciec+1];
    long long boki_y[liczba_ciec+1];

    for (int i = 0; i < liczba_ciec; ++i) // Ciecia x
    {
        cin >> wczytane_ciecie;
        boki_x[i] = wczytane_ciecie - wskaznik_poprzedni;
        wskaznik_poprzedni = wczytane_ciecie;
    }
    boki_x[liczba_ciec] = szerokosc_tortu - wskaznik_poprzedni;

    wskaznik_poprzedni = 0;
    for (int i = 0; i < liczba_ciec; ++i) // Ciecia y
    {
        cin >> wczytane_ciecie;
        boki_y[i] = wczytane_ciecie - wskaznik_poprzedni;
        wskaznik_poprzedni = wczytane_ciecie;
    }
    boki_y[liczba_ciec] = wysokosc_tortu - wskaznik_poprzedni;


    sort(boki_x,(boki_x+liczba_ciec+1));
    sort(boki_y,(boki_y+liczba_ciec+1));

    long long poczatek = 0;
    long long koniec = boki_x[liczba_ciec] * boki_y[liczba_ciec] + 1;
    long long srodek = 0;

    while (koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (cnt(srodek,boki_x,boki_y,liczba_ciec+1) >= szukany_kawalek)
        {
            poczatek = srodek;
        }
        else
        {
            koniec = srodek;
        }
    }

    cout << poczatek;


    return 0;
}