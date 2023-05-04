#include <iostream>
#include <vector>

using namespace std;

int n = 0, q = 0, k = 0, a = 0, b = 0, wczytana_liczba = 0, sum = 0;
vector<pair<int,int>> dp;
vector<pair<int,int>> M;

int main()
{
    // O(2^K * K + Q), dynamik z maskami bitowymi. Napelniamy dynamikiem jaki jest min koszt, dla danej maski.
    // jesli i, to jakas maska bitowa, przekonwertowana do int-a,
    // to dp[i] = min(najtanszy warsztat z wejscia o tej samej masce, min(dp z wszystkich masek majacych zapalony o jeden inny
    // niz jest juz zapalony bit))
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> q;

    M.assign((1 << k),{1e9+15,-1});
    dp.assign((1 << k),{1e9+15,-1});

    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        sum = 0;
        for (int j = 0; j < b; ++j)
        {
            cin >> wczytana_liczba;
            sum += (1 << (k - wczytana_liczba));
        }
        if (a < M[sum].first)
            M[sum] = {a,i};
    }

    for (int i = (1 << k) - 1; i >= 0; --i)
    {
        if (M[i].first != 1e9+15)
            dp[i] = M[i];
        sum = i;
        for (int j = (1 << k) / 2; j > 0; j /= 2)
        {
            if (sum >= j) // Zapalony bit
                sum -= j;
            else // Zgaszony bit
            {
                if (dp[i+j].first < dp[i].first)
                    dp[i] = dp[i+j];
                else if (dp[i+j].first == dp[i].first)
                    dp[i].second = min(dp[i].second, dp[i+j].second);
            }
        }
    }

    while (q--)
    {
        cin >> a;
        sum = 0;
        for (int i = 0; i < a; ++i)
        {
            cin >> wczytana_liczba;
            sum += (1 << (k - wczytana_liczba));
        }
        if (dp[sum].first == 1e9+15)
            cout << "NIE" << '\n';
        else
            cout << dp[sum].second + 1 << '\n';
    }

    return 0;
}