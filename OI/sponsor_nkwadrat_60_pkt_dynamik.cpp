#include <iostream>
#include <vector>

using namespace std;

int n = 0, max_wyn = 0;
double wczytana_liczba = 0;
vector<double> liczby;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        dp.push_back(-1);
        liczby.push_back(wczytana_liczba);
    }

    dp[0] = 1;

    for (int i = 1; i < n; ++i)
    {
        int max_dp = 0;
        for (int j = i-1; j >= 0; --j)
        {
            if (liczby[j] > liczby[i])
            {
                max_dp = max(max_dp,dp[j]);
            }
        }
        dp[i] = max_dp+1;
    }

    for (int i = 0; i < n; ++i)
    {
        max_wyn = max(max_wyn,dp[i]);
    }

    printf("%d00",max_wyn);

    return 0;
}
