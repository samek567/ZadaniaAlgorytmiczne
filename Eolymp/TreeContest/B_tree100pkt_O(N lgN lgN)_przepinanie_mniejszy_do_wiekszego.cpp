#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int n = 0, a = 0, b = 0, korzen = 0, cnt = 0, base = (1 << 20), rozmiar_drzewa = base * 2, wynik = 0;
vector<int> A;
vector<int> wyn;
vector<int> jaki_idx_seta;
vector<vector<int>> krawedzie;
vector<unordered_map<int,int>> stat;
vector<int> porzadek_topologiczny;
queue<int> Q;
vector<bool> czy_bylismy;

inline void przepnij(int idx_mniejszego,int idx_wiekszego)
{
    for (auto it = stat[idx_mniejszego].begin(); it != stat[idx_mniejszego].end(); ++it)
    {
        int kolor = it->first;
        stat[idx_wiekszego][kolor] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    A.assign(n+1,0);
    krawedzie.assign(n+1,{});
    wyn.assign(n+1,0);
    jaki_idx_seta.assign(n+1,-1);
    czy_bylismy.assign(n+1,false);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        A[i] = b;
        if (a == 0)
            korzen = i;
        else
        {
            krawedzie[a].push_back(i);
            krawedzie[i].push_back(a);
        }
    }

    if (n == 1)
    {
        cout << "1" << '\n';
        return 0;
    }

    porzadek_topologiczny.push_back(korzen);
    Q.push(korzen);
    czy_bylismy[korzen] = true;
    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        for (int i = 0; i < krawedzie[v].size(); ++i)
        {
            int wierz = krawedzie[v][i];
            if (czy_bylismy[wierz] == false)
            {
                czy_bylismy[wierz] = true;
                Q.push(wierz);
                porzadek_topologiczny.push_back(wierz);
            }
        }
    }

    for (int i = n-1; i >= 0; --i)
    {
        int v = porzadek_topologiczny[i];
        if (v != korzen and krawedzie[v].size() == 1)
        {
            jaki_idx_seta[v] = stat.size();
            stat.push_back({{A[v],1}});
            wyn[v] = 1;
            continue;
        }

        int ile_max = 0, wierzcholek_max = 0;
        for (int i = 0; i < krawedzie[v].size(); ++i)
        {
            int wierz = krawedzie[v][i];
            if (jaki_idx_seta[wierz] == -1)
                continue;
            if (stat[jaki_idx_seta[wierz]].size() > ile_max)
            {
                ile_max = stat[jaki_idx_seta[wierz]].size(), wierzcholek_max = wierz;
            }
        }
        jaki_idx_seta[v] = jaki_idx_seta[wierzcholek_max];
        stat[jaki_idx_seta[v]][A[v]] = 1;

        for (int i = 0; i < krawedzie[v].size(); ++i)
        {
            int wierz = krawedzie[v][i];
            if (jaki_idx_seta[wierz] == -1 or wierz == wierzcholek_max)
                continue;
            przepnij(jaki_idx_seta[wierz],jaki_idx_seta[v]);
        }

        wyn[v] = stat[jaki_idx_seta[v]].size();
    }

    for (int i = 1; i <= n; ++i)
        cout << wyn[i] << ' ';

    return 0;
}