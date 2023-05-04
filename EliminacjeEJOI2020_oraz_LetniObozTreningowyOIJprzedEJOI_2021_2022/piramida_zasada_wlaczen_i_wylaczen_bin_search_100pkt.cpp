#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;

int n = 0, m = 0;
ll wczytana_liczba = 0, poczatek = 0, koniec = 0, srodek = 0;
set<ll> S;
vector<ll> A;

inline ll cnt(ll x)
{
    ll res = 0, NWW = 1;
    for (int i = 1; i < (1 << n); ++i)
    {
        NWW = 1;
        int ile = 0;
        for (int j = 0; j < n; ++j)
        {
            auto b = (1 << j) & i;
            if (b)
            {
                NWW = A[j] * NWW / __gcd(A[j],NWW);
                ile++;
            }
        }

        if (ile % 2 == 0)
            res -= x / NWW;
        else
            res += x / NWW;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        S.insert(wczytana_liczba);
    }

    n = S.size();
    for (auto it = S.begin(); it != S.end(); ++it)
        A.push_back(*it);

    while(m--)
    {
        cin >> wczytana_liczba;
        poczatek = 0, koniec = 1e18+5;
        while(koniec - poczatek > 1)
        {
            srodek = (poczatek + koniec) / 2;
            if(cnt(srodek) >= wczytana_liczba)
                koniec = srodek;
            else
                poczatek = srodek;
        }
        cout << koniec << '\n';
    }

    return 0;
}
