#include <iostream>
#include <vector>

using namespace std;

long long n = 0, k = 0, q = 0, d = 0;
vector<long long> sumy_wiersze;
vector<vector<long long>> dp;

int main()
{
    // O(n * k)
    // Programowanie dynamiczne 2d.
    // dp[i][j] liczba ladnych ciagow o dlugosci i konczacych sie na j.
    // Podobny motyw wystapil w zadaniu anty trojkatowe pudelko z finalu 15 OIJ-a.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> q;
    sumy_wiersze.assign(n+1,0);
    for (int i = 0; i <= n; ++i)
    {
        dp.push_back({});
        for (int j = 0; j <= k; ++j)
            dp[i].push_back(0);
    }
    for (int i = 0; i <= k; ++i)
        dp[1][i] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % q;
        for (int j = 1; j < k; ++j)
        {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % q;
        }
        dp[i][k] = (dp[i-1][k] + dp[i-1][k-1]) % q;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
            sumy_wiersze[i] = (sumy_wiersze[i] + dp[i][j]) % q;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> d;
        cout << sumy_wiersze[d] << " ";
    }

    return 0;
}
