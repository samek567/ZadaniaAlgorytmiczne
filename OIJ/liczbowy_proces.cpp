#include <iostream>
#include <vector>

using namespace std;

unsigned long long suma_cyfr (unsigned long long liczba)
{
    unsigned long long suma = 0;
    while (liczba > 0)
    {
        suma += liczba % 10;
        liczba /= 10;
    }
    return suma;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    unsigned long long szukana_liczba = 0;

    vector<unsigned long long> f_g;

    f_g.push_back(1);

    for (int i = 0; i < 3000000; i++)
    {
        f_g.push_back(f_g[i] + (suma_cyfr(f_g[i]) * suma_cyfr(f_g[i])));
    }

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> szukana_liczba;

        long long poczatek = -1;
        long long koniec = 3000001;
        long long srodek = 0;

        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;

            if (f_g[srodek] >= szukana_liczba)
            {
                koniec = srodek;
            }
            else
            {
                poczatek = srodek;
            }
        }

        if (f_g[koniec] == szukana_liczba)
        {
            printf("TAK \n");
        }
        else
        {
            printf("NIE \n");
        }
    }
    return 0;
}