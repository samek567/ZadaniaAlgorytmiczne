#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int n = 0, m = 0, a = 0, b = 0, ile_SCC = 0;
vector<set<int>> SCC_krawedzie;
vector<vector<int>> SCC;
vector<vector<int>> krawedzie;
vector<vector<int>> odwrocone_krawedzie;
vector<int> kolejnosc_in_order;
vector<int> w_jakiej_SCC_jest;
vector<bool> czy_odwiedzone;
vector<int> ile_wchodzacych;
vector<int> porzadek_topologiczny;
vector<int> dp;
queue<int> Q;

void DFS(int x)
{
    czy_odwiedzone[x] = true;
    for (int i = 0; i < krawedzie[x].size(); ++i)
    {
        if (czy_odwiedzone[krawedzie[x][i]] == false)
        {
            DFS(krawedzie[x][i]);
        }
    }
    kolejnosc_in_order.push_back(x);
}

void DFS_SCC(int x)
{
    czy_odwiedzone[x] = true;
    SCC[SCC.size()-1].push_back(x);
    w_jakiej_SCC_jest[x] = SCC.size()-1;
    for (int i = 0; i < odwrocone_krawedzie[x].size(); ++i)
    {
        if (czy_odwiedzone[odwrocone_krawedzie[x][i]] == false)
        {
            DFS_SCC(odwrocone_krawedzie[x][i]);
        }
    }
}

int main()
{
    // Bardzo fajne zadanie,
    // 1 - Dzielimy graf na SCC, zeby nie bylo cykli i zauwazamy, ze z kazdego elementu w SCC mozna dojsc do kazdego innego.
    // 2 - Sortujemy graf topologicznie i odpalamy dynamika na dag-u.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    krawedzie.assign(n+1,{});
    odwrocone_krawedzie.assign(n+1,{});
    czy_odwiedzone.assign(n+1,false);
    w_jakiej_SCC_jest.assign(n+1,-1);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        odwrocone_krawedzie[b].push_back(a);
    }

    // Podzial na SCC
    for (int i = 1; i <= n; ++i)
    {
        if (czy_odwiedzone[i] == false)
        {
            DFS(i);
        }
    }
    fill(czy_odwiedzone.begin(),czy_odwiedzone.end(), false);
    SCC.push_back({});
    SCC_krawedzie.push_back({});
    for (int i = n-1; i >= 0; --i)
    {
        if (czy_odwiedzone[kolejnosc_in_order[i]] == false)
        {
            SCC.push_back({});
            SCC_krawedzie.push_back({});
            DFS_SCC(kolejnosc_in_order[i]);
            ile_SCC++;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < krawedzie[i].size(); ++j)
        {
            if (w_jakiej_SCC_jest[i] != w_jakiej_SCC_jest[krawedzie[i][j]])
            {
                SCC_krawedzie[w_jakiej_SCC_jest[i]].insert(w_jakiej_SCC_jest[krawedzie[i][j]]);
            }
        }
    }

    // Sortowanie topologiczne z dynamikiem na dag-ach.
    ile_wchodzacych.assign(ile_SCC+1,0);
    dp.assign(ile_SCC+1,0);
    for (int i = 1; i <= ile_SCC; ++i)
    {
        for (auto j = SCC_krawedzie[i].begin(); j != SCC_krawedzie[i].end(); ++j)
        {
            ile_wchodzacych[*j]++;
        }
    }
    for (int i = 1; i <= ile_SCC; ++i)
    {
        if (ile_wchodzacych[i] == 0)
        {
            Q.push(i);
            porzadek_topologiczny.push_back(i);
        }
    }
    while (!Q.empty())
    {
        int spr = Q.front();
        for (auto i = SCC_krawedzie[spr].begin(); i != SCC_krawedzie[spr].end(); ++i)
        {
            ile_wchodzacych[*i]--;
            if (ile_wchodzacych[*i] == 0)
            {
                Q.push(*i);
                porzadek_topologiczny.push_back(*i);
            }
        }
        Q.pop();
    }
    for (int i = ile_SCC-1; i >= 0; --i)
    {
        int ile = SCC[porzadek_topologiczny[i]].size();
        for (auto j = SCC_krawedzie[porzadek_topologiczny[i]].begin(); j != SCC_krawedzie[porzadek_topologiczny[i]].end(); ++j)
        {
            ile += dp[*j];
        }
        dp[porzadek_topologiczny[i]] = ile;
    }

    for (int i = 1; i <= n; ++i)
    {
        printf("%d \n",dp[w_jakiej_SCC_jest[i]] - 1);
    }

    return 0;
}