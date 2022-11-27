#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n = 0;
string s1, s2;

int main()
{
    /*
    https://github.com/samek567/ZadaniaAlgorytmiczne/blob/main/OKI_2022_2023_ZAWANSOWANE/EDIST.cpp
    ID: 30476906
    */

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int z = 0; z < n; ++z)
    {
        cin >> s1 >> s2;
        vector<vector<int>> dp;

        for (int i = 0; i <= s1.size(); ++i)
        {
            dp.push_back({});
            for (int j = 0; j <= s2.size(); ++j)
            {
                dp[i].push_back(INT_MAX);
            }
        }

        for (int i = 0; i <= s1.size(); ++i)
        {
            for (int j = 0; j <= s2.size(); ++j)
            {
                if (i == 0)
                {
                    dp[i][j] = j;
                }
                else if (j == 0)
                {
                    dp[i][j] = i;
                }
                else if (s1[i-1] == s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                }
            }
        }

        cout << dp[s1.size()][s2.size()] << '\n';
    }

    return 0;
}
