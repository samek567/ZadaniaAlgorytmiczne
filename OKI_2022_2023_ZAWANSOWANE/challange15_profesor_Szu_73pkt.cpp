#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 0, m = 0, a = 0, b = 0, ile_spojnych = 0, INF = 36501;
vector<vector<int>> krawedzie;
vector<vector<int>> odwrocone_krawedzie;
vector<bool> visited;
vector<int> porzadek;
vector<int> w_jakiej_spojnej;
vector<int> ile_w_SCC;
vector<bool> czy_epic_SCC; // czy ma wiecej niz jeden wierzcholek / jeden wierzcholek wchodzacy do siebie(wtedy wyn INF)
vector<vector<int>> krawedzie_SCC;
vector<int> ile_wchodzi;
queue<int> Q;
vector<int> porzadek_topologiczny;
vector<int> dp;
vector<int> wyn;

inline void DFS(int v)
{
    visited[v] = true;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i];
        if (visited[wierz] == false)
            DFS(wierz);
    }
    porzadek.push_back(v);
}

inline void DFS_spojne(int v)
{
    w_jakiej_spojnej[v] = ile_spojnych;
    for (int i = 0; i < odwrocone_krawedzie[v].size(); ++i)
    {
        int wierz = odwrocone_krawedzie[v][i];
        if (w_jakiej_spojnej[wierz] == -1)
            DFS_spojne(wierz);
    }
}

int main()
{
    // Silnie Spojne Skladowe, Sortowanie Topologiczne, Dynamik na dag-u.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    n++;
    krawedzie.assign(n+1,{});
    odwrocone_krawedzie.assign(n+1,{});
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        odwrocone_krawedzie[b].push_back(a);
    }

    visited.assign(n+1,false);
    for (int i = 1; i <= n; ++i)
        if (visited[i] == false)
            DFS(i);
    w_jakiej_spojnej.assign(n+1,-1);
    for (int i = n-1; i >= 0; --i)
    {
        int v = porzadek[i];
        if (w_jakiej_spojnej[v] == -1)
        {
            DFS_spojne(v);
            ile_spojnych++;
        }
    }

    czy_epic_SCC.assign(ile_spojnych,false);
    ile_w_SCC.assign(ile_spojnych,0);
    for (int i = 1; i <= n; ++i)
        ile_w_SCC[w_jakiej_spojnej[i]]++;
    for (int i = 0; i < ile_spojnych; ++i)
        if (ile_w_SCC[i] > 1)
            czy_epic_SCC[i] = true;

    krawedzie_SCC.assign(ile_spojnych,{});
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < krawedzie[i].size(); ++j)
        {
            if (i == krawedzie[i][j])
                czy_epic_SCC[w_jakiej_spojnej[i]] = true;
            else if (w_jakiej_spojnej[i] != w_jakiej_spojnej[krawedzie[i][j]])
                krawedzie_SCC[w_jakiej_spojnej[krawedzie[i][j]]].push_back(w_jakiej_spojnej[i]);
        }
    }

    ile_wchodzi.assign(ile_spojnych,0);
    for (int i = 0; i < ile_spojnych; ++i)
        for (int j = 0; j < krawedzie_SCC[i].size(); ++j)
            ile_wchodzi[krawedzie_SCC[i][j]]++;

    for (int i = 0; i < ile_spojnych; ++i)
    {
        if (ile_wchodzi[i] == 0)
        {
            Q.push(i);
            porzadek_topologiczny.push_back(i);
        }
    }

    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        for (int i = 0; i < krawedzie_SCC[v].size(); ++i)
        {
            int wierz = krawedzie_SCC[v][i];
            ile_wchodzi[wierz]--;
            if (ile_wchodzi[wierz] == 0)
            {
                Q.push(wierz);
                porzadek_topologiczny.push_back(wierz);
            }
        }
    }

    int maxx = 0;
    dp.assign(ile_spojnych,0);
    dp[w_jakiej_spojnej[n]] = 1;
    for (int i = 0; i < ile_spojnych; ++i)
    {
        int v = porzadek_topologiczny[i];
        if ((ile_w_SCC[v] > 1 or czy_epic_SCC[v] == true) and dp[v] > 0)
            dp[v] = INF;
        for (int j = 0; j < krawedzie_SCC[v].size(); ++j)
        {
            int wierz = krawedzie_SCC[v][j];
            if (dp[v] == INF)
                dp[wierz] = INF;
            else
                dp[wierz] = min(dp[wierz] + dp[v], INF);
        }
        maxx = max(maxx, dp[v]);
    }

    for (int i = 1; i < n; ++i)
        if (dp[w_jakiej_spojnej[i]] == maxx)
            wyn.push_back(i);

    if (maxx == INF)
        cout << "zawsze" << '\n';
    else
        cout << maxx << '\n';
    cout << wyn.size() << '\n';
    for (int i = 0; i < wyn.size(); ++i)
        cout << wyn[i] << ' ';

    return 0;
}