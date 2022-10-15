#include <iostream>
#include <cstdio>
#include <limits>

using namespace std;

struct max_licznik
{
    int powtorzenia;
    int idx_wartosci;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    int przeskok = 0;
    int wartosc_wczytanej = 0;
    int zamiana_int = 0;
    int rozmiary [27] = { };
    int licznik_char = 1;
    char znaki [27];
    char zamiana;
    char z_wczytana;
    //string ciag;
    max_licznik licznik_max;
    licznik_max.powtorzenia = 0;

    cin >> n >> zamiana;

    char ciag[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> z_wczytana;
        ciag[i] = z_wczytana;
        rozmiary[ciag[i]-64]++;
    }

    wartosc_wczytanej = int(zamiana)-64;

    for (int i = 1; i <= 26; ++i)
    {
        if (rozmiary[i] > licznik_max.powtorzenia)
        {
            licznik_max.powtorzenia = rozmiary[i];
            licznik_max.idx_wartosci = i;
        }
        znaki[i] = licznik_char+64;
        licznik_char++;
    }

    if (licznik_max.idx_wartosci < wartosc_wczytanej)
    {
        przeskok = wartosc_wczytanej - licznik_max.idx_wartosci;
    }
    else
    {
        przeskok = 26 - licznik_max.idx_wartosci + wartosc_wczytanej;
    }

    for (int i = 0; i < n; ++i)
    {
        wartosc_wczytanej = ciag[i]-64 + przeskok;
        if (wartosc_wczytanej % 26 == 0)
        {
            printf("Z");
        }

        else
        {
            zamiana_int = (wartosc_wczytanej % 26);
            printf("%c",znaki[zamiana_int]);
        }
    }
    return 0;
}