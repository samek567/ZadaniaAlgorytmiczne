#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Element_kolejki
{
    int wierzcholek;
    int cena;
};

int n = 0, m = 0, w = 0, k = 0, s = 0, a_i = 0, b_i = 0;
vector<vector<int>> krawedzie;
vector<vector<bool>> dp;
vector<vector<Element_kolejki>> idx_poprzedniej;
vector<int> koszty;
queue<Element_kolejki> Q;
vector<int> droga;

int main()
{
    // Graf warstwowy, BFS, dp[i][j] - czy da sie dojsc do wierzcholka i, suma j.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> w >> k >> s;

    koszty.assign(n+1,0);
    for (int i = 1; i <= n; ++i)
        cin >> koszty[i];

    krawedzie.assign(n+1,{});
    dp.assign(n+1,{});
    idx_poprzedniej.assign(n+1,{});
    for (int i = 1; i <= n; ++i)
    {
        dp[i].assign(s+1,false);
        idx_poprzedniej[i].assign(s+1,{-1,-1});
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> a_i >> b_i;
        krawedzie[a_i].push_back(b_i);
        krawedzie[b_i].push_back(a_i);
    }

    dp[w][koszty[w]] = true;
    Q.push({w,koszty[w]});

    while(!Q.empty())
    {
        Element_kolejki spr = Q.front();
        Q.pop();
        if (spr.wierzcholek == k and spr.cena == s)
        {
            Element_kolejki odtw = {k,s};
            while(true)
            {
                droga.push_back(odtw.wierzcholek);
                if (idx_poprzedniej[odtw.wierzcholek][odtw.cena].wierzcholek == -1 or (spr.wierzcholek == w and spr.cena == 0))
                    break;
                odtw = idx_poprzedniej[odtw.wierzcholek][odtw.cena];
            }
            for (int i = droga.size()-1; i >= 0; --i)
                cout << droga[i] << ' ';
            return 0;
        }
        for (int i = 0; i < krawedzie[spr.wierzcholek].size(); ++i)
        {
            int wierz = krawedzie[spr.wierzcholek][i];
            if (spr.cena + koszty[wierz] <= s)
            {
                if (dp[wierz][spr.cena + koszty[wierz]] == false)
                {
                    dp[wierz][spr.cena + koszty[wierz]] = true;
                    idx_poprzedniej[wierz][spr.cena + koszty[wierz]] = {spr.wierzcholek, spr.cena};
                    Q.push({wierz, spr.cena + koszty[wierz]});
                }
            }
        }
    }

    return 0;
}