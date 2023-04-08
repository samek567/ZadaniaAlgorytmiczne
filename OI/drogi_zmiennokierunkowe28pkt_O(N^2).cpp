#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, a = 0, b = 0, cnt = 0;
vector<vector<int>> krawedzie_parzyste;
vector<vector<int>> krawedzie_nie_parzyste;
vector<bool> czy_bylismy;
vector<bool> do_jakich_doszlismy;
vector<int> wyn;

void DFS_parzyste(int v)
{
    czy_bylismy[v] = true;
    if (do_jakich_doszlismy[v] == false)
    {
        do_jakich_doszlismy[v] = true;
        cnt++;
    }
    for (int i = 0; i < krawedzie_parzyste[v].size(); ++i)
        if (czy_bylismy[krawedzie_parzyste[v][i]] == false)
            DFS_parzyste(krawedzie_parzyste[v][i]);
}

void DFS_nie_parzyste(int v)
{
    czy_bylismy[v] = true;
    if (do_jakich_doszlismy[v] == false)
    {
        do_jakich_doszlismy[v] = true;
        cnt++;
    }
    for (int i = 0; i < krawedzie_nie_parzyste[v].size(); ++i)
        if (czy_bylismy[krawedzie_nie_parzyste[v][i]] == false)
            DFS_nie_parzyste(krawedzie_nie_parzyste[v][i]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    krawedzie_nie_parzyste.assign(n+1,{});
    krawedzie_parzyste.assign(n+1,{});
    do_jakich_doszlismy.assign(n+1,false);
    czy_bylismy.assign(n+1,false);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        krawedzie_parzyste[a].push_back(b);
        krawedzie_nie_parzyste[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        cnt = 0;
        fill(do_jakich_doszlismy.begin(),do_jakich_doszlismy.end(),false);
        fill(czy_bylismy.begin(),czy_bylismy.end(),false);
        DFS_parzyste(i);
        fill(czy_bylismy.begin(),czy_bylismy.end(),false);
        DFS_nie_parzyste(i);
        if (cnt == n)
            wyn.push_back(i);
    }

    cout << wyn.size() << '\n';
    for (int i = 0; i < wyn.size(); ++i)
        cout << wyn[i] << ' ';

    return 0;
}