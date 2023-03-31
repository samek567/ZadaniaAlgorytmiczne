#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;
typedef long long ll;

int n = 0, a = 0, b = 0, nr = 0;
vector<int> A;
vector<vector<int>> krawedzie;
vector<int> porzadek_topologiczny;
vector<bool> czy_bylismy;
queue<int> Q;
vector<unordered_map<int,int>> stat;
vector<ll> wyn;
vector<int> idx_mapy;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    krawedzie.assign(n+1,{});
    A.assign(n+1,0);
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    if (n == 1)
    {
        cout << A[1] << '\n';
        return 0;
    }

    czy_bylismy.assign(n+1,false);
    czy_bylismy[1] = true;
    Q.push(1);
    porzadek_topologiczny.push_back(1);
    while(!Q.empty())
    {
        int spr = Q.front();
        Q.pop();
        for (int i = 0; i < krawedzie[spr].size(); ++i)
        {
            int wierz = krawedzie[spr][i];
            if (czy_bylismy[wierz] == false)
            {
                Q.push(wierz);
                porzadek_topologiczny.push_back(wierz);
                czy_bylismy[wierz] = true;
            }
        }
    }

    idx_mapy.assign(n+1,-1);
    wyn.assign(n+1,0);
    for (int i = n-1; i >= 0; --i)
    {
        int spr = porzadek_topologiczny[i];
        if (spr != 1 and krawedzie[spr].size() == 1)
        {
            wyn[spr] = 1;
            idx_mapy[spr] = stat.size();
            stat.push_back({{A[spr],1}});
        }
        else
        {
            int max_liczebnosc = 0, idx_max = -1, odwolanie = -1;
            ll val = 0;
            for (int j = 0; j < krawedzie[spr].size(); ++j)
            {
                int wierz = krawedzie[spr][j];
                if (idx_mapy[wierz] == -1)
                    continue;
                if (stat[idx_mapy[wierz]].size() > max_liczebnosc)
                {
                    max_liczebnosc = stat[idx_mapy[wierz]].size();
                    idx_max = wierz;
                }
            }
            odwolanie = idx_mapy[idx_max];
            val = wyn[idx_max];
            auto it = stat[odwolanie].find(A[spr]);
            if (it != stat[odwolanie].end())
            {
                val -= (ll)stat[odwolanie][A[spr]] * (ll)stat[odwolanie][A[spr]];
                stat[odwolanie][A[spr]]++;
                val += (ll)stat[odwolanie][A[spr]] * (ll)stat[odwolanie][A[spr]];
            }
            else
            {
                stat[odwolanie][A[spr]] = 1;
                val++;
            }
            for (int j = 0; j < krawedzie[spr].size(); ++j)
            {
                int wierz = krawedzie[spr][j];
                if (idx_mapy[wierz] == -1 or wierz == idx_max)
                    continue;
                int idx = idx_mapy[wierz];
                for (auto it = stat[idx].begin(); it != stat[idx].end(); ++it)
                {
                    int ile = it->second, kolor = it->first;
                    auto it2 = stat[odwolanie].find(kolor);
                    if (it2 != stat[odwolanie].end())
                    {
                        val -= (ll)stat[odwolanie][kolor] * (ll)stat[odwolanie][kolor];
                        stat[odwolanie][kolor] += ile;
                        val += (ll)stat[odwolanie][kolor] * (ll)stat[odwolanie][kolor];
                    }
                    else
                    {
                        stat[odwolanie][kolor] = ile;
                        val += (ll)ile * (ll)ile;
                    }
                }
            }
            wyn[spr] = val;
            idx_mapy[spr] = odwolanie;
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << wyn[i] << ' ';

    return 0;
}