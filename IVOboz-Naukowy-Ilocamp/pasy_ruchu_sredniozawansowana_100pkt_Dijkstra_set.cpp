#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Element_seta
{
    int wartosc;
    int y;
    int x;
    bool operator < (const Element_seta &element_seta) const
    {
        if (wartosc == element_seta.wartosc)
        {
            if (y == element_seta.y)
                return x < element_seta.x;
            return y < element_seta.y;
        }
        return wartosc < element_seta.wartosc;
    }
};

int n = 0, m = 0, wczytana_liczba = 0;
vector<vector<int>> plansza;
vector<vector<int>> dp;
set<Element_seta> S;

int main()
{
    // O(N*M * lg(N*M))
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        plansza.push_back({});
        dp.push_back({});
        for (int j = 0; j < m; ++j)
        {
            cin >> wczytana_liczba;
            plansza[i].push_back(wczytana_liczba);
            dp[i].push_back(-1);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        // Dodajemy wierzcholki startowe na seta.
        if (plansza[i][0] == 0)
        {
            S.insert({0,i,0});
            dp[i][0] = 0;
        }
    }

    while(!S.empty())
    {
        Element_seta spr = *S.begin();
        if (spr.x == m-1)
        {
            cout << spr.wartosc << '\n';
            return 0;
        }
        S.erase(spr);
        // Krawedzie o wadze 0.
        if (spr.x + 1 < m)
        {
            if (plansza[spr.y][spr.x+1] == 0)
            {
                if (dp[spr.y][spr.x+1] == -1 || spr.wartosc < dp[spr.y][spr.x+1])
                {
                    auto it = S.find({dp[spr.y][spr.x+1],spr.y,spr.x+1});
                    if (it != S.end())
                        S.erase(*it);
                    dp[spr.y][spr.x+1] = spr.wartosc;
                    S.insert({spr.wartosc,spr.y,spr.x+1});
                }
            }
        }
        // Krawedzie o wadze 1
        if (spr.y + 1 < n)
        {
            if (plansza[spr.y+1][spr.x] == 0)
            {
                if (dp[spr.y+1][spr.x] == -1 || spr.wartosc + 1 < dp[spr.y+1][spr.x])
                {
                    auto it = S.find({dp[spr.y+1][spr.x],spr.y+1,spr.x});
                    if (it != S.end())
                        S.erase(*it);
                    dp[spr.y+1][spr.x] = spr.wartosc + 1;
                    S.insert({spr.wartosc + 1,spr.y+1,spr.x});
                }
            }
        }
        if (spr.y - 1 >= 0)
        {
            if (plansza[spr.y-1][spr.x] == 0)
            {
                if (dp[spr.y-1][spr.x] == -1 || spr.wartosc + 1 < dp[spr.y-1][spr.x])
                {
                    auto it = S.find({dp[spr.y-1][spr.x],spr.y-1,spr.x});
                    if (it != S.end())
                        S.erase(*it);
                    dp[spr.y-1][spr.x] = spr.wartosc + 1;
                    S.insert({spr.wartosc + 1,spr.y - 1,spr.x});
                }
            }
        }
    }

    cout << "NIE" << '\n';

    return 0;
}