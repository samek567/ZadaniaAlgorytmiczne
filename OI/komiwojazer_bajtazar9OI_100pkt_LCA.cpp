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

int n = 0, m = 0, a = 0, b = 0, akt = 0, base = (1 << 16), rozmiar_drzewa = base * 2, cnt = 0, wyn = 0;
vector<vector<int>> krawdzie;
vector<int> glebokosc;
vector<int> idx_w_drzewie_przedzialowym;
vector<Element> drzewo_przedzialowe;

inline void DFS(int v, int parent, int gleb)
{
    glebokosc[v] = gleb;
    idx_w_drzewie_przedzialowym[v] = cnt;
    drzewo_przedzialowe[base+cnt] = {v,gleb};
    cnt++;
    for (int i = 0; i < krawdzie[v].size(); ++i)
    {
        int wierz = krawdzie[v][i];
        if (wierz == parent)
            continue;
        DFS(wierz,v,gleb+1);
        idx_w_drzewie_przedzialowym[v] = cnt;
        drzewo_przedzialowe[base+cnt] = {v,gleb};
        cnt++;
    }
}

inline Element query(int l, int p)
{
    l = l + base - 1, p = p + base + 1;
    Element res = {-1,1000000};
    while (l / 2 != p / 2)
    {
        if (l % 2 == 0)
            res = min(res, drzewo_przedzialowe[l+1]);
        if (p % 2 == 1)
            res = min(res, drzewo_przedzialowe[p-1]);
        l /= 2;
        p /= 2;
    }
    return res;
}

int main()
{
    // LCA, LCA zaimplementowane za pomoca DFS preorder + drzewa przedzialowego, tak jak opisal Pan Radoszewski na MIMUW(chyba tez dela), w artykule o RMQ i LCA.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    krawdzie.assign(n+1,{});
    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b;
        krawdzie[a].push_back(b);
        krawdzie[b].push_back(a);
    }

    glebokosc.assign(n+1,-1);
    drzewo_przedzialowe.assign(rozmiar_drzewa,{1000000,1000000});
    idx_w_drzewie_przedzialowym.assign(n+1,-1);

    DFS(1,-1,0);
    for (int i = base-1; i >= 1; --i)
        drzewo_przedzialowe[i] = min(drzewo_przedzialowe[i*2], drzewo_przedzialowe[i*2+1]);


    akt = 1;
    cin >> m;
    while(m--)
    {
        cin >> a;
        int lca = query(min(idx_w_drzewie_przedzialowym[akt],idx_w_drzewie_przedzialowym[a]),max(idx_w_drzewie_przedzialowym[akt],idx_w_drzewie_przedzialowym[a])).wierzcholek;
        wyn += glebokosc[akt] + glebokosc[a] - 2 * glebokosc[lca];
        akt = a;
    }

    cout << wyn << '\n';

    return 0;
}
