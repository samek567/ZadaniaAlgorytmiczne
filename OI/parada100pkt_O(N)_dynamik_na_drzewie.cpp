#include <iostream>
#include <vector>

using namespace std;

int n = 0, a = 0, b = 0, wyn = 0, korzen = 0;
vector<vector<int>> krawedzie;
vector<int> dp;
vector<int> parent_v;

int DFS(int v, int parent)
{
    parent_v[v] = parent;
    if (krawedzie[v].size() == 1 and v != korzen)
        dp[v] = 1;
    else
    {
        int maxx = 0;
        for (int i = 0; i < krawedzie[v].size(); ++i)
        {
            int wierz = krawedzie[v][i];
            if (wierz == parent)
                continue;
            maxx = max(maxx, DFS(wierz,v));
            dp[v] = maxx - 2 + (int)krawedzie[v].size();
            wyn = max(wyn, dp[v]); /* zakladamy, ze wynik w poddrzewie ukorzenionym w wierzcholku v,
            konczy sie w wierzcholku v i nie jest tylko sam wierzcholek v (parada musi byc conajmniej w dwoch miastach)
            mozna zamiast uwzgledniania tego tutaj uwzglednic to w odtwarzaniu.
            */
            dp[v] = max(dp[v], (int)krawedzie[v].size());
        }
    }
    return dp[v];
}

int main()
{
    // O(N), dynamik na drzewie.
    // dp[v] - maksymalna mozliwa wartosc do uzyskania, w poddrzewie ukorzenionym w wierzcholku v.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    krawedzie.assign(n+1,{});
    dp.assign(n+1,-1);
    parent_v.assign(n+1,0);

    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    korzen = 1;
    DFS(korzen,0);

    for (int i = 1; i <= n; ++i)
    {
        int dp_i = 0, ile = 0, maxx1 = -1, maxx2 = -1;
        for (int j = 0; j < krawedzie[i].size(); ++j)
        {
            int wierz = krawedzie[i][j];
            if (wierz == parent_v[i])
                continue;
            if (dp[wierz] > maxx1)
            {
                maxx2 = maxx1, maxx1 = dp[wierz];
            }
            else if (dp[wierz] > maxx2)
                maxx2 = dp[wierz];
            ++ile;
        }
        if (ile <= 1)
            continue;
        dp_i = maxx1 + maxx2 - 2 + krawedzie[i].size() - 2;
        wyn = max(wyn, dp_i);
    }

    cout << wyn << '\n';

    return 0;
}
