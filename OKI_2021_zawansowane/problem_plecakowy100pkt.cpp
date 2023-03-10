#include <iostream>
#include <vector>

using namespace std;

int n = 0, W = 0, wczytana_liczba = 0, wyn = 0;
vector<int> masy, wagi, dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> W;
    dp.assign(W+1,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        masy.push_back(wczytana_liczba);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        wagi.push_back(wczytana_liczba);
    }

    for (int i = 0; i < n; ++i)
        for (int j = W; j >= 0; --j)
            if (j + masy[i] <= W)
                dp[j+masy[i]] = max(dp[j+masy[i]], dp[j] + wagi[i]);

    for (int i = W; i >= 0; --i)
        wyn = max(wyn,dp[i]);

    cout << wyn << '\n';

    return 0;
}