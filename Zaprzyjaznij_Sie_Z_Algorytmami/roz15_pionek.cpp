#include <iostream>
#include <vector>

using namespace std;

int n = 0;
long long wczytana_liczba = 0;
vector<long long> liczby;
vector<long long> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    dp.assign(n,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    dp[0] = liczby[0];
    for (int i = 1; i < n; ++i)
    {
        long long max_dp = -1e9;
        for (int j = 1; j <= 6 && i - j >= 0; ++j)
            max_dp = max(max_dp,dp[i-j]);
        dp[i] = max_dp + liczby[i];
    }

    printf("%lld",dp[n-1]);
    return 0;
}
