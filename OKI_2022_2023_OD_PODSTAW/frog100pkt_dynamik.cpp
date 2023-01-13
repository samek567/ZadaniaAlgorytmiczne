#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, wczytana_liczba = 0;
vector<int> liczby;
vector<ll> dp;

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
    dp[0] = 0;
    dp[1] = abs(liczby[0] - liczby[1]);
    for (int i = 2; i < n; ++i)
        dp[i] = min(dp[i-2] + abs(liczby[i-2] - liczby[i]),dp[i-1] + abs(liczby[i-1] - liczby[i]));
    printf("%lld",dp[n-1]);

    return 0;
}
