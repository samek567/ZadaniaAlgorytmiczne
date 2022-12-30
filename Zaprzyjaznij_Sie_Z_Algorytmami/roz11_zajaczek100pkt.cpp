#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, INF = 1e9;
vector<int> kamienie;
vector<int> fib;
vector<int> dp;

int main()
{
    // O(n log n), bo liczb fibonacciego jest co najwyzej logarytm. Rosna wykladniczo.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    dp.assign(n+1,INF);
    for (int i = 0; i <= n; ++i)
    {
        cin >> wczytana_liczba;
        kamienie.push_back(wczytana_liczba);
    }

    fib.push_back(1);
    fib.push_back(2);
    while(true)
    {
        if (fib[fib.size()-1] + fib[fib.size()-2] > n)
            break;
        fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
    }

    if (kamienie[0] == 1)
    {
        printf("-1");
        return 0;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (kamienie[i] == 0)
        {
            int min_dp = INF;
            for (int j = 0; j < fib.size(); ++j)
            {
                if (i - fib[j] >= 0)
                    min_dp = min(min_dp,dp[i-fib[j]]);
            }
            if (min_dp != INF)
                dp[i] = min_dp + 1;
        }
    }

    if (dp[n] == INF)
        printf("-1");
    else
        printf("%d",dp[n]);

    return 0;
}
