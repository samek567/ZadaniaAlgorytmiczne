#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int q = 0, o = 0, a = 0, b = 0, c = 0, base = (1<<17), rozmiar_drzewa = base * 2, mod = 1e9+7;
vector<int> drzewo_przedzialowe;

inline void update(int l, int p, int val)
{
    l = l + base - 1;
    p = p + base + 1;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            drzewo_przedzialowe[l+1] = ((ll)drzewo_przedzialowe[l+1] * (ll) val) % mod;
        if (p % 2 == 1)
            drzewo_przedzialowe[p-1] = ((ll)drzewo_przedzialowe[p-1] * (ll) val) % mod;
        l /= 2;
        p /= 2;
    }
}

inline int querry(int v)
{
    v += base;
    int wyn = 1;
    while (v > 0)
    {
        wyn = ((ll)wyn * (ll)drzewo_przedzialowe[v]) % mod;
        v /= 2;
    }
    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    drzewo_przedzialowe.assign(rozmiar_drzewa,1);
    cin >> q;
    while(q--)
    {
        cin >> o;
        if (o == 0)
        {
            cin >> a >> b >> c;
            update(a,b,c);
        }
        else
        {
            cin >> a;
            cout << querry(a) << '\n';
        }
    }

    return 0;
}