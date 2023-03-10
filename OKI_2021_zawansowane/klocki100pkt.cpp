#include <iostream>
#include <vector>

using namespace std;

int n = 0, k = 0, s = 0, wczytana_liczba = 0;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> s;
    dp.assign(s+1,1e9);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        for (int i = s; i >= 0; --i)
            if (i + wczytana_liczba <= s && dp[i] != 1e9)
                dp[i+wczytana_liczba] = min(dp[i+wczytana_liczba],dp[i]+1);
    }

    for (int i = s; i >= 0; --i)
    {
        if (dp[i] <= k && dp[i] != 1e9)
        {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}