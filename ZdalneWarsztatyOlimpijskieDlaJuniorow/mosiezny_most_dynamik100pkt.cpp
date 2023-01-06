#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0;
vector<int> liczby;
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

    if (n == 1)
    {
        printf("%d",liczby[0]);
        return 0;
    }
    else if (n == 2)
    {
        printf("%d",liczby[0] + liczby[1]);
        return 0;
    }
    dp[0] = liczby[0];
    dp[1] = liczby[0] + liczby[1];
    dp[2] = max(dp[1],max((long long)liczby[2] + (long long)liczby[1],(long long)liczby[0] + (long long)liczby[2]));
    for (int i = 3; i < n; ++i)
    {
        dp[i] = max(dp[i-1],liczby[i] + dp[i-2]);
        dp[i] = max(dp[i],liczby[i] + liczby[i-1] + dp[i-3]);
    }
    printf("%lld",dp[n-1]);

    return 0;
}
