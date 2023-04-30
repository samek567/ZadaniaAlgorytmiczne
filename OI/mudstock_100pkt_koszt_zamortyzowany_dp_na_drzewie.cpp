#include <iostream>
#include <vector>

using namespace std;

struct Wierzcholek
{
    int zapotrzebowanie;
    int numer_lini;
    int numer_osady;
};

struct Krawedz
{
    int wierzcholek;
    int cena;
};

int l = 0, m = 0, ile = 0, odl = 0, zap = 0, poprz = 0, wyn = 1e9, idx = 1;
vector<Wierzcholek> wierzcholki;
vector<vector<Krawedz>> krawedzie;
vector<int> suma_w_poddrzewie;
vector<int> ile_w_poddrzewie;
vector<int> parent;

inline void DFS_suma_w_poddrzwie(int v, int par)
{
    parent[v] = par;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i].wierzcholek;
        if (wierz == par)
            continue;
        DFS_suma_w_poddrzwie(wierz,v);
        suma_w_poddrzewie[v] += suma_w_poddrzewie[wierz] + ile_w_poddrzewie[wierz] * krawedzie[v][i].cena;
        ile_w_poddrzewie[v] += ile_w_poddrzewie[wierz];
    }
}

inline void DFS(int v, int suma, int ile_wierzcholkow, int ile_krawedz)
{
    suma_w_poddrzewie[v] += suma + ile_wierzcholkow * ile_krawedz;
    if (suma_w_poddrzewie[v] < wyn)
    {
        wyn = suma_w_poddrzewie[v];
        idx = v;
    }
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i].wierzcholek;
        if (wierz == parent[v])
            continue;
        DFS(wierz,suma + ile_wierzcholkow * ile_krawedz,ile_wierzcholkow+wierzcholki[v].zapotrzebowanie,krawedzie[v][i].cena);
    }
}

int main()
{
    // Koszt zamortyzowany, dp na drzewie.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> l >> m;

    wierzcholki.push_back({-1,-1,-1});
    wierzcholki.push_back({m,0,0});
    krawedzie.assign(1e6,{});

    for (int i = 0; i < l; ++i)
    {
        cin >> ile;
        poprz = 1;
        for (int j = 0; j < ile; ++j)
        {
            cin >> odl >> zap;
            wierzcholki.push_back({zap,i+1,j+1});
            krawedzie[poprz].push_back({wierzcholki.size()-1,odl});
            krawedzie[wierzcholki.size()-1].push_back({poprz,odl});
            poprz = wierzcholki.size()-1;
        }
    }

    suma_w_poddrzewie.assign(wierzcholki.size()+1,0);
    ile_w_poddrzewie.assign(wierzcholki.size()+1,-1);
    for (int i = 1; i <= wierzcholki.size(); ++i)
        ile_w_poddrzewie[i] = wierzcholki[i].zapotrzebowanie;

    parent.assign(wierzcholki.size(),-1);
    DFS_suma_w_poddrzwie(1,-1);

    wyn = suma_w_poddrzewie[1];

    for (int i = 0; i < krawedzie[1].size(); ++i)
    {
        int pocz = krawedzie[1][i].wierzcholek, sum = suma_w_poddrzewie[1] - suma_w_poddrzewie[pocz] - ile_w_poddrzewie[pocz] * krawedzie[1][i].cena, ile_wierz = ile_w_poddrzewie[1] - ile_w_poddrzewie[pocz];
        DFS(pocz,sum,ile_wierz, krawedzie[1][i].cena);
    }

    cout << wyn << '\n' << wierzcholki[idx].numer_lini << ' ' << wierzcholki[idx].numer_osady << '\n';

    return 0;
}
