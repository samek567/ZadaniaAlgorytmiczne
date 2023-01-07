#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int q = 0, t_i = 0, a_i = 0, b_i = 0, base = 0, rozmiar_drzewa = 0;
vector<int> drzewo_przedzialowe;

void update(int v, int val)
{
    v += base;
    drzewo_przedzialowe[v] = val;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe[v] = max(drzewo_przedzialowe[v*2+1],drzewo_przedzialowe[v*2]);
        v /= 2;
    }
}

int querry(int l, int p)
{
    l = l + base - 1;
    p = p + base + 1;
    int wyn = -1e9-5;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            wyn = max(wyn,drzewo_przedzialowe[l+1]);
        if (p % 2 == 1)
            wyn = max(wyn,drzewo_przedzialowe[p-1]);
        l /= 2;
        p /= 2;
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
    drzewo_przedzialowe.assign(rozmiar_drzewa,0);
    for (int i = 0; i < q; ++i)
    {
        cin >> t_i >> a_i >> b_i;
        if (t_i == 0)
            update(a_i,b_i);
        else
            printf("%d\n",querry(a_i,b_i));
    }

    return 0;
}