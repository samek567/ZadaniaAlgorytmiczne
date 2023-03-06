#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Element_seta
{
    int cena;
    int wierzcholek;
    int maska_bitowa;
    bool operator < (const Element_seta &element_seta) const
    {
        if (cena == element_seta.cena)
        {
            if (wierzcholek == element_seta.wierzcholek)
                return maska_bitowa < element_seta.maska_bitowa;
            return wierzcholek < element_seta.wierzcholek;
        }
        return cena < element_seta.cena;
    }
};

struct Krawedz
{
    int cena;
    int wierzcholek;
    int maska;
};

int n = 0, m = 0, p = 0, k = 0, w = 0, ile = 0, wczytana_liczba = 0, sum = 0, a = 0, b = 0, t = 0;
vector<vector<int>> dp;
set<Element_seta> S;
vector<vector<Krawedz>> krawedzie;
vector<int> kowale;

int main()
{
    // Graf warstwowy, Dijkstra, Maski bitowe
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> p >> k;

    krawedzie.assign(n+1,{});
    dp.assign(n+1,{});
    for (int i = 1; i <= n; ++i)
        dp[i].assign((1 << p), -1);

    kowale.assign(n+1, 0);
    for (int i = 0; i < k; ++i)
    {
        cin >> w >> ile;
        sum = 0;
        while(ile--)
        {
            cin >> wczytana_liczba;
            sum += (1 << (p - wczytana_liczba));
        }
        kowale[w] = (kowale[w] | sum);
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> t >> ile;
        sum = 0;
        while (ile--)
        {
            cin >> wczytana_liczba;
            sum += (1 << (p - wczytana_liczba));
        }
        krawedzie[a].push_back({t, b, sum});
        krawedzie[b].push_back({t, a, sum});
    }

    // Puszczamy Dijkstre.
    S.insert({0,1,kowale[1]});
    dp[1][kowale[1]] = 0;

    while(!S.empty())
    {
        Element_seta spr = *S.begin();
        S.erase(spr);
        if (spr.wierzcholek == n)
        {
            cout << spr.cena << '\n';
            return 0;
        }
        for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
        {
            int wierz = krawedzie[spr.wierzcholek][i].wierzcholek;
            if ((krawedzie[spr.wierzcholek][i].maska & spr.maska_bitowa) == krawedzie[spr.wierzcholek][i].maska)
            {
                if (dp[wierz][spr.maska_bitowa] == -1 or spr.cena + krawedzie[spr.wierzcholek][i].cena < dp[wierz][spr.maska_bitowa])
                {
                    auto it = S.find({dp[wierz][spr.maska_bitowa], wierz, spr.maska_bitowa});
                    if (it != S.end())
                        S.erase(*it);
                    dp[wierz][spr.maska_bitowa] = spr.cena + krawedzie[spr.wierzcholek][i].cena;
                    S.insert({spr.cena + krawedzie[spr.wierzcholek][i].cena, wierz, spr.maska_bitowa});
                }
                int maska_po = (spr.maska_bitowa | kowale[wierz]);
                if (dp[wierz][maska_po] == -1 or spr.cena + krawedzie[spr.wierzcholek][i].cena < dp[wierz][maska_po])
                {
                    auto it = S.find({dp[wierz][maska_po], wierz, maska_po});
                    if (it != S.end())
                        S.erase(*it);
                    dp[wierz][maska_po] = spr.cena + krawedzie[spr.wierzcholek][i].cena;
                    S.insert({spr.cena + krawedzie[spr.wierzcholek][i].cena, wierz, maska_po});
                }
            }
        }
    }

    cout << "-1" << '\n';

    return 0;
}
