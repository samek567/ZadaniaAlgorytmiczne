#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, wczytana_liczba = 0, t = 0;
vector<vector<int>> plansza;
vector<vector<int>> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        plansza.clear();
        dp.clear();
        cin >> m >> n;
        for (int i = 0; i < n; ++i)
        {
            dp.push_back({});
            plansza.push_back({});
            for (int j = 0; j < m; ++j)
            {
                cin >> wczytana_liczba;
                dp[i].push_back(0);
                plansza[i].push_back(wczytana_liczba);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = plansza[i][j];
                else if (i == 0)
                    dp[i][j] = dp[i][j-1] + plansza[i][j];
                else if (j == 0)
                    dp[i][j] = dp[i-1][j] + plansza[i][j];
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    if (plansza[i][j] == 1)
                        dp[i][j]++;
                }
            }
        }
        printf("%d\n",dp[n-1][m-1]);
    }
    return 0;
}