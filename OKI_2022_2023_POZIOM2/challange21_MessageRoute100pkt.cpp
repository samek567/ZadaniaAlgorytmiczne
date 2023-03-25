#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 0, m = 0, a = 0, b = 0, odtw = 0;
vector<vector<int>> krawedzie;
queue<int> Q;
vector<int> dp;
vector<int> idx_poprzedniej;
vector<int> droga;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    dp.assign(n+1,-1);
    idx_poprzedniej.assign(n+1,-1);
    krawedzie.assign(n+1,{});
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    Q.push(1);
    dp[1] = 1;
    while(!Q.empty())
    {
        int spr = Q.front();
        Q.pop();
        for (int i = 0; i < krawedzie[spr].size(); ++i)
        {
            int wierz = krawedzie[spr][i];
            if (dp[wierz] == -1)
            {
                dp[wierz] = dp[spr] + 1;
                Q.push(wierz);
                idx_poprzedniej[wierz] = spr;
            }
        }
    }

    if (dp[n] == -1)
    {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    odtw = n;
    while(true)
    {
        droga.push_back(odtw);
        if (idx_poprzedniej[odtw] == -1)
            break;
        odtw = idx_poprzedniej[odtw];
    }

    cout << dp[n] << '\n';
    for (int i = dp[n]-1; i >= 0; --i)
        cout << droga[i] << ' ';

    return 0;
}