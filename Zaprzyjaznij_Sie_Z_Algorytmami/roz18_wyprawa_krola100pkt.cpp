#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Element_kolejki
{
    int wierzcholek;
    int ile_zmian;
    int wartosc;
};

int n = 0, m = 0, k = 0, a = 0, b = 0, INF = 1e9, wyn = INF;
vector<vector<int>> krawedzie;
vector<vector<int>> odwrocone_krawedzie;
vector<vector<int>> dp; // dp[i][j], dojscie do wierzcholka i, wykonujac dokladnie j razy po zmienionej drodze.
queue<Element_kolejki> Q;

int main()
{
    // O(K * (N+M))
    /*
    Technika zwana grafem warstwowym. Tworzymy graf dp[i][j] - dojscie do wierzcholka i, idac dokladnie j razy po zmienionej drodze.
    Puszczamy zwyklego BFS-a. Co ciekawe, jesli zadanie było by takie samo, tylko, że na każdej krawędzi była by waga, to można to zrobić
    tak samo grafem warstwowym, korzystajac z algorytmu Dijkstry zamiast BFS-a.
    Podobne motywy grafu warstwowego wystapily w zadaniach:
    - Morskie opowiesci, 2 etap XX OI
    - Agenci final 7 OI
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    dp.assign(n+1,{});
    for (int i = 1; i <= n; ++i)
        dp[i].assign(k+1,INF);
    krawedzie.assign(n+1,{});
    odwrocone_krawedzie.assign(n+1,{});
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        odwrocone_krawedzie[b].push_back(a);
    }

    dp[1][0] = 0;
    Q.push({1,0,0});

    while(!Q.empty())
    {
        Element_kolejki spr = Q.front();
        Q.pop();

        if (spr.wierzcholek == n)
            break;

        for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
        {
            int wierz = krawedzie[spr.wierzcholek][i];
            if (dp[wierz][spr.ile_zmian] == INF)
            {
                dp[wierz][spr.ile_zmian] = spr.wartosc + 1;
                Q.push({wierz,spr.ile_zmian,spr.wartosc+1});
            }
        }

        if (spr.ile_zmian != k)
        {
            for (int i = 0; i < odwrocone_krawedzie[spr.wierzcholek].size(); ++i)
            {
                int wierz = odwrocone_krawedzie[spr.wierzcholek][i];
                if (dp[wierz][spr.ile_zmian+1] == INF)
                {
                    dp[wierz][spr.ile_zmian+1] = spr.wartosc + 1;
                    Q.push({wierz,spr.ile_zmian+1,spr.wartosc+1});
                }
            }
        }
    }

    for (int i = 0; i <= k; ++i)
        wyn = min(wyn, dp[n][i]);

    cout << wyn << '\n';

    return 0;
}