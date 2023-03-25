#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;

struct Element_seta
{
    ll wartosc;
    int wierzcholek;
    bool operator < (const Element_seta &element_seta) const
    {
        if (wartosc == element_seta.wartosc)
            return wierzcholek < element_seta.wierzcholek;
        return wartosc > element_seta.wartosc;
    }
};

struct Krawedz
{
    int wierzcholek;
    int cena;
};

int n = 0, m = 0, a = 0, b = 0, c = 0;
vector<vector<Krawedz>> krawedzie;
priority_queue<Element_seta> S;
vector<ll> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    krawedzie.assign(n+1,{});
    dp.assign(n+1, 1e18);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        krawedzie[a].push_back({b,c});
    }

    S.push({0,1});
    dp[1] = 0;

    while(!S.empty())
    {
        Element_seta spr = S.top();
        S.pop();
        if (dp[spr.wierzcholek] < spr.wartosc)
            continue;
        for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
        {
            int wierz = krawedzie[spr.wierzcholek][i].wierzcholek;
            if (spr.wartosc + (ll)krawedzie[spr.wierzcholek][i].cena < dp[wierz])
            {
                dp[wierz] = spr.wartosc + (ll)krawedzie[spr.wierzcholek][i].cena;
                S.push({spr.wartosc + (ll)krawedzie[spr.wierzcholek][i].cena, wierz});
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << dp[i] << ' ';

    return 0;
}