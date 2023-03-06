#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, base = (1 << 18), rozmiar_drzewa = base * 2;
ll wyn = 0;
vector<int> H;
vector<int> sila;
vector<ll> drzewo_przedzialowe(rozmiar_drzewa,0);
vector<ll> dp;

inline void update (ll val, int v)
{
    v += base;
    drzewo_przedzialowe[v] = val;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe[v] = max(drzewo_przedzialowe[v*2], drzewo_przedzialowe[v*2+1]);
        v /= 2;
    }
}

inline ll querry(int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    ll res = 0;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res = max(res,drzewo_przedzialowe[l+1]);
        if (p % 2 == 1)
            res = max(res,drzewo_przedzialowe[p-1]);
        l /= 2;
        p /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    H.assign(n,-1);
    sila.assign(n,-1);
    dp.assign(n,-1);
    for (int i = 0; i < n; ++i)
        cin >> H[i];
    for (int i = 0; i < n; ++i)
        cin >> sila[i];

    for (int i = 0; i < n; ++i)
    {
        ll val = querry(0,H[i]-1) + sila[i];
        dp[i] = val;
        if (drzewo_przedzialowe[base + H[i]] < val)
            update(val, H[i]);
    }

    for (int i = 0; i < n; ++i)
        wyn = max(wyn, dp[i]);

    cout << wyn << '\n';

    return 0;
}
