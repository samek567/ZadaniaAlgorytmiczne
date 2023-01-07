#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, wczytana_liczba = 0, poczatek = 0, koniec = 0, srodek = 0;
vector<int> liczby;

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
    sort(liczby.begin(),liczby.end());

    for (int i = 0; i < n; ++i)
    {
        poczatek = i, koniec = n;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (liczby[srodek] > liczby[i] * 2)
                koniec = srodek;
            else
                poczatek = srodek;
        }
        if (poczatek > i && liczby[poczatek] == liczby[i] * 2)
        {
            printf("TAK");
            return 0;
        }
    }
    printf("NIE");
    return 0;
}