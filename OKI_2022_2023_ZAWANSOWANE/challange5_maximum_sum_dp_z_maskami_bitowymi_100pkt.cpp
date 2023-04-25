#include <iostream>
#include <vector>

using namespace std;

int q = 0, n = 0, max_wyn = 0, sum = 0;
bool czy_pasuje = true;
vector<vector<int>> liczby;
vector<int> legalne_maski;
vector<int> sumy_legalne_maski;
vector<int> val;
vector<vector<int>> dp;

int main()
{
    // O(N * legal^2), dp z maskami bitowymi.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--)
    {
        cin >> n;
        liczby.clear();
        liczby.assign(n,{});
        for (int i = 0; i < n; ++i)
            liczby[i].assign(n,-1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> liczby[i][j];

        legalne_maski.clear();
        for (int i = 0; i < (1 << n); ++i)
            if ((i & (i << 1)) == 0)
                legalne_maski.push_back(i);
        dp.clear();
        dp.assign(n,{});
        for (int i = 0; i < n; ++i)
            dp[i].assign(legalne_maski.size(),0);
        max_wyn = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < legalne_maski.size(); ++j)
            {
                sum = 0;
                for (int k = 0; k < n; ++k)
                {
                    auto b = (1 << k) & legalne_maski[j];
                    if (b)
                        sum += liczby[i][k];
                }
                dp[i][j] = sum;
                sum = 0;
                if (i != 0)
                    for (int k = 0; k < legalne_maski.size(); ++k)
                        if ((legalne_maski[j] & legalne_maski[k]) == 0 and (legalne_maski[j] & (legalne_maski[k] >> 1)) == 0 and (legalne_maski[j] & (legalne_maski[k] << 1)) == 0)
                            sum = max(sum, dp[i-1][k]);
                dp[i][j] += sum;
                max_wyn = max(max_wyn, dp[i][j]);
            }
        }
        cout << max_wyn << '\n';
    }
    return 0;
}