#include <iostream>
#include <vector>

using namespace std;

struct Malpka
{
    int lewa_reka;
    int prawa_reka;
};

struct Krawdz
{
    int wierzcholek;
    bool czy_idziemy;
};

struct Trzymanie_malpki_krawedz
{
    int idx_rodzica;
    int swoj_idx;
};

int n = 0, m = 0, a = 0, b = 0;
vector<Malpka> malpki;
vector<Trzymanie_malpki_krawedz> idx1;
vector<Trzymanie_malpki_krawedz> idx2;
vector<int> wyn;
vector<vector<Krawdz>> krawedzie;
vector<bool> visited;

inline void DFS(int v)
{
    visited[v] = true;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        if (krawedzie[v][i].czy_idziemy == false)
            continue;
        int wierz = krawedzie[v][i].wierzcholek;
        if (visited[wierz] == false)
            DFS(wierz);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    wyn.assign(n+1,-1);
    malpki.assign(n+1,{-1,-1});
    for (int i = 1; i <= n; ++i)
        cin >> malpki[i].lewa_reka >> malpki[i].prawa_reka;

    idx1.assign(n+1,{});
    idx2.assign(n+1,{});
    krawedzie.assign(n+1,{});
    for (int i = 1; i <= n; ++i)
    {
        if (malpki[i].lewa_reka != -1)
        {
            idx1[i] = {krawedzie[malpki[i].lewa_reka].size(), krawedzie[i].size()};
            krawedzie[malpki[i].lewa_reka].push_back({i,true});
            krawedzie[i].push_back({malpki[i].lewa_reka,true});
        }
        if (malpki[i].prawa_reka != -1)
        {
            idx2[i] = {krawedzie[malpki[i].prawa_reka].size(), krawedzie[i].size()};
            krawedzie[malpki[i].prawa_reka].push_back({i,true});
            krawedzie[i].push_back({malpki[i].prawa_reka,true});
        }
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        if (b == 1)
        {
            krawedzie[malpki[a].lewa_reka][idx1[a].idx_rodzica].czy_idziemy = false;
            krawedzie[a][idx1[a].swoj_idx].czy_idziemy = false;
        }
        else
        {
            krawedzie[malpki[a].prawa_reka][idx2[a].idx_rodzica].czy_idziemy = false;
            krawedzie[a][idx2[a].swoj_idx].czy_idziemy = false;
        }
        visited.assign(n+1,false);
        DFS(1);
        for (int j = 1; j <= n; ++j)
            if (visited[j] == false)
                if (wyn[j] == -1)
                    wyn[j] = i;
    }

    for (int i = 1; i <= n; ++i)
        cout << wyn[i] << '\n';

    return 0;
}