#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll n = 0, k = 0, wczytana_liczba = 0, wyn = 0, poczatek = 0, koniec = 0, srodek = 0, suma = 0;
vector<ll> liczby;
vector<ll> sumy_prefiksowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    sumy_prefiksowe.assign(n,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }
    for (int i = n-2; i >= 0; --i)
    {
        if (liczby[i] < liczby[i+1])
            suma += liczby[i+1] - liczby[i];
        sumy_prefiksowe[i] = suma;
    }

    for (int i = 0; i < n; ++i)
    {
        poczatek = i, koniec = n;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (sumy_prefiksowe[i] - sumy_prefiksowe[srodek] <= k)
                poczatek = srodek;
            else
                koniec = srodek;
        }
        wyn = max(wyn,poczatek - (ll)i + (ll)1);
    }
    printf("%lld",wyn);

    return 0;
}