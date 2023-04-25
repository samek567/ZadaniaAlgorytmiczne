#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Krawedz
{
    int wierzcholek;
    int numer_krawedzi;
};

struct Element
{
    int y;
    int x;
    int val;
    bool operator < (const Element &element) const
    {
        if (y == element.y)
            return x < element.x;
        return y < element.y;
    }
};

int n = 0, m = 0, k = 0, y = 0, x = 0;
vector<vector<Krawedz>> krawedzie;
vector<int> ile;
vector<int> cykl_eulera;
vector<bool> visited;
set<Element> odtw;
vector<pair<int,int>> specjalne_pola;

inline void DFS_euler(int v)
{
    for (;ile[v] < krawedzie[v].size(); ++ile[v])
    {
        if (visited[krawedzie[v][ile[v]].numer_krawedzi] == true)
            continue;
        visited[krawedzie[v][ile[v]].numer_krawedzi] = true;
        DFS_euler(krawedzie[v][ile[v]].wierzcholek);
    }
    cykl_eulera.push_back(v);
}

int main()
{
    // Cykl Eulera.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    krawedzie.assign(n+m+1,{});
    ile.assign(n+m+1,0);
    visited.assign(k,false);
    specjalne_pola.assign(k,{-1,-1});

    for (int i = 0; i < k; ++i)
    {
        cin >> y >> x;
        krawedzie[y].push_back({n+x,i});
        krawedzie[n+x].push_back({y,i});
        specjalne_pola[i] = {y,x};
    }

    for (int i = 1; i <= n+m; ++i)
    {
        if (krawedzie[i].size() % 2 == 1)
        {
            cout << "NIE" << '\n';
            return 0;
        }
    }
    cout << "TAK" << '\n';

    DFS_euler(1);
    for (int i = 1; i < cykl_eulera.size(); ++i)
    {
        if (i % 2 == 1)
            odtw.insert({min(cykl_eulera[i], cykl_eulera[i-1]),max(cykl_eulera[i], cykl_eulera[i-1]) - n,1});
        else
            odtw.insert({min(cykl_eulera[i], cykl_eulera[i-1]),max(cykl_eulera[i], cykl_eulera[i-1]) - n,-1});
    }

    for (int i = 0; i < k; ++i)
    {
        auto it = odtw.find({specjalne_pola[i].first, specjalne_pola[i].second});
        cout << it->val << '\n';
    }

    return 0;
}