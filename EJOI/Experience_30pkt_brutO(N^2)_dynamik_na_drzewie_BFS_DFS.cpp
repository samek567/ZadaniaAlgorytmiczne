#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

struct Element_kolejki
{
    int wierzcholek;
    ll val;
    int min_val;
    int max_val;
};

int n = 0, a = 0, b = 0;
ll wyn = 0, maxx = 0, minn = 0;
vector<int> moce;
vector<vector<int>> krawedzie;
vector<int> porzadek_topologiczny;
queue<int> Q;
vector<bool> czy_bylismy;
vector<int> parent;
vector<ll> dp;
queue<Element_kolejki> Q_BFS;

int main()
{
    // 45pkt, O(N^2), dynamik na drzewie
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    krawedzie.assign(n+1,{});
    czy_bylismy.assign(n+1,false);
    moce.assign(n+1,-1);
    parent.assign(n+1,-1);
    dp.assign(n+1,0);

    for (int i = 1; i <= n; ++i)
        cin >> moce[i];

    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    Q.push(1);
    czy_bylismy[1] = true;
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
                parent[wierz] = spr;
                Q.push(wierz);
                porzadek_topologiczny.push_back(wierz);
                czy_bylismy[wierz] = true;
            }
        }
    }

    for (int i = n-1; i >= 0; --i)
    {
        int wierz = porzadek_topologiczny[i];
        wyn = 0, maxx = -1e9-50, minn = 1e9+50;
        while(!Q_BFS.empty())
            Q_BFS.pop();
        Q_BFS.push({wierz,0,minn,maxx});
        while(!Q_BFS.empty())
        {
            Element_kolejki spr = Q_BFS.front();
            Q_BFS.pop();
            spr.min_val = min(spr.min_val, moce[spr.wierzcholek]);
            spr.max_val = max(spr.max_val, moce[spr.wierzcholek]);
            ll suma_dp = 0;
            for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
            {
                int wierz = krawedzie[spr.wierzcholek][i];
                if (wierz != parent[spr.wierzcholek])
                    suma_dp += dp[wierz];
            }
            wyn = max(wyn, (spr.max_val - spr.min_val) + suma_dp + spr.val);
            for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
            {
                int wierz = krawedzie[spr.wierzcholek][i];
                if (wierz != parent[spr.wierzcholek])
                    Q_BFS.push({wierz, spr.val + suma_dp - dp[wierz], spr.min_val, spr.max_val});
            }
        }
        dp[wierz] = wyn;
    }

    cout << dp[1] << '\n';

    return 0;
}
