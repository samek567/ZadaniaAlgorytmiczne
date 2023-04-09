#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 0, q = 0, z_i = 0, wczytana_liczba = 0, wczytany_wierzcholek = 0, wczytany_koszt = 0, wyn = 0, maxx = 0;
vector<vector<int>> krawedzie;
vector<vector<int>> odwrocone_krawedzie;
vector<int> koszty;
vector<int> porzadek_topologiczny;
queue<int> Q;
vector<int> ile_wchodzi;
vector<int> dp;
vector<int> ile;

int main()
{
    // O(N+M), gdzie M to liczba krawedzi.
    // Sortowanie topologiczne i dynamik na dag-u.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    krawedzie.assign(n+1,{});
    odwrocone_krawedzie.assign(n+1,{});
    ile_wchodzi.assign(n+1,0);
    koszty.assign(n+1,-1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> koszty[i] >> z_i;
        ile_wchodzi[i] = z_i;
        for (int j = 0; j < z_i; ++j)
        {
            cin >> wczytana_liczba;
            krawedzie[wczytana_liczba].push_back(i);
            odwrocone_krawedzie[i].push_back(wczytana_liczba);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (ile_wchodzi[i] == 0)
        {
            Q.push(i);
            porzadek_topologiczny.push_back(i);
        }
    }

    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        for (int i = 0; i < krawedzie[v].size(); ++i)
        {
            int wierz = krawedzie[v][i];
            ile_wchodzi[wierz]--;
            if (ile_wchodzi[wierz] == 0)
            {
                Q.push(wierz);
                porzadek_topologiczny.push_back(wierz);
            }
        }
    }

    if (porzadek_topologiczny.size() < n) // odpowiedz nie, gdy graf nie jest dag-iem (w wyniku sortowania topologicznego nie beda wszystkie wierzcholki w porzadku topologicznym)
    {
        cout << "CYKL" << '\n';
        return 0;
    }

    dp.assign(n+1,0);
    for (int i = 0; i < n; ++i)
    {
        int v = porzadek_topologiczny[i], maxx = 0;
        for (int i = 0; i < odwrocone_krawedzie[v].size(); ++i)
            maxx = max(maxx, dp[odwrocone_krawedzie[v][i]]);
        dp[v] = koszty[v] + maxx;

    }

    maxx = 0;
    for (int i = 1; i <= n; ++i)
        maxx = max(maxx, dp[i]);
    cout << maxx << '\n';

    ile.assign(n+1,1e9);
    for (int z = n-1; z >= 0; --z)
    {
        int v = porzadek_topologiczny[z];
        if (krawedzie[v].size() == 0)
            ile[v] = maxx - dp[v] + 1;
        int max_dp = 0;
        for (int i = 0; i < odwrocone_krawedzie[v].size(); ++i)
            max_dp = max(max_dp,dp[odwrocone_krawedzie[v][i]]);
        for (int i = 0; i < odwrocone_krawedzie[v].size(); ++i)
        {
            int wierz = odwrocone_krawedzie[v][i];
            ile[wierz] = min(ile[wierz], ile[v] + (max_dp - dp[wierz]));
        }
    }

    cin >> q;
    while(q--)
    {
        cin >> wczytany_wierzcholek >> wczytany_koszt;
        if (wczytany_koszt >= ile[wczytany_wierzcholek])
            cout << "TAK" << '\n';
        else
            cout << "NIE" << '\n';
    }

    return 0;
}
