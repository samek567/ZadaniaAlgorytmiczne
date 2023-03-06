#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 0, m = 0, a = 0, b = 0, maxx = 0;
vector<vector<int>> krawedzie;
vector<vector<int>> odwrocone_krawedzie;
vector<int> ile_wychodzi;
vector<int> dp;
queue<int> Q;

int main()
{
    // O(N + M), dynamik
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    krawedzie.assign(n+1,{});
    odwrocone_krawedzie.assign(n+1,{});
    ile_wychodzi.assign(n+1,0);
    dp.assign(n+1,0);

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        ile_wychodzi[a]++;
        krawedzie[a].push_back(b);
        odwrocone_krawedzie[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
        if (ile_wychodzi[i] == 0)
            Q.push(i);

    while(!Q.empty())
    {
        int spr = Q.front(), max_dp = 0;
        Q.pop();
        for (int i = 0; i < krawedzie[spr].size(); ++i)
            max_dp = max(max_dp, dp[krawedzie[spr][i]]);
        dp[spr] = max_dp + 1;
        for (int i = 0; i < odwrocone_krawedzie[spr].size(); ++i)
        {
            int wierz = odwrocone_krawedzie[spr][i];
            ile_wychodzi[wierz]--;
            if (ile_wychodzi[wierz] == 0)
                Q.push(wierz);
        }
    }

    for (int i = 1; i <= n; ++i)
        maxx = max(maxx,dp[i]);
    cout << maxx - 1 << '\n';

    return 0;
}
