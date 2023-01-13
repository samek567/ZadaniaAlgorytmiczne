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
    if (n == 1)
    {
        printf("%d",liczby[0]);
        return 0;
    }
    else if (n == 2)
    {
        printf("%d",max(liczby[0],liczby[1]));
        return 0;
    }
    dp[0] = liczby[0];
    dp[1] = max(liczby[0],liczby[1]);
    for (int i = 2; i < n; ++i)
    {
        dp[i] = max(dp[i-1],dp[i-2] + (ll)liczby[i]);
    }
    printf("%lld",dp[n-1]);
    return 0;
}