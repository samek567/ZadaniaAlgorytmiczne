#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Element_kolejki
{
    int wierzcholek;
    int numer_poprzedniej;
};

int n = 0, m = 0, a = 0, b = 0, wyn = 1e9, nr = 0;
vector<vector<int>> krawedzie;
vector<int> dp;
queue<Element_kolejki> Q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    krawedzie.assign(n+1,{});
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
    {
        dp.assign(n+1,-1);
        dp[i] = 1;
        Q.push({i,-1});

        while(!Q.empty())
        {
            Element_kolejki spr = Q.front();
            Q.pop();
            for (int j = 0; j < krawedzie[spr.wierzcholek].size(); ++j)
            {
                int wierz = krawedzie[spr.wierzcholek][j];
                if (wierz == spr.numer_poprzedniej)
                    continue;
                if (dp[wierz] != -1)
                    wyn = min(wyn, dp[spr.wierzcholek] + dp[wierz] - 1);
                else
                {
                    dp[wierz] = dp[spr.wierzcholek] + 1;
                    Q.push({wierz, spr.wierzcholek});
                }
            }
        }
    }

    if (wyn == 1e9)
        cout << "-1" << '\n';
    else
        cout << wyn << '\n';

    return 0;
}