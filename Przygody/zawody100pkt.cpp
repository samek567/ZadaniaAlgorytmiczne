#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Krawedz
{
    int do_kogo;
    int waga;
};

struct Element_seta
{
    int wierzcholek;
    int wartosc;
    bool operator < (const Element_seta &element_seta) const
    {
        if (wartosc == element_seta.wartosc)
            return wierzcholek < element_seta.wierzcholek;
        return wartosc < element_seta.wartosc;
    }
};

int n = 0, m = 0, a = 0, b = 0, c = 0, d = 0, wyn = 0, min_wyn = 1e9+20;
vector<vector<Krawedz>> krawedzie;
vector<int> dp;
set<Element_seta> S;

int main()
{
    // Algorytm Dijkstry, odpalamy Dijsktre z kazdego wierzcholka, ktory wychodzi od wierzcholka "wejsciowego", czyli wierzcholka u numerze 1
    // Linia 57 i 58 baaardzo przyspiesza. Bez tych 2 linii, ten sam kod wchodzi na 70pkt, zamiast 100.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    krawedzie.assign(n+1,{});
    dp.assign(n+1,-1);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c >> d;
        krawedzie[a].push_back({b,c});
        krawedzie[b].push_back({a,d});
    }

    for (int i = 0; i < krawedzie[1].size(); ++i)
    {
        fill(dp.begin(),dp.end(),-1);
        S.clear();
        dp[krawedzie[1][i].do_kogo] = krawedzie[1][i].waga;
        S.insert({krawedzie[1][i].do_kogo,krawedzie[1][i].waga});
        wyn = -1;
        while(!S.empty())
        {
            Element_seta spr = *S.begin();
            if (spr.wartosc >= min_wyn)
                break;
            S.erase(spr);
            if (spr.wierzcholek == 1)
            {
                wyn = spr.wartosc;
                break;
            }
            for (int j = 0; j < krawedzie[spr.wierzcholek].size(); ++j)
            {
                int v = krawedzie[spr.wierzcholek][j].do_kogo;
                if (v == 1 && spr.wierzcholek == krawedzie[1][i].do_kogo)
                    continue;
                if (dp[v] == -1 || spr.wartosc + krawedzie[spr.wierzcholek][j].waga < dp[v])
                {
                    auto it = S.find({v,dp[v]});
                    if (it != S.end())
                        S.erase(*it);
                    dp[v] = spr.wartosc + krawedzie[spr.wierzcholek][j].waga;
                    S.insert({v,spr.wartosc + krawedzie[spr.wierzcholek][j].waga});
                }
            }
        }
        if (wyn != -1)
            min_wyn = min(min_wyn,wyn);
    }

    cout << min_wyn << '\n';

    return 0;
}