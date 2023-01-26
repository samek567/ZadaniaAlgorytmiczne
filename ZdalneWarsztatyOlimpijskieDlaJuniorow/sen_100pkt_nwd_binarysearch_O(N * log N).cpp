#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n = 0, q = 0, poczatek = 0, koniec = 0, srodek = 0;
ll wczytana_liczba = 0;
vector<ll> nwd_prefiksowe;

int main()
{
    // O(N log N) Binary search.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    cin >> wczytana_liczba;
    nwd_prefiksowe.push_back(wczytana_liczba);
    for (int i = 1; i < n; ++i)
    {
        cin >> wczytana_liczba;
        nwd_prefiksowe.push_back(__gcd(nwd_prefiksowe[i-1],wczytana_liczba));
    }
    while(q--)
    {
        cin >> wczytana_liczba;
        poczatek = -1, koniec = n;
        while (koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if (nwd_prefiksowe[srodek] % wczytana_liczba == 0)
                poczatek = srodek;
            else
                koniec = srodek;
        }
        printf("%d ",poczatek+1);
    }
    return 0;
}