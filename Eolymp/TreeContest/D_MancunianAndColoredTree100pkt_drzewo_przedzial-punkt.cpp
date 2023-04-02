#include <iostream>
#include <vector>

using namespace std;

struct Element
{
    int wierzcholek;
    int glebokosc;
    bool operator < (const Element &element) const
    {
        return glebokosc < element.glebokosc;
    }
};

int n = 0, c = 0, a = 0, base = (1 << 17), rozmiar_drzewa = base * 2, cnt = 0;
vector<int> A;
vector<vector<int>> krawedzie;
vector<Element> drzewo_przedzialowe;
vector<int> ile_w_podrzewie;
vector<int> porzadek_post_order;
vector<int> glebokosc;
vector<vector<int>> wystapienia;
vector<int> wyn;

inline int DFS(int v, int parent)
{
    porzadek_post_order[v] = cnt;
    ++cnt;
    int sum = 1;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i];
        if (wierz == parent)
            continue;
        sum += DFS(wierz,v);
    }
    ile_w_podrzewie[v] = sum;
    return ile_w_podrzewie[v];
}

inline void DFS_glebokosc(int v, int zag)
{
    glebokosc[v] = zag;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i];
        if (glebokosc[wierz] == -1)
            DFS_glebokosc(wierz, zag+1);
    }
}

inline void update(int l, int p, Element val)
{
    l = l + base - 1, p = p + base + 1;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            drzewo_przedzialowe[l+1] = max(drzewo_przedzialowe[l+1],val);
        if (p % 2 == 1)
            drzewo_przedzialowe[p-1] = max(drzewo_przedzialowe[p-1],val);
        l /= 2;
        p /= 2;
    }
}

inline void update_clear(int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            drzewo_przedzialowe[l+1] = {-1,-1};
        if (p % 2 == 1)
            drzewo_przedzialowe[p-1] = {-1,-1};
        l /= 2;
        p /= 2;
    }
}

inline Element query(int v)
{
    v += base;
    Element res = {-1,-1};
    while (v > 0)
    {
        res = max(res,drzewo_przedzialowe[v]);
        v /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;

    krawedzie.assign(n+1,{});
    porzadek_post_order.assign(n+1,-1);
    ile_w_podrzewie.assign(n+1,-1);
    glebokosc.assign(n+1,-1);
    wystapienia.assign(c+1,{});
    wyn.assign(n+1,-1);
    A.assign(n+1,-1);

    for (int i = 2; i <= n; ++i)
    {
        cin >> a;
        krawedzie[a].push_back(i);
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> A[i];
        wystapienia[A[i]].push_back(i);
    }
    DFS(1,-1);
    DFS_glebokosc(1,0);
    drzewo_przedzialowe.assign(rozmiar_drzewa,{-1,-1});
    for (int i = 1; i <= c; ++i)
    {
        for (int j = 0; j < wystapienia[i].size(); ++j)
        {
            int wierz = wystapienia[i][j];
            if (ile_w_podrzewie[wierz] == 1)
                continue;
            update(porzadek_post_order[wierz]+1, porzadek_post_order[wierz] + ile_w_podrzewie[wierz] - 1, {wierz,glebokosc[wierz]});
        }
        for (int j = 0; j < wystapienia[i].size(); ++j)
        {
            int wierz = wystapienia[i][j];
            wyn[wierz] = query(porzadek_post_order[wierz]).wierzcholek;
        }
        for (int j = 0; j < wystapienia[i].size(); ++j)
        {
            int wierz = wystapienia[i][j];
            if (ile_w_podrzewie[wierz] == 1)
                continue;
            update_clear(porzadek_post_order[wierz]+1, porzadek_post_order[wierz] + ile_w_podrzewie[wierz] - 1);
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << wyn[i] << ' ';

    return 0;
}