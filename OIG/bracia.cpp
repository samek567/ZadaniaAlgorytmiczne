#include <iostream>
#include <vector>

using namespace std;

int n = 0, wczytana_liczba = 0, MAX_wiek = 1e6+5;
vector<int> szereg_wejsciowy;
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
        szereg_wejsciowy.push_back(wczytana_liczba);
        bilans_wystapien[wczytana_liczba]++;
    }
    for (int i = 0; i < n; ++i)
    {
        if (bilans_wystapien[szereg_wejsciowy[i]] == 1)
        {
            szereg.push_back(szereg_wejsciowy[i]);
            szereg.push_back(szereg_wejsciowy[i]);
            bilans_wystapien[szereg_wejsciowy[i]] = 2;
        }
        else
            szereg.push_back(szereg_wejsciowy[i]);
    }
    for (int i = 0; i < szereg.size(); ++i)
    {
        if (idx_pierwszego[szereg[i]] == -1)
            idx_pierwszego[szereg[i]] = i;
    }

    dp.assign(szereg.size(),0);
    bilans_wystapien[szereg[0]]--;
    for (int i = 1; i < szereg.size(); ++i)
    {
        bilans_wystapien[szereg[i]]--;
        dp[i] = dp[i-1];
        if (bilans_wystapien[szereg[i]] == 0)
            dp[i] = max(dp[i],dp[idx_pierwszego[szereg[i]]]+1);
    }
    printf("%d",dp[szereg.size()-1]);

    return 0;
}
