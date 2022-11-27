#include <iostream>

using namespace std;

struct Produkt
{
    long long wartosc;
    long long waga;
};

int main()
{
    // Challange 2 dynamiki.
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0, b = 0, suma = 0;
    long long max_wynik = 0;

    cin >> n >> b;

    Produkt produkty[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> produkty[i].waga;
        suma += produkty[i].waga;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> produkty[i].wartosc;
    }

    long long statystyki[suma+1];
    for (int i = 0; i <= suma; ++i)
    {
        statystyki[i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = suma; j >= 1; --j)
        {
            if (statystyki[j] != 0)
            {
                if (j + produkty[i].waga <= suma)
                {
                    statystyki[j+produkty[i].waga] = max(statystyki[j+produkty[i].waga],statystyki[j]+produkty[i].wartosc);
                }
            }
        }
        statystyki[produkty[i].waga] = max(statystyki[produkty[i].waga],produkty[i].wartosc);
    }

    for (int i = 1; i <= suma; ++i)
    {
        if (i <= b)
        {
            max_wynik = max(max_wynik,statystyki[i]);
        }
    }
    cout << max_wynik;
    return 0;
}