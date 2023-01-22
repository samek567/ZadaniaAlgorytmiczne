#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Element_seta
{
    int y;
    int x;
    int koszt;
    bool operator < (const Element_seta &element_seta) const
    {
        if (koszt == element_seta.koszt)
        {
            if (y == element_seta.y)
                return x < element_seta.x;
            return y < element_seta.y;
        }
        return koszt < element_seta.koszt;
    }
};

int n = 0, x = 0, z = 0, k = 0, wczytana_liczba = 0;
Element_seta spr = {-1,-1,-1};
vector<vector<int>> dziury;
vector<vector<int>> dp;
vector<vector<int>> wierzcholki;
vector<vector<pair<int,int>>> krawedzie_lewo; // Wartosc, waga
vector<vector<int>> krawedzie_gora;
vector<vector<int>> krawedzie_dol;
vector<int> vect;
set<Element_seta> S;

int main()
{
    // O(n log n + z) Puszczamy Dijkstre.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> z;
    dziury.assign(n,{});
    dp.assign(n,{});
    wierzcholki.assign(n,{});
    krawedzie_lewo.assign(n,{});
    krawedzie_gora.assign(n,{});
    krawedzie_dol.assign(n,{});
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        while(k--)
        {
            cin >> wczytana_liczba;
            dziury[i].push_back(wczytana_liczba);
        }
    }

    // Dodajemy wszystkie wierzcholki w grafie
    for (int i = 0; i < n; ++i)
    {
        wierzcholki[i].push_back(1);
        if (x != 1)
            wierzcholki[i].push_back(x);
        for (int j = 0; j < dziury[i].size(); ++j)
        {
            if (dziury[i][j] - 1 != 1)
                wierzcholki[i].push_back(dziury[i][j]-1);
            if (dziury[i][j] + 1 != x)
                wierzcholki[i].push_back(dziury[i][j]+1);
        }
    }
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = 0; j < dziury[i].size(); ++j)
            wierzcholki[i+1].push_back(dziury[i][j]);
    }
    for (int i = 0; i < n; ++i)
    {
        sort(wierzcholki[i].begin(),wierzcholki[i].end());
        vect.clear();
        if (!wierzcholki[i].empty())
        {
            vect.push_back(wierzcholki[i][0]);
            for (int j = 1; j < wierzcholki[i].size(); ++j)
                if (wierzcholki[i][j] != wierzcholki[i][j-1])
                    vect.push_back(wierzcholki[i][j]);
        }
        wierzcholki[i] = vect;
        dp[i].assign(wierzcholki[i].size(),-1);
        krawedzie_lewo[i].assign(wierzcholki[i].size(),{-1,-1});
        krawedzie_gora[i].assign(wierzcholki[i].size(),-1);
        krawedzie_dol[i].assign(wierzcholki[i].size(),-1);
    }

    // Dodajemy krawedzie w grafie
    for (int i = 0; i < n; ++i)
    {
        int wsk = 0;
        for (int j = 1; j < wierzcholki[i].size(); ++j)
        {
            if (wsk == dziury[i].size())
            {
                krawedzie_lewo[i][j] = {j-1,0};
            }
            else
            {
                if (dziury[i][wsk] == wierzcholki[i][j] - 1)
                {
                    krawedzie_lewo[i][j] = {j-1,1};
                    wsk++;
                }
                else
                    krawedzie_lewo[i][j] = {j-1,0};
            }
        }
    }
    for (int i = 0; i < n-1; ++i)
    {
        int wsk = 0, wsk_dol = 0;
        for (int j = 0; j < wierzcholki[i].size(); ++j)
        {
            if (wsk == dziury[i].size())
                break;
            if (wierzcholki[i][j] == dziury[i][wsk] - 1)
            {
                while (wsk_dol < wierzcholki[i+1].size())
                {
                    if (wierzcholki[i+1][wsk_dol] == dziury[i][wsk])
                    {
                        krawedzie_gora[i+1][wsk_dol] = j;
                        wsk_dol++;
                        break;
                    }
                    wsk_dol++;
                }
                wsk++;
            }
        }
    }
    for (int i = 0; i < n-1; ++i)
    {
        int wsk = 0, wsk_dol = 0;
        for (int j = 0; j < wierzcholki[i].size(); ++j)
        {
            if (wsk == dziury[i].size())
                break;
            if (wierzcholki[i][j] == dziury[i][wsk] + 1)
            {
                while (wsk_dol < wierzcholki[i+1].size())
                {
                    if (wierzcholki[i+1][wsk_dol] == dziury[i][wsk])
                    {
                        krawedzie_dol[i][j] = wsk_dol;
                        wsk_dol++;
                        break;
                    }
                    wsk_dol++;
                }
                wsk++;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        dp[i][wierzcholki[i].size() - 1] = 0;
        S.insert({i,(int)wierzcholki[i].size() - 1,0});
    }

    while (!S.empty())
    {
        spr = *S.begin();
        S.erase(*S.begin());
        if (spr.x == 0)
        {
            dp[spr.y][0] = spr.koszt;
            continue;
        }

        if (dp[spr.y][krawedzie_lewo[spr.y][spr.x].first] == -1 || spr.koszt + krawedzie_lewo[spr.y][spr.x].second < dp[spr.y][krawedzie_lewo[spr.y][spr.x].first])
        {
            auto it = S.find({spr.y,krawedzie_lewo[spr.y][spr.x].first, dp[spr.y][krawedzie_lewo[spr.y][spr.x].first]});
            if (it != S.end())
                S.erase(*it);
            dp[spr.y][krawedzie_lewo[spr.y][spr.x].first] = spr.koszt + krawedzie_lewo[spr.y][spr.x].second;
            S.insert({spr.y,krawedzie_lewo[spr.y][spr.x].first,  spr.koszt + krawedzie_lewo[spr.y][spr.x].second});
        }
        if (krawedzie_gora[spr.y][spr.x] != -1)
        {
            if (dp[spr.y-1][krawedzie_gora[spr.y][spr.x]] == -1 || spr.koszt < dp[spr.y-1][krawedzie_gora[spr.y][spr.x]])
            {
                auto it = S.find({spr.y-1,krawedzie_gora[spr.y][spr.x], dp[spr.y-1][krawedzie_gora[spr.y][spr.x]]});
                if (it != S.end())
                    S.erase(*it);
                dp[spr.y-1][krawedzie_gora[spr.y][spr.x]] = spr.koszt;
                S.insert({spr.y-1,krawedzie_gora[spr.y][spr.x], spr.koszt});
            }
        }
        if (krawedzie_dol[spr.y][spr.x] != -1)
        {
            if (dp[spr.y+1][krawedzie_dol[spr.y][spr.x]] == -1 || spr.koszt + 1 < dp[spr.y+1][krawedzie_dol[spr.y][spr.x]])
            {
                auto it = S.find({spr.y+1,krawedzie_dol[spr.y][spr.x], dp[spr.y+1][krawedzie_dol[spr.y][spr.x]]});
                if (it != S.end())
                    S.erase(*it);
                dp[spr.y + 1][krawedzie_dol[spr.y][spr.x]] = spr.koszt + 1;
                S.insert({spr.y + 1,krawedzie_dol[spr.y][spr.x], spr.koszt + 1});
            }
        }
    }
    while(z--)
    {
        cin >> wczytana_liczba;
        printf("%d\n",dp[wczytana_liczba-1][0]);
    }

    return 0;
}