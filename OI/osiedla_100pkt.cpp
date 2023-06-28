#include <iostream>
#include <vector>

using namespace std;

struct Krawedz
{
    int wierzcholek;
    int numer_krawedzi;
};

struct Krawedz_in
{
    int a;
    int b;
};

int n = 0, m = 0, a = 0, b = 0, INF = 1e9, cnt = 0, wyn = 0;
vector<Krawedz_in> krawedzie_in;
vector<vector<Krawedz>> krawedzie;
vector<vector<Krawedz>> kraw;
vector<int> glebokosc;
vector<int> low;
vector<int> numer_krawedzi_wchodzacej;
vector<int> pre_order;
vector<int> mosty_v;
vector<bool> visited;
vector<bool> visited_kraw;
vector<char> wyn_vect;

inline void preprocesing()
{
    cin >> n >> m;
    krawedzie.assign(n+1,{});
    krawedzie_in.assign(m,{});
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        krawedzie_in[i] = {a,b};
        krawedzie[a].push_back({b,i});
        krawedzie[b].push_back({a,i});
    }

    glebokosc.assign(n+1,-1);
    low.assign(n+1,INF);
    numer_krawedzi_wchodzacej.assign(n+1,-1);
    pre_order.assign(n+1,-1);
    mosty_v.assign(n+1,-1);
}

inline void DFS(int v, int nr_wchodzacej, int gleb)
{
    glebokosc[v] = gleb;
    pre_order[v] = ++cnt;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        Krawedz spr = krawedzie[v][i];
        if (spr.numer_krawedzi == nr_wchodzacej)
            continue;
        if (glebokosc[spr.wierzcholek] == -1) // Drzewowa
        {
            DFS(spr.wierzcholek,spr.numer_krawedzi,gleb+1);
            if (low[spr.wierzcholek] > glebokosc[v])
                mosty_v[spr.wierzcholek] = v;
            low[v] = min(low[v], low[spr.wierzcholek]);
        }
        else if (pre_order[spr.wierzcholek] < pre_order[v])
            low[v] = min(low[v], glebokosc[spr.wierzcholek]);
    }
}

inline void usun_krawedzie()
{
    kraw.assign(n+1,{});
    for (int i = 0; i < m; ++i)
    {
        int v1 = krawedzie_in[i].a, v2 = krawedzie_in[i].b;
        if (mosty_v[v1] != v2 and mosty_v[v2] != v1)
        {
            kraw[v1].push_back({v2,i}), kraw[v2].push_back({v1,i});
        }
    }
    wyn_vect.assign(m,'<');
}

inline void DFS_spojne(int v)
{
    visited[v] = true;
    for (auto x : kraw[v])
    {
        if (visited_kraw[x.numer_krawedzi] == false)
        {
            visited_kraw[x.numer_krawedzi] = true;
            if (krawedzie_in[x.numer_krawedzi].a == v)
                wyn_vect[x.numer_krawedzi] = '<';
            else
                wyn_vect[x.numer_krawedzi] = '>';
            if (visited[x.wierzcholek] == false)
                DFS_spojne(x.wierzcholek);
        }
    }
}

int main()
{
    // Znajdz wszystkie mosty, usun je i odtworz wyn DFS-em.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    preprocesing();

    for (int i = 1; i <= n; ++i)
        if (glebokosc[i] == -1)
            DFS(i,-1,0);

    usun_krawedzie();

    visited.assign(n+1,false);
    visited_kraw.assign(m,false);
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] == false)
        {
            DFS_spojne(i);
            ++wyn;
        }
    }

    cout << wyn << '\n';

    for (int i = 0; i < m; ++i)
        cout << wyn_vect[i];
    cout << '\n';

    return 0;
}
