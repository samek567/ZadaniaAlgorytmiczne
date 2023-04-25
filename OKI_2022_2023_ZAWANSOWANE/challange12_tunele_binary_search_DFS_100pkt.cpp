#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, k = 0, a_i = 0, b_i = 0, poczatek = 0, koniec = 0, srodek = 0;
vector<pair<int,int>> krawedzie_wejscie;
vector<vector<int>> krawedzie;
vector<bool> czy_bylismy;

void DFS(int v)
{
    czy_bylismy[v] = true;
    for (int i = 0; i < krawedzie[v].size(); ++i)
        if (czy_bylismy[krawedzie[v][i]] == false)
            DFS(krawedzie[v][i]);
}

inline int ile_spojnych(int x)
{
    int ile = 0;
    for (int i = 0; i <= n; ++i)
        krawedzie[i].clear();
    fill(czy_bylismy.begin(),czy_bylismy.end(),false);
    for (int i = x; i < m; ++i)
    {
        krawedzie[krawedzie_wejscie[i].first].push_back(krawedzie_wejscie[i].second);
        krawedzie[krawedzie_wejscie[i].second].push_back(krawedzie_wejscie[i].first);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (czy_bylismy[i] == false)
        {
            DFS(i);
            ile++;
        }
    }
    return ile;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    czy_bylismy.assign(n+1,false);
    for (int i = 0; i <= n; ++i)
        krawedzie.push_back({});
    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        krawedzie_wejscie.push_back({a_i,b_i});
    }
    poczatek = -1, koniec = m-1;
    while(koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (ile_spojnych(srodek) >= k)
            koniec = srodek;
        else
            poczatek = srodek;
    }
    cout << koniec+1 << '\n';

    return 0;
}