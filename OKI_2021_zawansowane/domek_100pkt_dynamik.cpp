#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 0, wczytana_liczba1 = 0, wczytana_liczba2 = 0, rozmiar_drzewa = 0;
vector<int> drzewo;
vector<vector<int>> dp;

int main()
{
    // O(2^N * K), mamy 2^N - 1 wierzcholkow i z kazdego bierzemy petla dp.
    // Programowanie dynamiczne, dp[i][j] max wyn w drzewie ukorzenionym w wierezcholku i biorac co najwiecej j wierzcholkow.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    k /= 2;
    rozmiar_drzewa = (1 << n);
    for (int i = 0; i < rozmiar_drzewa; ++i)
    {
        dp.push_back({});
        for (int j = 0; j <= k; ++j)
            dp[i].push_back(0);
    }
    drzewo.push_back(0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < (1 << (i - 1)); ++j)
        {
            cin >> wczytana_liczba1 >> wczytana_liczba2;
            drzewo.push_back(wczytana_liczba1 + wczytana_liczba2);
        }
    }

    for (int i = rozmiar_drzewa / 2; i < rozmiar_drzewa; ++i)
    {
        for (int j = 1; j <= k; ++j)
            dp[i][j] = max(0,drzewo[i]);
    }

    for (int i = rozmiar_drzewa / 2 - 1; i >= 1; --i)
    {
        for (int j = 1; j <= k; ++j)
        {
            dp[i][j] = drzewo[i];
            int max_sum = -1e9-5;
            for (int f = 0; f <= j-1; ++f)
                max_sum = max(max_sum,dp[i*2][f] + dp[i*2+1][j - f - 1]);
            dp[i][j] += max_sum;
            dp[i][j] = max(dp[i][j],drzewo[i]);
            dp[i][j] = max(dp[i][j],dp[i][j-1]);
        }
    }

    cout << dp[1][k] << '\n';

    return 0;
}