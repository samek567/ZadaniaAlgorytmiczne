#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0, q = 0, y_1 = 0, x_1 = 0, y_2 = 0, x_2 = 0, wyn = 0;
vector<vector<bool>> plansza;
vector<vector<int>> dp;

int main()
{
    // O(n*m*q)
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 0; i <= n; ++i)
    {
        plansza.push_back({});
        dp.push_back({});
        for (int j = 0; j <= m; ++j)
        {
            plansza[i].push_back(false);
            dp[i].push_back(0);
        }
    }
    while(q--)
    {
        cin >> y_1 >> x_1 >> y_2 >> x_2;
        y_1--;
        x_1--;
        y_2--;
        x_2--;
        wyn = 0;

        for (int i = y_1; i <= y_2; ++i)
            for (int j = x_1; j <= x_2; ++j)
                plansza[i][j] = !plansza[i][j];

        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                if (plansza[i][j] == true)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }

        for (int j = m-1; j >= 0; --j)
        {
            for (int i = n-1; i >= 0; --i)
            {
                dp[i][j] += dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1];
                if (dp[i][j] % 2 == 1)
                {
                    dp[i][j] = dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1] + 1;
                    if (dp[i][j] % 1 == 0)
                        wyn++;
                }
                else
                    dp[i][j] = dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1];
            }
        }
        printf("%d\n",wyn);
    }
    return 0;
}