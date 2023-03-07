#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Krawedz
{
    int do_kogo;
    int cena;
};

struct Element_seta
{
    int wierzcholek;
    int cena;
    bool operator < (const Element_seta &element_seta) const
    {
        if (cena == element_seta.cena)
            return wierzcholek < element_seta.wierzcholek;
        return cena < element_seta.cena;
    }
};

int n = 0, m = 0, x = 0, y = 0, z = 0, wyn = 0;
vector<vector<Krawedz>> krawedzie;
set<Element_seta> S;
vector<int> dp;
vector<bool> czy_bylismy;

int main()
{
    // Algorytm Prima, do wyznaczania MST.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    czy_bylismy.assign(n+1,false);
    dp.assign(n+1,-1);
    krawedzie.assign(n+1,{});
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> z;
        krawedzie[x].push_back({y,z});
        krawedzie[y].push_back({x,z});
    }

    S.insert({1,0});
    dp[1] = 0;
    czy_bylismy[1] = true;
    while(!S.empty())
    {
        Element_seta spr = *S.begin();
        S.erase(spr);
        czy_bylismy[spr.wierzcholek] = true;
        wyn += spr.cena;
        for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
        {
            int wierz = krawedzie[spr.wierzcholek][i].do_kogo;
            if (czy_bylismy[wierz] == true)
                continue;
            if (dp[wierz] == -1 or krawedzie[spr.wierzcholek][i].cena < dp[wierz])
            {
                auto it = S.find({wierz, dp[wierz]});
                if (it != S.end())
                    S.erase(*it);
                dp[wierz] = krawedzie[spr.wierzcholek][i].cena;
                S.insert({wierz, dp[wierz]});
            }
        }
    }

    cout << wyn;

    return 0;
}