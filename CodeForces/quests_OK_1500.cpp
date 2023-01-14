#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll t = 0, n = 0, c = 0, d = 0, wczytana_liczba = 0, suma = 0, poczatek = 0, koniec = 0, srodek = 0;
vector<ll> liczby;

inline bool czy_sie_da (ll k)
{
    int wsk = 0;
    ll suma_zap = 0;
    for (int i = 0; i < d; ++i)
    {
        if (wsk < n)
            suma_zap += liczby[wsk];
        if (wsk == k)
            wsk = 0;
        else
            wsk++;
    }
    if (suma_zap >= c)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cout.tie(0);

    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> c >> d;
        liczby.clear();
        suma = 0;
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytana_liczba;
            liczby.push_back(wczytana_liczba);
        }
        sort(liczby.begin(),liczby.end(),greater<ll>());
        if (d * liczby[0] < c && d * liczby[0] >= 0)
        {
            printf("Impossible\n");
            continue;
        }
        for (int i = 0; i < min(n,d); ++i)
            suma += liczby[i];
        if (suma >= c)
        {
            printf("Infinity\n");
            continue;
        }
        else
        {
            poczatek = -1;
            koniec = d;
            while(koniec - poczatek > 1)
            {
                srodek = (poczatek + koniec ) / 2;
                if (czy_sie_da(srodek) == true)
                    poczatek = srodek;
                else
                    koniec = srodek;
            }
            printf("%lld\n",poczatek);
        }
    }
    return 0;
}
