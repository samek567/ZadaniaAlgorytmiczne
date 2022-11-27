#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, licznik_kulek = 0, wskaznik_kulka = 0;
long long wczytana_liczba = 0, max_szerokosc = 10000000000000000;
vector<long long> krazki;
vector<long long> max_przejdzie;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        max_szerokosc = min(max_szerokosc,wczytana_liczba);
        max_przejdzie.push_back(max_szerokosc);
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> wczytana_liczba;
        krazki.push_back(wczytana_liczba);
    }

    for (int i = n-1; i >= 0; --i)
    {
        if (krazki[wskaznik_kulka] <= max_przejdzie[i])
        {
            licznik_kulek++;
            if (licznik_kulek == m)
            {
                cout << i+1;
                return 0;
            }
            wskaznik_kulka++;
        }
    }

    cout << "0";

    return 0;
}