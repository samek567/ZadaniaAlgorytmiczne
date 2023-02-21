#include <iostream>
#include <vector>
#include <deque>

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
deque<Element_seta> S;
vector<vector<bool>> czy_sprawdzilismy;

int main()
{
    // O(N*M), Dijsktra z deque, korzystajac ze krawedzie maja wagi 0 lub 1.
    // https://forum.pasja-informatyki.pl/579294/zadanie-pasy-ruchu-ilocamp?show=579294#q579294
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        plansza.push_back({});
        dp.push_back({});
        czy_sprawdzilismy.push_back({});
        for (int j = 0; j < m; ++j)
        {
            cin >> wczytana_liczba;
            plansza[i].push_back(wczytana_liczba);
            dp[i].push_back(-1);
            czy_sprawdzilismy[i].push_back(false);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        // Dodajemy wierzcholki startowe na seta.
        if (plansza[i][0] == 0)
        {
            S.push_back({0,i,0});
            dp[i][0] = 0;
        }
    }

    while(!S.empty())
    {
        Element_seta spr = S.front();
        S.pop_front();
        if (czy_sprawdzilismy[spr.y][spr.x] == true)
            continue;
        if (spr.x == m-1)
        {
            cout << spr.wartosc << '\n';
            return 0;
        }
        // Krawedzie o wadze 0.
        if (spr.x + 1 < m)
        {
            if (plansza[spr.y][spr.x+1] == 0)
            {
                if (dp[spr.y][spr.x+1] == -1 || spr.wartosc < dp[spr.y][spr.x+1])
                {
                    dp[spr.y][spr.x+1] = spr.wartosc;
                    S.push_front({spr.wartosc,spr.y,spr.x+1});
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
                    dp[spr.y+1][spr.x] = spr.wartosc + 1;
                    S.push_back({spr.wartosc + 1,spr.y+1,spr.x});
                }
            }
        }
        if (spr.y - 1 >= 0)
        {
            if (plansza[spr.y-1][spr.x] == 0)
            {
                if (dp[spr.y-1][spr.x] == -1 || spr.wartosc + 1 < dp[spr.y-1][spr.x])
                {
                    dp[spr.y-1][spr.x] = spr.wartosc + 1;
                    S.push_back({spr.wartosc + 1,spr.y - 1,spr.x});
                }
            }
        }
    }

    cout << "NIE" << '\n';

    return 0;
}