#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll q = 0, a = 0, b = 0, c = 0, d = 0, base = (1 << 18), rozmiar_drzewa = base * 2, MOD = 1e9+7;
vector<ll> drzewo_przedzialowe(rozmiar_drzewa,1);

ll querry(ll v)
{
    v += base;
    ll wyn = 1;
    while(v > 0)
    {
        wyn = (wyn * drzewo_przedzialowe[v]) % MOD;
        v /= 2;
    }
    return wyn;
}

void update(ll l, ll p, ll val)
{
    l = l + base - 1;
    p = p + base + 1;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            drzewo_przedzialowe[l+1] = (drzewo_przedzialowe[l+1] * val) % MOD;
        if (p % 2 == 1)
            drzewo_przedzialowe[p-1] = (drzewo_przedzialowe[p-1] * val) % MOD;
        l /= 2;
        p /= 2;
    }
}
int main()
{
    // O(N lg N) - zaimplementuj drzewo przedzial - punkt
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--)
    {
        cin >> a;
        if (a == 0)
        {
            cin >> b >> c >> d;
            update(b,c,d);
        }
        else
        {
            cin >> b;
            cout << querry(b) << '\n';
        }
    }

    return 0;
}