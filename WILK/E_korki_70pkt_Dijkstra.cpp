#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Element_kolejki
{
    int wierzcholek;
    int wartosc;
    bool operator < (const Element_kolejki &element_kolejki) const
    {
        if (wartosc == element_kolejki.wartosc)
            return wierzcholek < element_kolejki.wierzcholek;
        return wartosc > element_kolejki.wartosc;
    }
};

struct Krawedz
{
    int wierzcholek;
    int cena;
};

int n = 0, m = 0, q = 0, a = 0, b = 0, t = 0, INF = 1e9+50;
bool czy_istnieje = false;
vector<Krawedz> krawedzie[501];
priority_queue<Element_kolejki> Q;
int dp[501];
int poprzednie_dp[501];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 500; ++i)
        poprzednie_dp[i] = -1;

    cin >> n >> m >> q;

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> t;
        krawedzie[a].push_back({b,t});
    }

    for (int z = 0; z < q; ++z)
    {
        cin >> a >> b >> t;

        dp[a] = t;
        Q = priority_queue<Element_kolejki>();
        Q.push({a,t});
        czy_istnieje = false;
        while(!Q.empty())
        {
            Element_kolejki spr = Q.top();
            Q.pop();
            if (spr.wartosc > dp[spr.wierzcholek])
                continue;
            if (spr.wierzcholek == b)
            {
                czy_istnieje = true;
                cout << spr.wartosc << '\n';
                break;
            }
            for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
            {
                int wierz = krawedzie[spr.wierzcholek][i].wierzcholek, krawedz_val = spr.wartosc + krawedzie[spr.wierzcholek][i].cena + t;
                if (poprzednie_dp[wierz] != z)
                {
                    dp[wierz] = INF;
                    poprzednie_dp[wierz] = z;
                }
                if (krawedz_val < dp[wierz])
                {
                    dp[wierz] = krawedz_val;
                    Q.push({wierz, krawedz_val});
                }
            }
        }
        if (czy_istnieje == false)
            cout << "-1" << '\n';
    }
    return 0;
}