#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll q = 0, t_i = 0, a_i = 0, b_i = 0, c_i = 0, base = 0, rozmiar_drzewa = 0, mod = 1e9+7;
vector<ll> drzewo_przedzialowe;

void update(int l, int p, ll val)
{
    l = l + base - 1;
    p = p + base + 1;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            drzewo_przedzialowe[l+1] = (drzewo_przedzialowe[l+1] * val) % mod;
        if (p % 2 == 1)
            drzewo_przedzialowe[p-1] = (drzewo_przedzialowe[p-1] * val) % mod;
        l /= 2;
        p /= 2;
    }
}

ll querry(int v)
{
    v += base;
    ll wyn = 1;
    while (v > 0)
    {
        wyn = (wyn * drzewo_przedzialowe[v]) % mod;
        v /= 2;
    }
    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    base = (1 << 20);
    rozmiar_drzewa = base * 2;
    drzewo_przedzialowe.assign(rozmiar_drzewa,1);
    for (int i = 0; i < q; ++i)
    {
        cin >> t_i;
        if (t_i == 0)
        {
            cin >> a_i >> b_i >> c_i;
            update(a_i,b_i,c_i);
        }
        else
        {
            cin >> a_i;
            printf("%lld\n",querry(a_i));
        }
    }

    return 0;
}