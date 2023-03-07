#include <iostream>
#include <vector>

using namespace std;
typedef long double ld;
typedef long long ll;

int n = 0, poczatek = 0, koniec = 0, srodek = 0, lewy_wsk = 0, prawy_wsk = 0;
ll suma = 0;
ld k = 0, wyn = 1000000000000000000;
vector<int> liczby;
vector<ll> sumy_prefiksowe;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    liczby.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> liczby[i];

    for (int i = 0; i < n; ++i)
    {
        suma += liczby[i];
        sumy_prefiksowe.push_back(suma);
    }

    for (int i = 0; i < n; ++i)
    {
        if (liczby[i] >= k)
        {
            if (abs(liczby[i] - k) < wyn)
            {
                wyn = abs(liczby[i] - k);
                lewy_wsk = i;
                prawy_wsk = i;
            }
        }
        else
        {
            poczatek = i, koniec = n;
            while (koniec - poczatek > 1)
            {
                srodek = (poczatek + koniec) / 2;
                ll sum = 0;
                if (i == 0)
                    sum = sumy_prefiksowe[srodek];
                else
                    sum = sumy_prefiksowe[srodek] - sumy_prefiksowe[i-1];
                if ((ld)sum / ld(srodek - i + 1) <= k)
                    poczatek = srodek;
                else
                    koniec = srodek;
            }
            ll sum = 0;
            if (i == 0)
                sum = sumy_prefiksowe[poczatek];
            else
                sum = sumy_prefiksowe[poczatek] - sumy_prefiksowe[i-1];
            ld srednia = (ld)sum / ld(poczatek - i + 1);
            if (abs(srednia - k) < wyn)
            {
                wyn = abs(srednia - k);
                lewy_wsk = i;
                prawy_wsk = poczatek;
            }
            if (poczatek != n-1)
            {
                ll sum = 0;
                if (i == 0)
                    sum = sumy_prefiksowe[koniec];
                else
                    sum = sumy_prefiksowe[koniec] - sumy_prefiksowe[i-1];
                ld srednia = (ld)sum / ld(koniec - i + 1);
                if (abs(srednia - k) < wyn)
                {
                    wyn = abs(srednia - k);
                    lewy_wsk = i;
                    prawy_wsk = koniec;
                }
            }
        }
    }

    cout << lewy_wsk + 1 << ' ' << prawy_wsk + 1 << '\n';

    return 0;
}