#include <iostream>
#include <vector>

using namespace std;

int n = 0, q = 0, a = 0, b = 0, base = (1 << 18), rozmiar_drzewa = base * 2;
vector<int> drzewo_przedzialowe;

inline int querry(int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    int res = 0;
    while(l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res = max(res, drzewo_przedzialowe[l+1]);
        if (p % 2 == 1)
            res = max(res, drzewo_przedzialowe[p-1]);
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

    drzewo_przedzialowe.assign(rozmiar_drzewa,0);

    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> drzewo_przedzialowe[base+i];
    for (int i = base-1; i >= 1; --i)
        drzewo_przedzialowe[i] = max(drzewo_przedzialowe[i*2], drzewo_przedzialowe[i*2+1]);

    while(q--)
    {
        cin >> a >> b;
        cout << querry(a-1,b-1) << ' ';
    }

    return 0;
}