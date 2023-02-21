#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0;
vector<int> liczby;
vector<int> dp;

int main()
{
    // O(N), programowanie dynamiczne 1D.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    dp.push_back(liczby[0]);
    for (int i = 1; i < n; ++i)
    {
        dp.push_back(liczby[i]);
        int maxx = -1e9;
        for (int j = 1; j <= 6; ++j)
        {
            if (i-j < 0)
                break;
            maxx = max(maxx,dp[i-j]);
        }
        dp[i] += maxx;
    }

    cout << dp[n-1] << '\n';

    return 0;
}