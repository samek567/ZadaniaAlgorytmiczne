#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll n = 0, q = 0, wczytana_liczba = 0, poczatek = 0, koniec = 0, srodek = 0;
vector<ll> dzialki;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        dzialki.push_back(wczytana_liczba);
    }
    for (int i = 0; i < q; ++i)
    {
        cin >> wczytana_liczba;
        poczatek = 0, koniec = n;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (dzialki[srodek] > wczytana_liczba)
                koniec = srodek;
            else
                poczatek = srodek;
        }
        printf("%lld\n",min(abs(dzialki[poczatek] - wczytana_liczba),abs(dzialki[poczatek+1] - wczytana_liczba)));
    }
    return 0;
}