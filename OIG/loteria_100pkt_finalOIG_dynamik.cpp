#include <iostream>
#include <vector>

using namespace std;

long long n = 0, k = 0, mod = 1e9+9;
int wczytana_liczba = 0;
vector<int> liczby;
vector<long long> stat;
vector<long long> dp;

int main()
{
    // O(n+k)
    // Programowanie dynamiczne 1d.
    // dp[i] - liczba podciagow od 1 do liczby[i] konczacych sie w idx-ie i.
    // dp[i] = suma po wszystkich dp mniejszych od i, ktore sa rowne liczby[i] - 1. to trzyma tablica stat.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    stat.assign(k+1,0);
    dp.assign(n,0);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        liczby.push_back(wczytana_liczba);
    }

    for (int i = 0; i < n; ++i)
    {
        if (liczby[i] <= k)
        {
            if (liczby[i] == 1)
            {
                dp[i] = 1;
                stat[1] = (stat[1] + 1) % mod;
            }
            else
            {
                dp[i] = stat[liczby[i]-1];
                stat[liczby[i]] = (stat[liczby[i]] + dp[i]) % mod;
            }
        }
    }

    printf("%lld",stat[k]);

    return 0;
}