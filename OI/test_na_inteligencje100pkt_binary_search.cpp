#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, k = 0, wczytana_liczba = 0, akt_idx = 0;
vector<vector<int>> stat;
vector<int> zapytania;

inline bool przetwarzaj()
{
    cin >> k;
    zapytania.clear();
    for (int i = 0; i < k; ++i)
    {
        cin >> wczytana_liczba;
        zapytania.push_back(wczytana_liczba);
    }
    akt_idx = 0;
    for (int i = 0; i < k; ++i)
    {
        // Szukamy pierwszego >=
        if (stat[zapytania[i]].size() == 0)
            return false;
        int poczatek = -1, koniec = stat[zapytania[i]].size(), srodek = 0;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (stat[zapytania[i]][srodek] >= akt_idx)
                koniec = srodek;
            else
                poczatek = srodek;
        }
        if (koniec == stat[zapytania[i]].size())
            return false;
        akt_idx = stat[zapytania[i]][koniec] + 1;
    }
    return true;
}

int main()
{
    // binary search
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    stat.assign(1e6+1,{});
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        stat[wczytana_liczba].push_back(i);
    }
    cin >> m;
    while(m--)
    {
        if (przetwarzaj() == true)
            cout << "TAK" << '\n';
        else
            cout << "NIE" << '\n';
    }
    return 0;
}