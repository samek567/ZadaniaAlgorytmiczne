#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, poczatek = 0, koniec = 0, srodek = 0;
vector<vector<int>> plansza;
vector<vector<int>> stat;
vector<vector<int>> dp;

bool czy_pasuje(int x)
{
    stat.clear();
    dp.clear();
    for (int i = 0; i < n; ++i)
    {
        stat.push_back({});
        dp.push_back({});
        for (int j = 0; j < n; ++j)
        {
            if (plansza[i][j] >= x)
                stat[i].push_back(1);
            else
                stat[i].push_back(0);
            dp[i].push_back(0);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 && j == 0)
                dp[i][j] = stat[i][j];
            else if (i == 0)
                dp[i][j] = dp[i][j-1] + stat[i][j];
            else if (j == 0)
                dp[i][j] = dp[i-1][j] + stat[i][j];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + stat[i][j];
        }
    }
    if (dp[n-1][n-1] > (2*n-1) / 2)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        plansza.push_back({});
        for (int j = 0; j < n; ++j)
        {
            cin >> wczytana_liczba;
            plansza[i].push_back(wczytana_liczba);
        }
    }
    poczatek = 0, koniec = 1e9+1;
    while(koniec - poczatek > 1)
    {
        srodek = (poczatek + koniec) / 2;
        if (czy_pasuje(srodek) == true)
            poczatek = srodek;
        else
            koniec = srodek;
    }
    printf("%d",poczatek);

    return 0;
}