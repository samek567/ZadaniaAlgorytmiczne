#include <iostream>
#include <vector>

using namespace std;

int q = 0, o = 0, a = 0, b = 0, base = (1<<17), rozmiar_drzewa = base * 2;
vector<int> drzewo_przedzialowe;

inline void update(int v, int val)
{
    v += base;
    drzewo_przedzialowe[v] = val;
    v /= 2;
    while (v > 0)
    {
        drzewo_przedzialowe[v] = max(drzewo_przedzialowe[v*2],drzewo_przedzialowe[v*2+1]);
        v /= 2;
    }
}

inline int querry(int l, int p)
{
    l = l + base - 1;
    p = p + base + 1;
    int wyn = 0;
    while(l / 2 != p / 2)
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

    drzewo_przedzialowe.assign(rozmiar_drzewa,0);
    cin >> q;
    while(q--)
    {
        cin >> o >> a >> b;
        if (o == 0)
            update(a,b);
        else
            cout << querry(a,b) << '\n';
    }

    return 0;
}