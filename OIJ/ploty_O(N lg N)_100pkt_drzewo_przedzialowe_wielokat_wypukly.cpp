#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Krawedz
{
    int minn;
    int maxx;
};

int n = 0, a = 0, b = 0, base = 0, rozmiar_drzewa = 0, q = 0;
vector<Krawedz> krawedzie;
vector<Krawedz> krawedzie_in;
vector<int> drzewo_przedzialowe_min;
vector<int> drzewo_przedzialowe_max;

inline int query_max (int l, int p)
{
    l--,p--;
    l = l + base - 1, p = p + base + 1;
    int res = -1e9;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res = max(res, drzewo_przedzialowe_max[l+1]);
        if (p % 2 == 1)
            res = max(res, drzewo_przedzialowe_max[p-1]);
        l /= 2;
        p /= 2;
    }
    return res;
}

inline int query_min (int l, int p)
{
    l--,p--;
    l = l + base - 1, p = p + base + 1;
    int res = 1e9;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res = min(res, drzewo_przedzialowe_min[l+1]);
        if (p % 2 == 1)
            res = min(res, drzewo_przedzialowe_min[p-1]);
        l /= 2;
        p /= 2;
    }
    return res;
}


inline pair<int,int> jakie_przecinaja()
{
    vector<int> A_min, A_max;
    A_min.assign(n+1,1e9);
    A_max.assign(n+1,-1e9);
    for (int i = 0; i < krawedzie.size(); ++i)
        A_min[krawedzie[i].minn] = min(A_min[krawedzie[i].minn], krawedzie[i].maxx);
    for (int i = 0; i < krawedzie.size(); ++i)
        A_max[krawedzie[i].minn] = max(A_max[krawedzie[i].minn], krawedzie[i].maxx);

    base = (1 << int((double)ceil(log2(n + 5)))), rozmiar_drzewa = base * 2;
    drzewo_przedzialowe_min.assign(rozmiar_drzewa,1e9);
    drzewo_przedzialowe_max.assign(rozmiar_drzewa,-1e9);

    for (int i = 1; i <= n; ++i)
        drzewo_przedzialowe_min[i+base-1] = A_min[i];
    for (int i = base-1; i >= 1; --i)
        drzewo_przedzialowe_min[i] = min(drzewo_przedzialowe_min[i*2], drzewo_przedzialowe_min[i*2+1]);

    for (int i = 1; i <= n; ++i)
        drzewo_przedzialowe_max[i+base-1] = A_max[i];
    for (int i = base-1; i >= 1; --i)
        drzewo_przedzialowe_max[i] = max(drzewo_przedzialowe_max[i*2], drzewo_przedzialowe_max[i*2+1]);


    for (int i = 0; i < krawedzie.size(); ++i)
    {
        int minn = query_min(krawedzie[i].minn+1, krawedzie[i].maxx-1), maxx = query_max(krawedzie[i].minn+1, krawedzie[i].maxx-1);
        if (maxx > krawedzie[i].maxx or minn < krawedzie[i].minn)
        {
            for (int j = 0; j < krawedzie.size(); ++j)
            {
                int a = krawedzie[j].minn, b = krawedzie[j].maxx;
                if (a > krawedzie[i].minn and a < krawedzie[i].maxx and (b < krawedzie[i].minn or b > krawedzie[i].maxx))
                    return {i,j};
            }
        }
    }
    return {-1,-1};
}

int main()
{
    /* O(N lg N), sprawdzamy kazda krawedz, żeby było łatwiej trzymamy je pomiedzy wierzchołkami mniejszy do większego,
    // z drzewem przedzialowym zakladamy, ze jeden wierzcholek potencjalnie przecinajacej sie krawedzi znajduje sie w jednej czesci
    // przedzielonego na pol wielokata foremnego, z drzewem przedzialowym max-ow i min-ow sprwadzamy czy sie przecinaja.
    // Po raz kolejny dzieki Whistleroosh: https://forum.pasja-informatyki.pl/584148/zadanie-ploty-2-etap-xv-oij */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while(q--)
    {
        cin >> n;
        krawedzie.assign(n-2,{});
        for (int i = 0; i < n-2; ++i)
        {
            cin >> a >> b;
            krawedzie[i].minn = min(a,b);
            krawedzie[i].maxx = max(a,b);
        }

        krawedzie_in = krawedzie;

        pair<int,int> przecinajace = jakie_przecinaja();

        vector<Krawedz> dod;
        for (int i = 0; i < n-2; ++i)
            if (i != przecinajace.first)
                dod.push_back(krawedzie[i]);
        krawedzie = dod;

        pair<int,int> przecinajace2 = jakie_przecinaja();

        if (przecinajace2.first == -1)
            cout << krawedzie_in[przecinajace.first].minn << ' ' << krawedzie_in[przecinajace.first].maxx << '\n';
        else
            cout << krawedzie_in[przecinajace.second].minn << ' ' << krawedzie_in[przecinajace.second].maxx << '\n';
    }

    return 0;
}
