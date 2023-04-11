#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int n = 0, k = 0, a = 0, b = 0;
ll wyn = 0;
vector<vector<int>> krawedzie;
vector<vector<ll>> dp;
vector<int> parent;

void DFS(int v, int rodzic)
{
    parent[v] = rodzic;
    for (int i = 0; i < krawedzie[v].size(); ++i)
    {
        int wierz = krawedzie[v][i];
        if (wierz != rodzic)
            DFS(wierz,v);
    }
}

int main()
{
    // O(N*K), programowanie dynamiczne na drzewie
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    krawedzie.assign(n+1,{});
    for (int i = 0; i < n-1; ++i)
    {
        cin >> a >> b;
        krawedzie[a].push_back(b);
        krawedzie[b].push_back(a);
    }

    parent.assign(n+1,0);
    DFS(1,0);

    dp.assign(n+1,{});
    for (int i = 1; i <= n; ++i)
        dp[i].assign(k+1,0);

    for (int i = 1; i <= n; ++i)
        dp[i][0] = 1;

    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int f = 0; f < krawedzie[j].size(); ++f)
            {
                int wierz = krawedzie[j][f];
                if (wierz != parent[j])
                    dp[j][i] += dp[wierz][i-1];
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= k / 2; ++j)
        {
            int dl_1 = j, dl_2 = k - j, ile_dzieci = krawedzie[i].size();
            if (i != 1)
                ile_dzieci--;
            if (ile_dzieci == 0)
                continue;
            else if (ile_dzieci == 1)
            {
                if (dl_2 == k)
                    wyn += dp[i][k];
            }
            else if (dl_1 == 0)
                wyn += dp[i][dl_2];
            else
            {
                ll suma = 0;
                for (int f = 0; f < krawedzie[i].size(); ++f)
                {
                    int wierz = krawedzie[i][f];
                    if (wierz == parent[i])
                        continue;
                    suma += dp[wierz][dl_2 - 1];
                }
                ll dod = 0;
                for (int f = 0; f < krawedzie[i].size(); ++f)
                {
                    int wierz = krawedzie[i][f];
                    if (wierz == parent[i])
                        continue;
                    dod += dp[wierz][dl_1-1] * (suma - dp[wierz][dl_2-1]);
                }
                if (dl_1 == dl_2)
                    wyn += dod / 2;
                else
                    wyn += dod;
            }
        }
    }

    cout << wyn << '\n';

    return 0;
}