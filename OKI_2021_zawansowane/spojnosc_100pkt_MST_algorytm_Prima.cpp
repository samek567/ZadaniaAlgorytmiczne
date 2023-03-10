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
    int cena;
    bool operator < (const Element_seta &element_seta) const
    {
        if (cena == element_seta.cena)
            return wierzcholek < element_seta.wierzcholek;
        return cena < element_seta.cena;
    }
};

int n = 0, m = 0, a = 0, b = 0, wyn = 0, ile_w_jednej_spojnej = 0;
vector<vector<Krawedz>> krawedzie;
vector<bool> czy_bylismy;
vector<int> dp;
set<Element_seta> S;

void DFS(int v)
{
    czy_bylismy[v] = true;
    ile_w_jednej_spojnej++;
    for (int i = 0; i < krawedzie[v].size(); ++i)
        if (czy_bylismy[krawedzie[v][i].do_kogo] == false)
            DFS(krawedzie[v][i].do_kogo);
}

int main()
{
    // O((N+M) * lg(N)), MST, algorytm Prima
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    krawedzie.assign(n+1,{});
    czy_bylismy.assign(n+1,false);
    dp.assign(n+1,-1);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back({b,i+1});
        krawedzie[b].push_back({a,i+1});
    }

    DFS(1);
    if (ile_w_jednej_spojnej != n)
    {
        cout << "NIE ISTNIEJE" << '\n';
        return 0;
    }

    S.insert({1,0});
    dp[1] = 0;
    while(!S.empty())
    {
        Element_seta spr = *S.begin();
        wyn = max(wyn,spr.cena);
        S.erase(*S.begin());
        for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
        {
            int wierz = krawedzie[spr.wierzcholek][i].do_kogo;
            if (dp[wierz] == -1 or krawedzie[spr.wierzcholek][i].waga < dp[wierz])
            {
                auto it = S.find({wierz,dp[wierz]});
                if (it != S.end())
                    S.erase(*it);
                dp[wierz] = krawedzie[spr.wierzcholek][i].waga;
                S.insert({wierz,krawedzie[spr.wierzcholek][i].waga});
            }
        }
    }

    cout << wyn << '\n';

    return 0;
}