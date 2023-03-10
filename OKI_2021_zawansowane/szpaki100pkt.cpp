#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int q = 0, k = 0, a = 0, b = 0, c = 0, base = (1<<17), rozmiar_drzewa = base * 2, MOD = 1e9+7;
char operacja;
vector<int> drzewo_przedzialowe;

inline void update(int l, int p, int val)
{
    l = l + base - 1;
    p = p + base + 1;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            drzewo_przedzialowe[l+1] = ((ll)drzewo_przedzialowe[l+1] * (ll)val) % MOD;
        if (p % 2 == 1)
            drzewo_przedzialowe[p-1] = ((ll)drzewo_przedzialowe[p-1] * (ll)val) % MOD;
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
        wyn = ((ll)wyn * (ll)drzewo_przedzialowe[v]) % MOD;
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
    cin >> q >> k;
    MOD = k;
    while(q--)
    {
        cin >> operacja;
        if (operacja == 'N')
        {
            cin >> a >> b >> c;
            update(a,b,c);
        }
        else
        {
            cin >> a;
            if (querry(a) == 0)
                cout << "TAK" << '\n';
            else
                cout << "NIE" << '\n';
        }
    }

    return 0;
}