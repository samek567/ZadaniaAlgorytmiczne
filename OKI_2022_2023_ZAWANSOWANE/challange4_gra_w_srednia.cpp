#include <iostream>
#include <vector>
using namespace std;

int n = 0;
double wczytana_liczba;
vector<vector<double>> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        dp.push_back({});
        for (int j = 0; j < n; ++j)
        {
            dp[i].push_back(-1);
        }
    }

    // Inicjalizacja dynamika.
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        dp[i][i] = wczytana_liczba;
    }

    for (int i = 2; i <= n; ++i) // Dlugosc sprawdzania.
    {
        for (int j = 0; j <= n - i; ++j)
        {
            int p = j;
            int k = j + i - 1;

            for (int f = p; f < k; ++f)
            {
                dp[p][k] = max(dp[p][k],(dp[p][f] + dp[f+1][k]) / 2);
            }
        }
    }

    printf("%lf",dp[0][n-1]);

    return 0;
}
