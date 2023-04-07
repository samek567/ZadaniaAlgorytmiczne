#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

struct Element_seta
{
    ll dp;
    int wierzcholek;
    bool operator < (const Element_seta &element_seta) const
    {
        if (dp == element_seta.dp)
            return wierzcholek < element_seta.wierzcholek;
        return dp < element_seta.dp;
    }
};

struct Krawedz
{
    int wierzcholek;
    int cena;
};

int n = 0, m = 0, a = 0, b = 0, c = 0;
ll INF = 1e18+50;
vector<int> C;
vector<ll> dp;
set<Element_seta> S;
vector<vector<Krawedz>> krawedzie;
vector<vector<Krawedz>> odwrocone_krawedzie;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    C.assign(n+1,0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> C[i];
        C[i] /= 2;
    }

    krawedzie.assign(n+1,{});
    odwrocone_krawedzie.assign(n+1,{});
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        krawedzie[a].push_back({b,c});
    }

    dp.assign(n+1,INF);
    S.insert({0,1});
    dp[1] = 0;
    while(!S.empty())
    {
        Element_seta spr = *S.begin();
        S.erase(spr);
        for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
        {
            int wierz = krawedzie[spr.wierzcholek][i].wierzcholek, val = spr.dp + krawedzie[spr.wierzcholek][i].cena;
            if (val < dp[wierz])
            {
                auto it = S.find({dp[wierz],wierz});
                if (it != S.end())
                    S.erase(*it);
                dp[wierz] = val;
                S.insert({dp[wierz],wierz});
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        S.insert({dp[i] + C[i], i});
    int val = S.begin()->dp, wierz = S.begin()->wierzcholek;
    fill(dp.begin(),dp.end(),INF);
    dp[wierz] = val;
    while(!S.empty())
    {
        Element_seta spr = *S.begin();
        if (spr.wierzcholek == 1)
        {
            cout << spr.dp << '\n';
            return 0;
        }
        S.erase(spr);
        for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
        {
            int wierz = krawedzie[spr.wierzcholek][i].wierzcholek, val = spr.dp + krawedzie[spr.wierzcholek][i].cena;
            if (val < dp[wierz])
            {
                auto it = S.find({dp[wierz],wierz});
                if (it != S.end())
                    S.erase(*it);
                dp[wierz] = val;
                S.insert({dp[wierz],wierz});
            }
        }
    }

    return 0;
}