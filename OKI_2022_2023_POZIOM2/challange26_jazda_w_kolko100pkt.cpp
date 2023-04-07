#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, a = 0, b = 0, start = 0;
bool czy_mamy = false;
vector<vector<int>> krawedzie;
vector<bool> visited;

inline void DFS(int v, int parent)
{
    if (czy_mamy == true)
        return;
    visited[v] = true;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i];
        if (wierz == parent)
            continue;
        if (visited[wierz] == true)
            czy_mamy = true;
        DFS(wierz,v);
    }
}

int main()
{
    // O(N+M), sprawdz czy graf nieskierowany ma cykl.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    krawedzie.assign(n+1,{});
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    visited.assign(n+1,false);
    for (int i = 1; i <= n; ++i)
        if (visited[i] == false)
            DFS(i,-1);

    if (czy_mamy == true)
        cout << "TAK" << '\n';
    else
        cout << "NIE" << '\n';

    return 0;
}