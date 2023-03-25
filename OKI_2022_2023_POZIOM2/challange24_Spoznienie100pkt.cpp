#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

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

struct Krawedz
{
    int wierzcholek;
    int cena;
};

int n = 0, m = 0, a = 0, b = 0, a_i = 0, b_i = 0, c_i = 0, min_wyn = -1, INF = 1e9+50;
set<Element_seta> S;
vector<vector<Krawedz>> krawedzie;
vector<int> dp1;
vector<int> dp2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> a >> b;

    dp1.assign(n+1,INF);
    dp2.assign(n+1,INF);
    krawedzie.assign(n+1,{});
    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i >> c_i;
        krawedzie[a_i].push_back({b_i,c_i});
    }

    S.insert({a,0});
    dp1[a] = 0;
    while(!S.empty())
    {
        Element_seta spr = *S.begin();
        S.erase(spr);
        if (spr.wierzcholek == b)
        {
            if (min_wyn == -1)
                min_wyn = spr.wartosc;
            else
            {
                if (min_wyn + 1 == spr.wartosc)
                    cout << "YES" << '\n';
                else
                    cout << "NO" << '\n';
                return 0;
            }
        }
        for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
        {
            int wierz = krawedzie[spr.wierzcholek][i].wierzcholek, krawedz_val = krawedzie[spr.wierzcholek][i].cena;
            if (spr.wartosc + krawedz_val < dp1[wierz])
            {
                if (dp1[wierz] == INF)
                {
                    dp1[wierz] = spr.wartosc + krawedz_val;
                    S.insert({wierz, dp1[wierz]});
                }
                else
                {
                    auto it = S.find({wierz, dp2[wierz]});
                    if (it != S.end())
                        S.erase(*it);
                    dp2[wierz] = dp1[wierz];
                    dp1[wierz] = spr.wartosc + krawedz_val;
                    S.insert({wierz, dp1[wierz]});
                }
            }
            else if (spr.wartosc + krawedz_val < dp2[wierz] and spr.wartosc + krawedz_val != dp1[wierz])
            {
                auto it = S.find({wierz, dp2[wierz]});
                if (it != S.end())
                    S.erase(*it);
                dp2[wierz] = spr.wartosc + krawedz_val;
                S.insert({wierz, dp2[wierz]});
            }
        }
    }

    cout << "NO" << '\n';

    return 0;
}