#include <iostream>
#include <vector>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int n = 0, k = 0, q = 0, a_i = 0, b_i = 0, c_i = 0, base = 0, rozmiar_drzewa = 0;
vector<ll> drzewo_przedzialowe;

void update(int l, int p, int val)
{
    l = l + base - 1;
    p = p + base + 1;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            drzewo_przedzialowe[l+1] += val;
        if (p % 2 == 1)
            drzewo_przedzialowe[p-1] += val;
        l /= 2;
        p /= 2;
    }
}

ll querry(int v)
{
    v += base;
    ll zap = 0;
    while (v > 0)
    {
        zap += drzewo_przedzialowe[v];
        v /= 2;
    }
    return zap;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> q;
    base = (1 << int(ceil((double)log2(k))));
    rozmiar_drzewa = base * 2;
    drzewo_przedzialowe.assign(rozmiar_drzewa,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a_i >> b_i >> c_i;
        update(a_i,b_i,c_i);
    }
    for (int i = 0; i < q; ++i)
    {
        cin >> a_i;
        printf("%lld\n", querry(a_i));
    }
    return 0;
}