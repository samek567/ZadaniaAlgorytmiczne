#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, poczatek = 0, koniec = 0, srodek = 0;
vector<int> liczby;

inline bool czy_pasuje(int x)
{
    int ile = 1, ile_ulozylismy = 0;
    for (int i = 0; i < n; ++i)
    {
        if (liczby[i] > x)
            return false;
        else if (ile_ulozylismy + liczby[i] <= x)
            ile_ulozylismy += liczby[i];
        else
        {
            ile++;
            ile_ulozylismy = liczby[i];
        }
    }
    if (ile <= x)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    poczatek = 0, koniec = 1e9+5;
    while(koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (czy_pasuje(srodek) == true)
            koniec = srodek;
        else
            poczatek = srodek;
    }

    cout << koniec << '\n';

    return 0;
}