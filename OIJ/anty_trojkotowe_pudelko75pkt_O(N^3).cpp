#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int n = 0, m = 0, wczytana_liczba = 0;
ll wyn = 0;
vector<int> liczby;

int main()
{
    // O(N^3)
    // Dynamik, dp[i][j] -> ile jest anty trojkatowych pudelek, gdzie najwiekszy bok ma dlugosc i, a drugi najwiekszy dlugosc j.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int stat[m+1] = {0};
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        stat[wczytana_liczba]++;
    }

    for (int i = 1; i <= m; ++i)
    {
        if (stat[i] != 0)
        {
            wyn++;
            for (int j = 0; j < min(stat[i],2); ++j)
                liczby.push_back(i);
        }
    }

    ll dp[m+1][m+1];
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= m; ++j)
            dp[i][j] = 0;

    dp[liczby[1]][liczby[0]] = 1;

    for (int i = 2; i < liczby.size(); ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            int L_I = liczby[i], L_J = liczby[j];
            if (dp[L_I][L_J] == 0)
            {
                ll val = 1;
                for (int k = L_J; k >= 1; --k)
                    if (k <= L_I - L_J)
                        val += dp[L_J][k];
                dp[L_I][L_J] = val;
            }
        }
    }

    for (int i = 1; i <= m; ++i)
        for (int j = i; j >= 1; --j)
            wyn += dp[i][j];

    cout << wyn << '\n';

    return 0;
}
