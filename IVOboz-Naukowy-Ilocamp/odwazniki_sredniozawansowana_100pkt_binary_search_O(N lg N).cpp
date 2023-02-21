#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n = 0, wczytana_liczba = 0, sum = 0;
vector<ll> S;
vector<ll> suma;
vector<ll> odwarzniki;

int main()
{
    // O(N lg N) - wyszukiwanie bianrne. Zeby dalo sie ulozyc na i-tej wysokosci, to musi byc szary odwaznik o wadze 2*czarny_odwarznik[i] oraz inny szary odwarznik o wadze czarne_odwarzniki[i] - suma_wyrzej[i]
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    suma.assign(n,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        odwarzniki.push_back(wczytana_liczba);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        S.push_back(wczytana_liczba);
    }
    sort(S.begin(),S.end());

    for (int i = n-1; i >= 0; --i)
    {
        suma[i] = sum;
        sum += odwarzniki[i];
    }

    for (int i = 0; i < n; ++i)
    {
        int poczatek = -1, koniec = n, srodek = 0;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (S[srodek] <= odwarzniki[i] * 2)
                poczatek = srodek;
            else
                koniec = srodek;
        }
        if (poczatek != -1)
        {
            if (S[poczatek] == odwarzniki[i] * 2)
            {
                poczatek = -1, koniec = n, srodek = 0;
                while (koniec - poczatek > 1)
                {
                    srodek = (poczatek + koniec) / 2;
                    if (S[srodek] <= odwarzniki[i] - suma[i])
                        poczatek = srodek;
                    else
                        koniec = srodek;
                }
                if (poczatek != -1)
                {
                    if (S[poczatek] == odwarzniki[i] - suma[i])
                    {
                        cout << i+1 << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << n << '\n';

    return 0;
}