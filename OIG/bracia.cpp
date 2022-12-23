#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, MAX_wiek = 1e6+5;
vector<int> szereg;
vector<int> bilans_wystapien;
vector<int> idx_pierwszego;
vector<int> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    bilans_wystapien.assign(MAX_wiek,0);
    idx_pierwszego.assign(MAX_wiek,-1);
    for (int i = 0; i < n; ++i)
    {
        cin >> wczytana_liczba;
        szereg.push_back(wczytana_liczba);
        bilans_wystapien[wczytana_liczba]++;
        if (idx_pierwszego[wczytana_liczba] == -1)
            idx_pierwszego[wczytana_liczba] = i;
    }

    dp.assign(n,0);
    bilans_wystapien[szereg[0]]--;
    if (bilans_wystapien[szereg[0]] == 0)
        dp[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        bilans_wystapien[szereg[i]]--;
        dp[i] = dp[i-1];
        if (bilans_wystapien[szereg[i]] == 0)
            dp[i] = max(dp[i],dp[idx_pierwszego[szereg[i]]]+1);
    }

    if (n == 1)
        printf("1");
    else
        printf("%d",dp[n-1]);

    return 0;
}
