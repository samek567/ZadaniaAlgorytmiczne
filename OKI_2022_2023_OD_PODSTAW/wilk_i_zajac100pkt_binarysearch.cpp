#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll n = 0, wczytana_liczba = 0, poczatek = 0, koniec = 0, srodek = 0, skok_prawo = 0, skok_lewo = 0, najdluzszy_skok = 0, idx_postaci = 0;
string ciag;
vector<ll> wysokosci;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> skok_prawo >> skok_lewo;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        wysokosci.push_back(wczytana_liczba);
    }
    cin >> ciag;
    for (int i = 0; i < ciag.size(); ++i)
    {
        if (ciag[i] == 'g')
        {
            poczatek = -1, koniec = idx_postaci;
            while (koniec - poczatek > 1)
            {
                srodek = (poczatek + koniec) / 2;
                if (wysokosci[srodek] - wysokosci[idx_postaci] <= skok_lewo)
                    koniec = srodek;
                else
                    poczatek = srodek;
            }
            najdluzszy_skok = max(najdluzszy_skok,idx_postaci - koniec);
            idx_postaci = koniec;
        }
        else
        {
            poczatek = idx_postaci, koniec = n;
            while (koniec - poczatek > 1)
            {
                srodek = (poczatek + koniec) / 2;
                if (wysokosci[idx_postaci] - wysokosci[srodek] <= skok_prawo)
                    poczatek = srodek;
                else
                    koniec = srodek;
            }
            najdluzszy_skok = max(najdluzszy_skok,poczatek - idx_postaci);
            idx_postaci = poczatek;
        }
    }
    printf("%lld %lld",idx_postaci+1,najdluzszy_skok);
    return 0;
}
